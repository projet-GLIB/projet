#include <stdlib.h>
#include <stdio.h>

int main( int argc, char *argv[] )
{
  
   if( argc == 1 )
     {
       printf("Usage : %s  -i [RAW/FASTA]",argv[0]);
     }
   else if( argc > 2 )
     {
       printf("Too many arguments supplied.\n");
     }
   else
     {
       printf("One argument expected.\n");
     }
}
