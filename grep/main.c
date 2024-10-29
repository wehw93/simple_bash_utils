#include"flagc.h"
void main(int argc, char * argv[]){
	flag_grep arg = {0,0,0,0,0,0,0};	
	size_t quantity_files = 0 ;
	par_flags(&arg, argc, argv, &quantity_files);
	execution(arg, argv, argc, quantity_files);
}
