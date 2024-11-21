#include "flags.h"

void par_opts(int argc, char *argv[], int *flag, flag_cat *arg,
              const struct option long_options[]);
void par_flags(flag_cat *arg, int argc, char *argv[], size_t *count_files,
               char ***filenames) {
  const struct option long_options[] = {{"number-nonblank", 0, 0, 'b'},
                                        {"number", 0, 0, 'n'},
                                        {"squeeze-blank", 0, 0, 's'},
                                        {0, 0, 0, 'e'},
                                        {0, 0, 0, 't'},
                                        {0, 0, 0, 'v'},
                                        {0, 0, 0, 'T'},
                                        {0, 0, 0, 'E'},
                                        {0, 0, 0, 0}};
  int flag = 0;
  int j = 0;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') (*count_files)++;
  }
  *filenames = calloc(*count_files, sizeof(char *));

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] != '-') {
      (*filenames)[j] = argv[i];
      j++;
    }
  }
  par_opts(argc, argv, &flag, arg, long_options);
  if (flag == 0) {
    arg->baza = 1;
  }
}
void par_opts(int argc, char *argv[], int *flag, flag_cat *arg,
              const struct option long_options[]) {
  int res = 0;
  while ((res = getopt_long(argc, argv, "betnsvET", long_options, NULL)) !=
         -1) {
    if (res == 'v') {
      (*flag) = 1;
      arg->flag_v = 1;
    }
    if (res == 'T') {
      (*flag) = 1;
      arg->flag_T = 1;
    }
    if (res == 'E') {
      (*flag) = 1;
      arg->flag_T = 1;
    }
    if (res == 'b') {
      (*flag) = 1;
      arg->flag_b = 1;
    } else if (res == 'e') {
      (*flag) = 1;
      arg->flag_e = 1;
    } else if (res == 't') {
      (*flag) = 1;
      arg->flag_t = 1;
    } else if (res == 's') {
      (*flag) = 1;
      arg->flag_s = 1;
    } else if (res == 'n') {
      (*flag) = 1;
      arg->flag_n = 1;
    }
  }
  if (arg->flag_b && arg->flag_n) {
    arg->flag_n = 0;
  }
}
