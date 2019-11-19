int create_the_mismatch_table(int* shift_value_table,
			      int  len              );



int find_the_corresponding_shift(char  character,
				 char* pat_char ,
				 int*  shift_value_table,
				 int   len,
				 int*  nb_shift);


int find_occurence(char* text_char,
		   char* pat_char ,
		   int*  shift_value_table,
		   int   length_text,
		   int   len,
		   int * s,
		   int*  begin_value);

int find_all_occurence(char* text_char,
		       char* pat_char ,
		       int*  shift_value_table,
		       int   length_text,
		       int   len,
		       int * s,
		       int*  begin_value);

int read_your_packet(FILE* fin, char* text_char,int length_text,int nb_of_packets_u_want);//size of packet > len
//comment decider du decoupage ??
/*
- SOit un pattern de longueur len
- SOit un texte de longueur t_len
- Soit un nombre n specifie par l'utilisateur

Grand 1 : faire un dessin !

WARNING: que faire si on rajoute trop de zeros,parceque t_len est loin d'etre divisble par n ?  On aura beaucoup de zero inutile.
Ensuite, comment decoupé les morceaux et sous morceaux et sous sous morceau etc, pour ameliorer l'efficacite des caches ?
Si le pattern est enorme, comment faire ? Il faut un autre programme ou une autre astuce de decoupage, par exemple, on decoupe et si un proco ne detecte auune erreur erreur , tout va bien et recolle les morceaux des autres procos etc!

POUR L'INSTANT, on part du principe que les patterns à chercher sont toujours tres petit devant la taille du texte ( chercher 100 ou plus caracteres dans un texte de plusieurs milliard de char)
 1]
	 On verifie si t_len est divisible par n 
--Soit on rajoute suffisamment de zeros car ce n'est pas divisible
--Soit on ne fait rien

1]-1) On calcule la taille des paquets  : taille = new_t_len / n

 2] 
	On rajoute les 'len - 1' premiers caracteres du texte, a la fin du texte

 3]
	Le premier bloc contiendra la lecture des : 
[ taille + (len -1 )] premier caractere, ensuite on seek  la position taille +(len-1) puis on en relit autant et ce, jusqu'à ce qu'on ait lu n paquets

4] 
	Ensuite on lance le programme pour chacun des morceaux comme s'il s'agissait du texte complet

INFO: En parallele, chaque programme doit, à la fin de son execution, ecrire ses resultats puis dire qu'il a fini, et s'il n'en a aucun, ecrire qu'il a fini, c'est tout.
La recuperation des resultats se fera en lisant les n fichiers ecrits par le "prog parallele"














*/
