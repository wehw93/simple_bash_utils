#include"flags.h"
void execution(flag_cat arg, char * argv[]){
	if (arg.baza)
		cat_defalut(argv[1]);
	if (arg.cat_b)
		cat_b(argv[2]);
	if (arg.cat_e)
		cat_E(argv[2]);
	if (arg.cat_n)
		cat_n(argv[2]);
	if (arg.cat_s)
		cat_s(argv[2]);
	if (arg.cat_t)
		cat_t(argv[2]);
}
