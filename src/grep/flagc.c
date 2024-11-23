
#include "flagc.h"

#include <getopt.h>
void par_opts(int argc, char *argv[], flag_grep *arg, int *count_E);
void par_flags(flag_grep *arg, int argc, char *argv[], size_t *count_files) {
  int count_E = 0;
  int indexOfWords = 0;
  int count_flags = 0;
  par_opts(argc, argv, arg, &count_E);
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-' && argv[i][1] != 'e') {
      count_flags++;
    }
  }
  for (int i = 1 + count_flags + count_E; i < 1 + count_flags + count_E * 2;
       i++) {
    strcpy((arg->word[indexOfWords++]), argv[i]);
    arg->count_words++;
  }

  if (!count_E) {
    arg->baza = 1;
    for (int i = 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        strcpy((arg->word[indexOfWords++]), argv[i]);
        arg->count_words++;
        break;
      }
    }
    for (int i = count_flags + 2; i < argc; i++) {
      if (argv[i][0] != '-') {
        (*count_files)++;
      }
    }
  } else {
    for (int i = count_flags + count_E * 2 + 1; i < argc; i++) {
      if (argv[i][0] != '-') {
        (*count_files)++;
      }
    }
  }
}
void par_opts(int argc, char *argv[], flag_grep *arg, int *count_E) {
  int res = 0;
  while ((res = getopt_long(argc, argv, "eivcln", NULL, NULL)) != -1) {
    if (res == 'e') {
      arg->flag_e = 1;
      (*count_E)++;
    }
    if (res == 'i') {
      arg->flag_i = 1;
    }
    if (res == 'v') {
      arg->flag_v = 1;
    }
    if (res == 'c') {
      arg->flag_c = 1;
    }
    if (res == 'l') {
      arg->flag_l = 1;
    }
    if (res == 'n') {
      arg->flag_n = 1;
    }
  }
}
