#include <AD/persist/pstream.h>
#include <fstream.h>
#include <strstream.h>

main()
{  {  ofstream O("testing"); 
      Postream PO(O);
      PO << "this is a test\n";
   }
   ifstream I("testing");
   Pistream PI(I);
   char buf[128];
   PI.read(buf,sizeof(buf));
   cout << "this = " << buf;
   return 0;
}
