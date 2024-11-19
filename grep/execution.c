#include "../common/work_with_file.h"
#include "flagc.h"
#include "options.h"
void execution(flag_grep arg, char *argv[], int argc, size_t quantity_files) {
  char *buffer = 0;
  size_t size_file = 0;
  int count_res = 0;
  if (quantity_files == 1) {
    read_file(argv[argc - quantity_files], &buffer, &size_file, "grep");
    execute_options(arg, &buffer, &size_file, &count_res);
    if (arg.grep_c)
      printf("%d\n", count_res);
    else {
      if (arg.grep_l && size_file != 0) {
        printf("%s\n", argv[argc - 1]);
      } else {
        for (size_t i = 0; i < size_file; i++) {
          printf("%c", buffer[i]);
        }
      }
    }
  } else {
    for (size_t i = 0; i < quantity_files; i++) {
      size_file = 0;
      count_res = 0;
      read_file(argv[argc - quantity_files + i], &buffer, &size_file, "grep");
      execute_options(arg, &buffer, &size_file, &count_res);
      if (arg.grep_c)
        printf("%s:%d\n", argv[argc - quantity_files + i], count_res);
      else {
        if (arg.grep_l && size_file != 0) {
          printf("%s\n", argv[argc - quantity_files + i]);
        } else {
          for (size_t j = 0; j < size_file; j++) {
            if (j == 0) {
              printf("%s:", argv[argc - quantity_files + i]);
            }
            if (j != 0 && buffer[j - 1] == '\n') {
              printf("%s:", argv[argc - quantity_files + i]);
            }
            printf("%c", buffer[j]);
          }
        }
      }
    }
  }
  free(buffer);
}
void execute_options(flag_grep arg, char *buffer[], size_t *size_file,
                     int *count_res) {
  if (arg.baza) {
    grep_default(buffer, size_file, arg.word[0], arg.grep_i, arg.grep_v,
                 count_res, arg.grep_n);
  }
  if (arg.grep_e) {
    grep_E(buffer, size_file, arg.word, arg.count_words, arg.grep_i, arg.grep_v,
           count_res, arg.grep_n);
  }
}
