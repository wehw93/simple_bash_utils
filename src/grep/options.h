#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<regex.h>
#include"flagc.h"
#define MAX_LEN 1000

void grep_default(char *buffer[], size_t *size_file,regex_t *regex,  char * filenames, int one, flag_grep arg);
