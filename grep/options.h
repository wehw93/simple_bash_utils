#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000
void grep_E(char *buffer[], size_t *size_file, char word[][MAX_LEN],
            int count_words, int flag_i, int flag_v, int *count_res,
            int grep_n);
void grep_default(char *buffer[], size_t *size_file, char word[], int flag_i,
                  int flag_v, int *count_res, int grep_n);
