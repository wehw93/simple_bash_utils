#include "flagc.h"
int main(int argc, char *argv[]) {
  flag_grep arg = {};
  size_t quantity_files = 0;
  par_flags(&arg, argc, argv, &quantity_files);
  execution(arg, argv, argc, quantity_files);
  return 0;
}
