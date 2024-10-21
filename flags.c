#include"flags.h"
#include"getopt.h"
static struct option long_optinons[] = {
	{"number-nonblank", 0,0,'b'},
	{"number",0,0,'n'},
	{"squeeze-blank",0,0,'s'},
	{0,0,0,'e'},
	{
	{0,0,0,0}
};
void par_flags( flag_cat *arg, int argc, char * argv[], size_t *count_flags){
   int res = 0;
	while((res = getopt(argc,argv,"beEtvnsT"))!=-1){
		if (res == 'b'){
			(*count_flags)++;
			arg->cat_b = 1;
		}
		else if(res=='e') {
			(*count_flags)++;
			arg->cat_e = 1;
		}
		else if (res == 't'){
			(*count_flags)++;
			arg->cat_t = 1;
		}
		else if (res == 's'){
			(*count_flags)++;
			arg->cat_s = 1;
		}
		else if (res == 'n'){
			(*count_flags)++;
			arg->cat_n = 1;
		}
		}
		if ((*count_flags) == 0){
	   		arg->baza = 1;	
   		 }
		(*count_flags) = argc-1-(*count_flags);
}
