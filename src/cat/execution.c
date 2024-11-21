#include "../common/work_with_file.h"
#include "flags.h"
void execution(flag_cat arg, char** filenames, size_t files_count,
               size_t* files_len) {
  int count_line = 1;
  char* buf = 0;
  for (size_t i = 0; i < files_count; i++) {
    read_file(filenames[i], &buf, files_len, "cat");
    if (*files_len != 0) {
      if (arg.flag_t) {
        arg.flag_v = 1;
        cat_T(&buf, files_len);
      }
      if (arg.flag_T) {
        cat_T(&buf, files_len);
      }
      if (arg.flag_s) {
        cat_s(&buf, files_len);
      }
      if (arg.flag_b) {
        cat_b(&buf, files_len, &count_line);
      }
      if (arg.flag_e) {
        arg.flag_v = 1;
        cat_E(&buf, files_len);
      }
      if (arg.flag_E) {
        cat_E(&buf, files_len);
      }
      if (arg.flag_n) {
        cat_n(&buf, files_len, &count_line);
      }
      if (arg.flag_v) {
        cat_v(&buf, files_len);
      }
      if (!arg.flag_v) {
        for (size_t j = 0; j < *files_len; j++) {
          printf("%c", buf[j]);
        }
      }
    }
  }
  free(buf);
}
