#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000
typedef struct flag_grep {
  char word[MAX_LEN][MAX_LEN];
  size_t count_words;
  int baza;
  int flag_e;
  int flag_i;
  int flag_v;
  int flag_c;
  int flag_l;
  int flag_n;
} flag_grep;

void execute_options(flag_grep arg, char *buffer[], size_t *size_file,
                     int *count_res);
void execution(flag_grep arg, char *argv[], int argc, size_t quantity_files);
void par_flags(flag_grep *arg, int argc, char *argv[], size_t *count_files);
void par_opt(flag_grep *arg, int *count_E, int *count_flags, int argc,
             char *argv[]);
