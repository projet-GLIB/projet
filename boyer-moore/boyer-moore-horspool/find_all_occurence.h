int find_all_occurence(char* text_char,
		       char* pat_char ,
		       int*  shift_value_table,
		       int   length_text,
		       int   len,
		       int* s,
		       int* begin_value){//a partie de *begin_value

  
  find_occurence(text_char,pat_char,shift_value_table,length_text,len,s,begin_value);
  if(  begin_value[0]  <=  ( length_text - len )  ){

    /*if pattern can be found in the rest of the text then find it*/ find_all_occurence(text_char,pat_char,shift_value_table,length_text,len,s,begin_value);

  }
  else{
    printf("all occurences found..\n");
    return 1;
  }
}
