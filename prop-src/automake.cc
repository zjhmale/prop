#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include "basics.h"

Bool out_of_date (const char * filename, struct _stat& target)
{
   struct _stat source;
   if (_stat(filename, &source))
   {  perror(filename); return true; }
   double d = difftime(source.st_mtime,target.st_mtime);
   return d > 0.0;
}
