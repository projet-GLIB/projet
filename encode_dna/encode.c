#include <stdlib.h>
#include <stdio.h>

#define A_ascii_code 65
#define T_ascii_code 84
#define G_ascii_code 71
#define C_ascii_code 67
/*

"Encode" 4 chars sur un seul octet,si valeur de char possible : A T G C

*/


char compresse(char* array)
{
  char number = 0;
  for(int i =0 ;i<4;i++)
    {
//effect on perfs if using xor for all cases ?
  if (array[i]=='A')
    {
      array[i] ^= array[i];//=0
    }
    //{array[i] = array[i] - A_ascii_code;}  //b'0000 0000'
  if (array[i]=='T')
    {
      array[i] = 3;
    }//b'0000 0011'
  if (array[i]=='G')
    {
      array[i] = 1;
    }//b'0000 0001'
  if (array[i]=='C')
    {
      array[i] = 2;
    }//b'0000 0010'
  
    }
  
  number = ( (number+array[0]) << 2 );
  number = ( (number+array[1]) << 2 );
  number = ( (number+array[2]) << 2 );
  number = ( (number+array[3])      );
      
  return number;
}

int main()
{
  int size=8;
  char* tab = malloc(sizeof(char)*4);
  for(int i=0;i<size/4;)
    {
      FILE* fd = fopen("text.txt","r");
      fseek(fd,i*4,SEEK_SET);
      fread(tab,sizeof(char),4,fd);
      printf("%s\n",tab);
      fclose(fd);
      char number = compresse(tab);
      i++;
      printf("%i \n",number);
    }
  
}
