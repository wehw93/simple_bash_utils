#include "work_with_file.h"
void read_file(const char filename[], char *buf[], size_t *size_file,
               const char util[]) {
  FILE *fp = fopen(filename, "r");
  size_t len = 0;
  if (fp) {
    fseek(fp, 0L, SEEK_END);
    *size_file = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    if (*size_file != 0) {
      *buf = realloc(*buf, (*size_file+1) * sizeof(char));
    }
	(*buf)[*size_file] = '\0';	
    len = fread(*buf, sizeof(char), *size_file, fp);
    fclose(fp);
  } else {
    printf("%s: %s: Нет такого файла или каталога\n", util, filename);
    *size_file = 0;
  }
  *size_file = len;
}
