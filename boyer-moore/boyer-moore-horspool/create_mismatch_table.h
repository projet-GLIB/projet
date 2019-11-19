int create_the_mismatch_table(int* shift_value_table,
			      int  len              ){

  for(int i=0;i<len-1;i++){
    shift_value_table[i]=len-i-1;
  }
  shift_value_table[len-1]=len-1;
  //https://www.cs.helsinki.fi/u/tpkarkka/opetus/13s/spa/lecture05.pdf
  //document sur horspool
  //mismatch[]={ t , e , s , t }
  //shiftval[]={ 3 , 2 , 1 , 1 }
  //je veux stocker qque t:1,e:2,s:1
}
