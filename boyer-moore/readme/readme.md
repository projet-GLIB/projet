/*
l'algorithme marche !! Mais ce n'est pas boyer moore c'est boyer moore horspool
(pas urgent)On pourrait aussi implementer Raite, qui est comme BMH, on utilise la bad character rule, mais on effectue deux comparaison avant de vraiment comparer, bref lire la doc de raita...


-> il faut maintenant ameliorer la chaine nommee "shift_value_table"(ou pas, c'est pas tres critique)
-> ameliorer la recuperation des valeurs de "len" et "text_len" en lisant directement dans les fichiers avec un FILE* , fseek(end) ftell
-> penser a comment on parallelise un algo
-> implem raita
-> comparaison avec du bitwise
-> penser aux caches
-> idee d'amelioration: quand le prog a shifte vers la droite de x rang, alors les x premiers termes encore en memoire RAM ne servent plus a rien, on les supprime, ca peut etre utile si on parallelise. Ensuite on lit des octets supplementaire du texte et on recommence. Les processus peuvent s'envoyer la position ou ils ont trouve un pattern, comme ca les autres processus ne chercheront pas à commencer leur recherche a partir de cette position ni apres cette position.Ca ne servirai a rien, il faut qu'il commence avant l'indice renvoyé qui sera le 'i' dans l'algo. CHaque processus doit charger en memoire un nombre n de caracteres, + len-1 caracteres-> faire un dessin pour expliquer ca correctement.
n > len

Bref, prenons le temps, et on pourra trouver un moyen efficace de paralleliser,
et si on a qu'un seul pc, on utilisera le meme moyen pour faire du "parallele" mais un morceau apres l'autre. Ce sera utile par exmple pour trouver un pattern dans le genome humain, lequel ne peut pas etre charge dans seulement 4GB de ram. Et meme si on a plus de ram, c'est plus rapide en parallele.
*/