#include <iostream.h>
#include <AD/generic/generic.h>

Bool trace_enabled = true;

void prop_trace(const char * rule, const char * file_name, int line_number)
{  if (trace_enabled)
   {  cerr << "\"" << file_name << "\", line " << line_number 
           << ": " << rule << "\n" << flush;
   }
}
