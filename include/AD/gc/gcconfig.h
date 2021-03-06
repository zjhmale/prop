//////////////////////////////////////////////////////////////////////////////
// NOTICE:
//
// ADLib, Prop and their related set of tools and documentation are in the
// public domain.   The author(s) of this software reserve no copyrights on
// the source code and any code generated using the tools.  You are encouraged
// to use ADLib and Prop to develop software, in both academic and commercial
// settings, and are welcomed to incorporate any part of ADLib and Prop into
// your programs.
//
// Although you are under no obligation to do so, we strongly recommend that
// you give away all software developed using our tools.
//
// We also ask that credit be given to us when ADLib and/or Prop are used in
// your programs, and that this notice be preserved intact in all the source
// code.
//
// This software is still under development and we welcome(read crave for)
// any suggestions and help from the users.
//
// Allen Leung (leunga@cs.nyu.edu)
// 1994-1995
//////////////////////////////////////////////////////////////////////////////

#ifndef gc_configuration_h
#define gc_configuration_h

#include <AD/config/config.h>

//////////////////////////////////////////////////////////////////////////////
//  This file is used to customize the garbage collectors.  Please
//  read this through carefully and customize it to suit your platform's
//  needs.
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//  Maximum number of garbage collectors instance.
//  Notice that more than one type of heaps are allowed.
//////////////////////////////////////////////////////////////////////////////
#define GC_MAX_NUMBER_OF_COLLECTORS 256

//////////////////////////////////////////////////////////////////////////////
//  Size of a *logical* page in bytes.  Memory managed by the managers
//  are partitioned into logical pages.  Increasing the page size will
//  decrease the sizes bookkeeping data structures, but may increase retention.
//  Page size *MUST* be a power of two but it doesn't have to match the
//  underlying page size of the VM.
//
//  I think 256 bytes is probably too small while something like 4K
//  is probably too large.
//////////////////////////////////////////////////////////////////////////////
#define GC_PAGE_SIZE 512

//////////////////////////////////////////////////////////////////////////////
//  Should we use blacklisting to decrease the likehood of
//  false root identification?
//
//     The default is yes.
//     We'll allow up to ten percentage of all memory to be blacklisted,
//     or 64K of memory at one time, or 512K total, whichever is lower.
//
//////////////////////////////////////////////////////////////////////////////
#define GC_USE_BLACKLISTING
#define GC_MIN_BLACKLISTED_PAGES       4
#define GC_MAX_BLACKLISTED_PERCENTAGE  10
#define GC_MAX_BLACKLISTED_PAGES       (65536/GC_PAGE_SIZE)
#define GC_MAX_TOTAL_BLACKLISTED_PAGES (512*1024/GC_PAGE_SIZE)

//////////////////////////////////////////////////////////////////////////////
//  Should cross heap pointers be allowed?
//  The default is yes.   If you want to allocate connecting structures
//  in multiple collectable heaps then this is a must.  If you'll only use
//  one collector at a time then you can safely comment this option
//  out.  The code will be a bit faster.
//////////////////////////////////////////////////////////////////////////////
#define GC_HAS_CROSS_HEAP_POINTERS

//////////////////////////////////////////////////////////////////////////////
//  Should we try to keep track of garbage collection time?
//  The default is yes.  This is generally a good idea since you may want
//  to profile the programs during fine-tuning.   The timer code should
//  work on both BSD and System V systems.
//////////////////////////////////////////////////////////////////////////////
#if defined(PROP_HAS_GETRUSAGE) || defined(PROP_HAS_TIMES)
#define GC_USE_TIMER
#endif

//////////////////////////////////////////////////////////////////////////////
//  Debugging flag.  Off for production use.
//////////////////////////////////////////////////////////////////////////////
// #define DEBUG_GC

