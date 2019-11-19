int find_the_corresponding_shift(char character,char* pat_char, int* shift_value_table,int len,int* nb_shift){
  nb_shift[0]=len;
  for(int i=len-2;i>=0;i--){//la derniere case n'est pas utilise
    if(character==pat_char[i]){//pas optimale pour des long patterns
      //il faudra imperativement trouver un moyen de stocker les chars une seule fois chacun en excluant le dernier,ici on stocke tout le pattern et on balaye tout le pattern, il faut changer les deux premieres fonctions
      //apres si le pattern est pas enorme, et que l'on a que a t g c, ça va on blayera jamais tout pat_char et shift_value ne prend pas trop de place
      //s'arrete a la premiere occurence en partant de la fin
      nb_shift[0]=shift_value_table[i];
      break;
    }
   
  }
}
