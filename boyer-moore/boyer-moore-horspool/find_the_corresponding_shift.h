int find_the_corresponding_shift(char character,char* pat_char, int* shift_value_table,int len,int* nb_shift){
  nb_shift[0]=len;
  for(int i=len-2;i>=0;i--){//la derniere case n'est pas utilise
    if(character==pat_char[i]){//pas optimale pour des long patterns
      //s'arrete a la premiere occurence en partant de la fin
      nb_shift[0]=shift_value_table[i];
      break;
    }
   
  }
}
