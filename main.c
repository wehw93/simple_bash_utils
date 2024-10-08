#include"flags.h"
void main(int argc, char * argv[]){
	flag_cat  arg = {0,0,0,0,0,0};
	par_flags(&arg, argc, argv);
	execution(arg,argv);	
}

