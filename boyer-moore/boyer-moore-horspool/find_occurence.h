int find_occurence(char* text_char,char* pat_char,int* shift_value_table,int length_text,int len,int * s,int* begin_value){
  int count=0;
  for(int i = begin_value[0];i<=length_text-len;i+=s[0]){
    count=0;
    for(int j=len-1;j>=0;j--){
      if(pat_char[j]!=text_char[i+j]){
	find_the_corresponding_shift((text_char[i+len-1]),pat_char,shift_value_table,len,s);
begin_value[0]=i+s[0];
	  break;
      }
      count+=1;
	
    }

    if(count==len){
      printf("reponse  %d , so (%d + 1) eme character in the text\n",i,i);
      begin_value[0]=i+len;
      break;
   
    }
	
   
  }
 
}
