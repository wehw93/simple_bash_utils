#include"options.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cat_n(char* buf[], size_t* size_file, int *count_line) {
  size_t sz = *size_file;
  for (size_t i = 1; i < *size_file; i++){
    if ((*buf)[i - 1] == '\n'){
		  sz += 7;
	  }
  }
  char* buffer = calloc(sz+8, sizeof(char));
  size_t j = 0;
	sz+=7;
  j += sprintf(buffer, "%6d\t%c", *count_line, (*buf)[0]);
     		(*count_line)++; 
  for (size_t i = 1; i < *size_file; i++) {
    if ((*buf)[i - 1] == '\n') {
      j += sprintf(buffer + j, "%6d\t%c", *count_line, (*buf)[i]);
      (*count_line)++;
    } else
      j += sprintf(buffer + j, "%c", (*buf)[i]);
  }
char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;
}

void cat_b(char* buf[], size_t* size_file, int *count_line) {
  size_t sz = *size_file;
  for (size_t i = 1; i < *size_file; i++){
    if ((*buf)[i - 1] == '\n'){
      if ((*buf)[i] != '\n') {
		  sz += 7;
	  }
	}
  }

  char* buffer = calloc(sz+8, sizeof(char));
  size_t j = 0;
	sz+=7;

  j += sprintf(buffer + j, "%6d\t%c", *count_line, (*buf)[0]);
    (*count_line)++; 
  for (size_t i = 1; i < *size_file; i++) {
    if ((*buf)[i - 1] == '\n') {
      if ((*buf)[i] == '\n') {
        j += sprintf(buffer + j, "%c", (*buf)[i]);
      } else {
        j += sprintf(buffer + j, "%6d\t%c", *count_line, (*buf)[i]);
     		(*count_line)++; 
	  }
    } else
      j += sprintf(buffer + j, "%c", (*buf)[i]);
  }
char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;
}

void cat_E(char** buf, size_t* size_file) {
int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n')
      sz += 1;
  }
  char *buffer = calloc(sz + 1, sizeof(char));
  int j = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n') {
      sprintf(buffer + j, "$");
      j++;
    }
    sprintf(buffer + j, "%c", (*buf)[i]);
    j++;
  }
  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;}


void cat_s(char** buf, size_t* size_file) {
int sz = 0;
  int per = 0;
  int j = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n' && per < 2) {
      sz++;
      per++;
    }
    if ((*buf)[i] == '\n' && per > 2) {
      continue;
    }
    if ((*buf)[i] != '\n') {
      per = 0;
      sz++;
    }
  }
  char *buffer = calloc(sz, sizeof(char));
  per = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n' && per < 2) {
      sprintf(buffer + j, "%c", (*buf)[i]);
      j++;
      per++;
    }
    if (per > 2 && (*buf)[i] == '\n') {
      continue;
    }
    if ((*buf)[i] != '\n') {
      sprintf(buffer + j, "%c", (*buf)[i]);
      j++;
      per = 0;
    }
  }

  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;}

void cat_T(char* buf[], size_t* size_file) {
int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\t')
	{
      sz ++;
	}
  }
  char *buffer = calloc(sz, sizeof(char));
  int j = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\t') {
      sprintf(buffer + j, "^");
      j++;
      sprintf(buffer + j, "I");
      j++;
    } else {
      sprintf(buffer + j, "%c", (*buf)[i]);
      j++;
    }
  }

  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;}

void cat_v(char** buf, const size_t* size_file) {
for (size_t i = 0; i < *size_file; i++) {
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] >= 0 &&
        (*buf)[i] < 32 && (*buf)[i] != '\n' && (*buf)[i] != '\t') {
      printf("^%c", ((*buf)[i]) + 64);
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] == 127) {
      printf("^?");
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < 0 &&
        (*buf)[i] >= -96) {
      printf("M-%c", (*buf)[i] + 128);
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < -96) {
      printf("M-%c", ((*buf)[i]) + 192);
      continue;
    }
    printf("%c", (*buf)[i]);
  }}

