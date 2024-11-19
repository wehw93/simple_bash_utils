#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/work_with_file.h"
typedef struct flag_cat {
  int baza;
  int flag_b;
  int flag_e;
  int flag_E;
  int flag_n;
  int flag_s;
  int flag_T;
  int flag_t;
  int flag_v;
} flag_cat;

void cat_b(char *buf[], size_t *size_file, int *count_b);
void cat_n(char *buffer[], size_t *size_file, int *count_n);
void cat_E(char *buffer[], size_t *size_file);
void cat_T(char *buffer[], size_t *size_file);
void cat_s(char *buffer[], size_t *size_file);
void cat_v(char *buffer[], const size_t *size_file);
