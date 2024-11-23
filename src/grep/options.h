#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "flagc.h"
#define MAX_LEN 1000

void grep_default(char *buffer[], const size_t *size_file, regex_t *regex,
                  const char *filenames, int one, flag_grep arg);
