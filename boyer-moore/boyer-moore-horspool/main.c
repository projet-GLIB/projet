#include <stdio.h>
#include <stdlib.h>
#include "prototype.h"
#include "create_mismatch_table.h"
#include "find_the_corresponding_shift.h"
#include "find_occurence.h"
#include "find_all_occurence.h"



int main(){
  
  int* s = malloc(sizeof(int));//nb_shift
  int len = 3;//len of the pattern
  int text_len = 82462 ;//len of the text
  char* pat_char = malloc(sizeof(char)*len);
  char* pat_filename = "pattern.txt";
  char* text_filename = "brca1.seq.fa";
  int* shift_value_table = malloc(sizeof(int)*len);
  
  FILE* fd = fopen(pat_filename,"r");
 
  fread(pat_char,sizeof(char),len,fd);
  fclose(fd);
  
  shift_value_table=malloc(sizeof(int)*len);
  
  char* text_char=malloc(sizeof(char)*text_len);
 
  FILE* fd2=fopen(text_filename,"r");
  fread(text_char,sizeof(char),text_len,fd2);
  
  fclose(fd2);
  create_the_mismatch_table(shift_value_table,len);
  int* begin_value=malloc(sizeof(int));
  begin_value[0]=0;
  find_all_occurence(text_char,pat_char,shift_value_table,text_len,len,s,begin_value);
//find_occurence(text_char,pat_char,shift_value_table,text_len,len,s,begin_value);
}
