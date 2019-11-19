#include <stdio.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))


/*fonctionne, trouve la premiere occurence du pattern et s'arrete, renvoie la position de la premiere lettre du pattern, en demarrant a zero

ON pourrait tout simplement recuperer ce 'i' et relancer la fonction find_occurence en demarrant a 'i' au lieu de zero

un peu comme une recurrence
*/
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

int find_occurence(char* text_char,char* pat_char,int* shift_value_table,int length_text,int len,int * s,int* begin_value){
  int count=0;

  for(int i = begin_value[0];i<=length_text-len;i+=s[0]){
    count=0;
    for(int j=len-1;j>=0;j--){
      if(pat_char[j]!=text_char[i+j]){
	printf("%c    %c \n",pat_char[j],text_char[i+j]);
	find_the_corresponding_shift((text_char[i+len-1]),pat_char,shift_value_table,len,s);
	  break;
      }
      count+=1;
    }

    if(count==len){
      printf("reponse  %d \n",i);
      begin_value[0]=i+len;
      break;
    //return 1;//i est l'indice dans le tab
    //}
  
    }
  }
  //if begin_value <= lenght_text - len 
  //find_occurence(blable....,tmp); on peut creer comme ceci une fonction find_all_occurences
  //else return;
}
int find_all_occurence(){//voir au dessus
  
  return 1;
}

//mettre au clair l'idee pour la parallelisation, sur plusieurs coeur en parallele ou bien en sequentielle en coupant le texte de la meme maniere que pour le parallele

int main(){
  
  int* s = malloc(sizeof(int));
  int len = 3;//len of the pattern
  int text_len = 30;//len of the text
  char* pat_char = malloc(sizeof(char)*len);
  char* pat_filename = "pattern.txt";
  char* text_filename = "text.txt";
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
  int begin_value=0;
  find_occurence(text_char,pat_char,shift_value_table,text_len,len,s,&begin_value);}
