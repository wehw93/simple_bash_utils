#define _GNU_SOURCE
#define MAX_LEN 1000
#include "options.h"
void grep_default(char *buffer[], size_t *size_file, char word[], int flag_i,
                  int flag_v, int *count_res, int grep_n) {
  if (!flag_v) {
    grep_def_without_v(buffer, size_file, word, flag_i, count_res, grep_n);
  } else {
    grep_def_with_v(buffer, size_file, word, flag_i, count_res, grep_n);
  }
}
void grep_def_without_v(char *buffer[], size_t *size_file, char word[],
                        int flag_i, int *count_res, int grep_n) {
  char *buf = calloc(*size_file, sizeof(char));
  char *temp = calloc(*size_file, sizeof(char));
  int indexForTemp = 0;
  int indexForBuf = 0;
  int line = 0;

  for (size_t i = 0; i < *size_file; i++) {
    line++;
    while ((*buffer)[i] != '\n') {
      temp[indexForTemp++] = (*buffer)[i];
      i++;
    }
    if (flag_i) {
      if (strcasestr(temp, word) != NULL) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:%s\n", line, temp);
          (*count_res)++;
        } else {
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
        }
      }
    } else {
      if (strstr(temp, word) != NULL) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:%s\n", line, temp);
          (*count_res)++;
        } else {
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
        }
      }
    }
    memset(temp, 0, sizeof(char) * indexForTemp);
    indexForTemp = 0;
  }

  char *ptr = *buffer;
  *size_file = indexForBuf;
  *buffer = buf;
  free(ptr);
  free(temp);
}
void grep_def_with_v(char *buffer[], size_t *size_file, char word[], int flag_i,
                     int *count_res, int grep_n) {
  char *buf = calloc(*size_file, sizeof(char));
  char *temp = calloc(*size_file, sizeof(char));
  int indexForTemp = 0;
  int indexForBuf = 0;
  int line = 0;
  for (size_t i = 0; i < *size_file; i++) {
    line++;
    while ((*buffer)[i] != '\n') {
      temp[indexForTemp++] = (*buffer)[i];
      i++;
    }
    if (flag_i) {
      if (strcasestr(temp, word) == NULL) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:%s\n", line, temp);
          (*count_res)++;
        } else {
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
        }
      }
    } else {
      if (strstr(temp, word) == NULL) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:%s\n", line, temp);
          (*count_res)++;
        } else {
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
        }
      }
    }
    memset(temp, 0, sizeof(char) * indexForTemp);
    indexForTemp = 0;
  }
  char *ptr = *buffer;
  *size_file = indexForBuf;
  *buffer = buf;
  free(ptr);
  free(temp);
}

void grep_E(char *buffer[], size_t *size_file, char word[][MAX_LEN],
            int count_words, int flag_i, int flag_v, int *count_res,
            int grep_n) {
  if (!flag_v) {
    grep_e_without_v(buffer, size_file, word, count_words, flag_i, count_res,
                     grep_n);
  } else {
    grep_e_with_v(buffer, size_file, word, count_words, flag_i, count_res,
                  grep_n);
  }
}
void grep_e_with_v(char *buffer[], size_t *size_file, char word[][MAX_LEN],
                   int count_words, int flag_i, int *count_res, int grep_n) {
  char *buf = calloc(*size_file * 2, sizeof(char));
  char *temp = calloc(*size_file, sizeof(char));
  int indexForTemp = 0;
  int indexForBuf = 0;
  int line = 0;
  int flag_V = 0;
  for (size_t i = 0; i < *size_file; i++) {
    line++;
    while ((*buffer)[i] != '\n') {
      temp[indexForTemp++] = (*buffer)[i];
      i++;
    }

    if (flag_i) {
      for (int j = 0; j < count_words; j++) {
        if (strcasestr(temp, word[j]) != NULL) {
          flag_V = 1;
        }
      }
      if (!flag_V) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:", line);
        }
        indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
        (*count_res)++;
      }
    } else {
      for (int j = 0; j < count_words; j++) {
        if (strstr(temp, word[j]) != NULL) {
          flag_V = 1;
        }
      }
      if (!flag_V) {
        if (grep_n) {
          indexForBuf += sprintf(buf + indexForBuf, "%d:", line);
        }
        indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
        (*count_res)++;
      }
    }
    flag_V = 0;
    memset(temp, 0, sizeof(char) * indexForTemp);
    indexForTemp = 0;
  }
  char *ptr = *buffer;
  *size_file = indexForBuf;
  *buffer = buf;
  free(ptr);
  free(temp);
}
void grep_e_without_v(char *buffer[], size_t *size_file, char word[][MAX_LEN],
                      int count_words, int flag_i, int *count_res, int grep_n) {
  char *buf = calloc(*size_file * 2, sizeof(char));
  char *temp = calloc(*size_file, sizeof(char));
  int indexForTemp = 0;
  int indexForBuf = 0;
  int line = 0;
  for (size_t i = 0; i < *size_file; i++) {
    line++;

    while ((*buffer)[i] != '\n') {
      temp[indexForTemp++] = (*buffer)[i];
      i++;
    }
    if (flag_i) {
      for (int j = 0; j < count_words; j++) {
        if (strcasestr(temp, word[j]) != NULL) {
          if (grep_n) {
            indexForBuf += sprintf(buf + indexForBuf, "%d:", line);
          }
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
          break;
        }
      }
    } else {
      for (int j = 0; j < count_words; j++) {
        if (strstr(temp, word[j]) != NULL) {
          if (grep_n) {
            indexForBuf += sprintf(buf + indexForBuf, "%d:", line);
          }
          indexForBuf += sprintf(buf + indexForBuf, "%s\n", temp);
          (*count_res)++;
          break;
        }
      }
    }
    memset(temp, 0, sizeof(char) * indexForTemp);
    indexForTemp = 0;
  }
  char *ptr = *buffer;
  *size_file = indexForBuf;
  *buffer = buf;
  free(ptr);
  free(temp);
}
