#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct  flag_grep{
	char word[100][100];
	int count_words;
	int baza;
	int grep_e;
	int grep_i;
	int grep_v;
	int grep_c;
	int grep_l;
	int grep_n;
}flag_grep;
void execute_options( flag_grep arg, char *buffer[], size_t *size_file);
void execution(flag_grep arg, char * argv[], int argc, size_t quantity_files);
void par_flags(flag_grep * arg, int argc, char * argv[], size_t *count_files);
