#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//find start codon by brute forcing

long int find_start(char* text,long int size_of_text)
{
  char start[3]    = "ATG";
  char codon_start = 52 ;//b'00110100' on se fiche du dernier 00
  //                          A T G A
  for(int i =0;i<size_of_text-1;i++)//faire la derniere case hors du for()
    {
      if( ( ( text[i] ^ codon_start ) >> 2 ) == 0 )
	{
	  printf("found\n");//block i , pos 0
	}
      else if(( ( ( text[i] ^ (codon_start >> 2)  ) << 2 ) >> 2  ) == 0 )
	{
	  printf("found\n"); //block i, pos 1
	}

      
      else
	{
	  text[i] = (text[i] << 4)+(text[i+1] >> 4);
	}

      
       if( ( ( text[i] ^ codon_start ) >> 2 ) == 0 )
	{
	  printf("found\n");//block i, pos 2
	}
       else if(( ( ( text[i] ^ (codon_start >> 2)  ) << 2 ) >> 2  )==0)
	{
	  printf("found\n");//block i,pos 3
	}
    }
  
   if( ( ( text[size_of_text-1] ^ codon_start ) >> 2 ) == 0 )
	{
	  printf("found\n");//block size_of_text, pos 0
	}
   else if(( ( ( text[size_of_text-1] ^ (codon_start >> 2)  ) << 2 ) >> 2  )==0)
	{
	  printf("found\n");//block sizeof_of_text, pos 1
	}
}

int main()
{
  printf("hello world\n");
}
