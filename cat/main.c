#include"flags.h"
int main(int argc, char * argv[]){
	flag_cat  arg = {};
	size_t quantity_flags = 0;
	par_flags(&arg, argc, argv, &quantity_flags);
	execution(arg,argv,argc, quantity_flags);	
	return 0;
}

