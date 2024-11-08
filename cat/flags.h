#include "options.h"
typedef struct flag_cat {
  int baza;
  int cat_b;
  int cat_e;
  int cat_n;
  int cat_s;
  int cat_T;
  int cat_t;
  int cat_v;
} flag_cat;
void par_flags(flag_cat *arg, int argc, char *argv[], size_t *count_flags);
void execution(flag_cat arg, char *argv[], int argc, size_t quantity_files);
