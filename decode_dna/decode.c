#include <stdlib.h>
#include <stdio.h>

#define A_ascii_code 65
#define T_ascii_code 84
#define G_ascii_code 71
#define C_ascii_code 67
/*

"De-encode" 1 byte et ecrit 4 char

*/


char decompresse(char octet,char* array)
{
  array[0]= ( octet >> 6 ) ;     //extrait les 2 premiers bits
  array[1]= ( octet << 2 ) >> 6 ;//le 3eme et 4eme
  array[2]= ( octet << 4 ) >> 6 ;//le 5eme et 6eme
  array[3]= ( octet << 6 ) >> 6 ;//le 7eme et 8eme
  for(int i =0;i<4;i++)
    { 
      if(array[i]==0) { array[i]=A_ascii_code;continue; }
      if(array[i]==3) { array[i]=T_ascii_code;continue; }
      if(array[i]==1) { array[i]=G_ascii_code;continue; }
      if(array[i]==2) { array[i]=C_ascii_code;continue; } 
    }

}

int main()
{
  char* tab = malloc(sizeof(char)*4);
  char octet=0;
  FILE* fd = fopen("encoded_text.txt","r");
  //fseek(fd,0,SEEK_SET);
  fread(&octet,sizeof(char),1,fd);
  printf("%i\n",octet);
  fclose(fd);
  decompresse(octet,tab);
  printf("%s\n",tab);
    
  
}
