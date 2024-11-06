#include "options.h"
void cat_n(char *buf[], size_t *size_file) {
  int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n')
      sz += 8;
  }
  char *buffer = calloc(sz, sizeof(char));
  int flag = 1;
  size_t j = 0;
  int number_line = 1;
  for (size_t i = 0; i < *size_file; i++) {
    if (flag) {
      sprintf(buffer + j, "%6d\t", number_line);
      j += 7;
      flag = 0;
      number_line++;
    }
    if ((*buf)[i] == '\n') {
      flag = 1;
    }
    sprintf(buffer + j, "%c", (*buf)[i]);

    j++;
  }
  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;
}
void cat_b(char *buf[], size_t *size_file) {
  int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n')
      sz += 8;
  }
  char *buffer = calloc(sz, sizeof(char));
  int number_line = 1;
  int flag = 1;
  int j = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if (flag && (*buf)[i] != '\n') {
      sprintf(buffer + j, "%6d\t", number_line);
      j += 7;
      number_line++;
      flag = 0;
    }

    if ((*buf)[i] == '\n') {
      flag = 1;
    }
    sprintf(buffer + j, "%c", (*buf)[i]);
    j++;
  }
  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;
}

void cat_defalut(char **buf, size_t size_file) {
  char *buffer = calloc(size_file, sizeof(char));
  for (size_t i = 0; i < size_file; i++) {
    sprintf(buffer + i, "%c", (*buf)[i]);
  }
  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
}

void cat_t(char *buf[], size_t *size_file) {
  int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\t')
      sz += 2;
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
  *size_file = sz;
}
void cat_s(char *buf[], size_t *size_file) {
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
  *size_file = sz;
}

void cat_E(char *buf[], size_t *size_file) {
  int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if ((*buf)[i] == '\n')
      sz += 1;
  }
  char *buffer = calloc(sz, sizeof(char));
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
  *size_file = sz;
}
void cat_v(char *buf[], size_t *size_file) {
  int sz = *size_file;
  for (size_t i = 0; i < *size_file; i++) {
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < 32 &&
        (*buf)[i] >= 0) {
      sz += 2;
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] == 127) {
      sz += 2;
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < 0 &&
        (*buf)[i] >= -127) {
      sz += 3;
      continue;
    }
    sz++;
  }
  char *buffer = calloc(sz, sizeof(char));
  int j = 0;
  for (size_t i = 0; i < *size_file; i++) {
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] >= 0 &&
        (*buf)[i] < 32 && (*buf)[i] != '\n' && (*buf)[i] != '\t') {
      sprintf(buffer + j, "^%c", ((*buf)[i]) + 64);
      j += 2;
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] == 127) {
      sprintf(buffer + j, "^?");
      j += 2;
      continue;
    }
    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < 0 &&
        (*buf)[i] >= -96) {
      sprintf(buffer + j, "M-%c", (*buf)[i] + 128);
      j += 3;
      continue;
    }

    if (isprint((unsigned char)(*buf)[i]) == 0 && (*buf)[i] < -96) {
      sprintf(buffer + j, "M-%c", ((*buf)[i]) + 192);
      j += 3;
      continue;
    }
    sprintf(buffer + j, "%c", (*buf)[i]);
    j++;
  }
  char *ptr = *buf;
  *buf = buffer;
  free(ptr);
  *size_file = sz;
}
