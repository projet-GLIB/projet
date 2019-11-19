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












*/
