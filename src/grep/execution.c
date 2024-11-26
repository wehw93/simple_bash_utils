#include "options.h"
#include "work_with_file.h"
void execution(flag_grep arg, char *argv[], int argc, size_t quantity_files) {
  regex_t *reg_words = calloc(arg.count_words, sizeof(regex_t));
  int flag_for_reg = REG_EXTENDED;
  if (arg.flag_i) {
    flag_for_reg |= REG_ICASE;
  }
  for (size_t i = 0; i < arg.count_words; i++) {
    //	  printf("%s\n", arg.word[i]);
    regcomp(&(reg_words[i]), arg.word[i], flag_for_reg);
  }
  char *buffer = 0;
  size_t size_file = 0;
  if (quantity_files == 1) {
    read_file(argv[argc - quantity_files], &buffer, &size_file, "grep");
    grep_default(&buffer, &size_file, reg_words, argv[argc - quantity_files], 1,
                 arg);
  } else {
    for (size_t i = 0; i < quantity_files; i++) {
      read_file(argv[argc - quantity_files + i], &buffer, &size_file, "grep");
      grep_default(&buffer, &size_file, reg_words,
                   argv[argc - quantity_files + i], 0, arg);
    }
  }
  free(buffer);
  for (size_t i = 0; i < arg.count_words; i++) {
    regfree(&reg_words[i]);
  }
  free(reg_words);
}
