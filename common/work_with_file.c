#include "work_with_file.h"
void read_file(const char filename[], char *file[], size_t *size_file,
               const char util[]) {
  FILE *fp = fopen(filename, "r");
  if (fp) {
    int i = *size_file;
    fseek(fp, 0L, SEEK_END);
    *size_file += ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    *file = realloc(*file, *size_file * sizeof(char));
    char c[1];
    while ((c[0] = getc(fp)) != EOF) {
      (*file)[i] = c[0];
      i++;
    }
    fclose(fp);
  } else {
    printf("%s: %s: Нет такого файла или каталога\n", util, filename);
  }
}
