#include"flagc.h"
#include<getopt.h>
void par_flags(flag_grep * arg, int argc, char * argv[], size_t *count_files){
	int res = 0;
	int flag = 0;
	for (int i = 1; i < argc; i++){
		if (argv[i][0]!= '-'){
			strcpy((arg->word), argv[i]);
			break;
		}
	}
	for (int i = 1; i < argc; i++){
		if (argv[i][0]!= '-' && (strcmp(argv[i], arg->word)!=0))
			(*count_files)++;	
	}
	while((res = getopt_long(argc,argv,"eivcln",NULL, NULL))!=-1){
		
		if (res == 'e'){
			arg->grep_e = 1;		
			flag = 1;
		}
		if (res == 'i'){
			arg->grep_i = 1;		
			flag = 1;
		}
		if (res == 'v'){
			arg->grep_v = 1;		
			flag = 1;
		}
		if (res == 'c'){
			arg->grep_c = 1;		
			flag = 1;
		}
		if (res == 'l'){
			arg->grep_l = 1;		
			flag = 1;
		}
		if (res == 'n'){
			arg->grep_n = 1;		
			flag = 1;
		}
	}
	if (!flag){
		arg->baza = 1;
	}
}