//////////////////////////////////////////////////////////////////////////////
//  Architecture dependent information follows:
//
//  GC_ALIGNMENT          -- a suitable data alignment in bytes.  This is
//                           8 on most platforms.  All data allocated
//                           are guaranteed to satisfy this constraint.
//                           Notice that while decrease this alignment may
//                           decrease the sizes of objects allocated, it
//                           will also increase the sizes of the internal
//                           bitmaps and the times for roots identification,
//                           as more addresses will become candidates.
//  GC_DATA_START         -- a macro to find the start of static data
//  GC_DATA_END           -- a macro to find the end of the static data
//
//  GC_GET_HEAP_BOTTOM    -- a macro to locate the bottom of the heap
//  GC_GET_HEAP_TOP       -- a macro to locate the top of the heap
//
//  Some assumptions that I've made:
//
//     8 bits in a bytes.
//     32 bit processor.
//     4 byte alignment for pointers.
//     linear address space.
//     the static area is contiguous and not expandable during execution.
//     the heap area is contiguous.
//     the stack area is contiguous(no spaghetti stack please).
//     _setjmp() will properly flush the registers onto the stack.
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
//  Configuration for Linux on x86 architectures.
//  Configuration for Sparc on SUN/OS
//////////////////////////////////////////////////////////////////////////////
#if defined(linux) || (defined(sparc) && ! defined(__SVR4))
#  define GC_ALIGNMENT           8   // use 8-byte alignment for our heap
extern int etext;
extern int end;
#  define GC_DATA_START  (void*)(((unsigned long)(&etext) + 0xfff) & ~0xfff)
#  define GC_DATA_END    (void*)(&end)
#include <stdlib.h>
#include <unistd.h>
//extern "C" void * sbrk(int);
#  define GC_GET_HEAP_BOTTOM sbrk(0)
#  define GC_GET_HEAP_TOP    sbrk(0)
#  define GC_CONFIGURED
#endif

//////////////////////////////////////////////////////////////////////////////
// Configuration for Sparc on Solaris 5.*
//   Paul F. Dietz, 2/26/97
//////////////////////////////////////////////////////////////////////////////
#if defined(sparc) && defined(__SVR4)
#  define GC_ALIGNMENT           8   // use 8-byte alignment for our heap
extern int etext;
extern int end;

//
// The data segment in Solaris Sparc binaries does not start
// on the next page after the text segment.  The first symbol
// in the data segment is apparently _GLOBAL_OFFSET_TABLE.
// So, make the first page be the page containing this symbol.
//  PFD 2/26/97
//
extern int _GLOBAL_OFFSET_TABLE_;
#  define GC_DATA_START  (void*)((unsigned long)(&_GLOBAL_OFFSET_TABLE_)\
                                  & ~0xfff)
#  define GC_DATA_END    (void*)(&end)
#include <stdlib.h>
#include <unistd.h>
extern "C" void * sbrk(int);
#  define GC_GET_HEAP_BOTTOM sbrk(0)
#  define GC_GET_HEAP_TOP    sbrk(0)
#  define GC_CONFIGURED
#endif

#if defined(_MSC_VER)
// will not work for sure
struct GC_ALIGNMENT_TYPE { int a; void * b; double c; };
#define GC_ALIGNMENT sizeof(GC_ALIGNMENT_TYPE)
extern int etext;
extern int end;
#  define GC_DATA_START  (void*)(((unsigned long)(&etext) + 0xfff) & ~0xfff)
#  define GC_DATA_END    (void*)(&end)
#include <stdlib.h>
//#include <unistd.h>
extern "C" void * sbrk(int);
#  define GC_GET_HEAP_BOTTOM sbrk(0)
#  define GC_GET_HEAP_TOP    sbrk(0)
#define GC_CONFIGURED
#endif

//////////////////////////////////////////////////////////////////////////////
//  Default configuration: assume vanilla Unixes.
//  Caution: I don't know if it'll work!!!!
//
//  Please add your own and email any new configurations to
//
//     leunga@cs.nyu.edu
//
//  It'll be much appreciated.
//////////////////////////////////////////////////////////////////////////////
#ifndef GC_CONFIGURED
struct GC_ALIGNMENT_TYPE { int a; void * b; double c; };
#define GC_ALIGNMENT sizeof(GC_ALIGNMENT_TYPE)
extern int etext;
extern int end;
#  define GC_DATA_START  (void*)(((unsigned long)(&etext) + 0xfff) & ~0xfff)
#  define GC_DATA_END    (void*)(&end)
#include <stdlib.h>
#include <unistd.h>
extern "C" void * sbrk(int);
#  define GC_GET_HEAP_BOTTOM sbrk(0)
#  define GC_GET_HEAP_TOP    sbrk(0)
#endif

#endif
