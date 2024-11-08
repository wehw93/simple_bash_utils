#include "flags.h"
#include "getopt.h"
void par_flags(flag_cat *arg, int argc, char *argv[], size_t *count_files) {
  const struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                        {"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {0, 0, 0, 'e'},
                                        {0, 0, 0, 't'},
                                        {0, 0, 0, 'v'},
                                        {0, 0, 0, 'T'},
                                        {0, 0, 0, 'E'},
                                        {0, 0, 0, 0}};
  int res = 0;
  int flag = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-')
      (*count_files)++;
  }
  while ((res = getopt_long(argc, argv, "betnsvET", long_options, NULL)) !=
         -1) {
    if (res == 'v') {
      flag = 1;
      arg->cat_v = 1;
    }
    if (res == 'T') {
      flag = 1;
      arg->cat_T = 1;
    }
    if (res == 'E') {
      flag = 1;
      arg->cat_e = 1;
    }
    if (res == 'b') {
      flag = 1;
      arg->cat_b = 1;
    } else if (res == 'e') {
      flag = 1;
      arg->cat_v = 1;
      arg->cat_e = 1;
    } else if (res == 't') {
      flag = 1;
      arg->cat_t = 1;
    } else if (res == 's') {
      flag = 1;
      arg->cat_s = 1;
    } else if (res == 'n') {
      flag = 1;
      arg->cat_n = 1;
    }
  }
  if (flag == 0) {
    arg->baza = 1;
  }
}
