#include "../common/work_with_file.h"
#include "flags.h"
void execution(flag_cat arg, char *argv[], int argc, size_t quantity_files) {
  char *buffer = 0;
  size_t size_file = 0;
  int count_b = 1;
  int count_n = 1;
  for (int i = argc - quantity_files; i < argc; i++) {
	  size_file = 0;
    read_file(argv[i], &buffer, &size_file, "cat");
 if (arg.baza) {
    cat_defalut(&buffer, size_file);
  }
  if (arg.cat_s) {
    cat_s(&buffer, &size_file);
  }
  if (arg.cat_b) {
    cat_b(&buffer, &size_file, &count_b);
  }
  if (arg.cat_e) {
    cat_E(&buffer, &size_file);
  }
  if (arg.cat_n) {
    cat_n(&buffer, &size_file, &count_n);
  }
  if (arg.cat_t) {
    cat_t(&buffer, &size_file);
  }
  if (arg.cat_T){
	  cat_T(&buffer,&size_file);
  }
  if (arg.cat_v) {
    cat_v(&buffer, &size_file);
  }
  for (size_t i = 0; i < strlen(buffer); i++) {
    printf("%c", buffer[i]);
  }
  }
  free(buffer);
}
