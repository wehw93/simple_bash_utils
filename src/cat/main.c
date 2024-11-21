#include "flags.h"
int main(int argc, char *argv[]) {
  flag_cat flags = {};
  size_t count_files = 0;
  char **filenames = 0;
  size_t files_len = 0;
  par_flags(&flags, argc, argv, &count_files, &filenames);
  execution(flags, filenames, count_files, &files_len);
  free(filenames);
  return 0;
}
