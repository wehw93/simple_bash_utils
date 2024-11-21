#define MAX_LEN 1000
#include "options.h"
int func_reg(flag_grep arg, regex_t* regex, char * temp);
void grep_default(char *buffer[], size_t *size_file,regex_t *regex,  char * filenames, int one, flag_grep arg) {
	char *temp = calloc(*size_file, sizeof(char));
	size_t ind_temp = 0;
	int count = 0;
	for (size_t i = 0; i < *size_file; i++){
		while ((*buffer)[i]!='\n' && (*buffer)[i]!='\0'){
				temp[ind_temp++] = (*buffer)[i];
				i++;
		}
		int res=func_reg(arg,regex,temp);
		if (arg.flag_v && res==1){
			res = 0;
		}
		else if (arg.flag_v && res==0){
			res = 1;
		}
		if (res==1){
			count++;
		}
		if (res==1 && !one && !arg.flag_c){
			printf("%s:%s\n", filenames,temp);
		}
		if (res==1 && one && !arg.flag_c){
			printf("%s\n", temp);
		}
		memset(temp,0,sizeof(char)*ind_temp);
		ind_temp = 0;
	}
	if (arg.flag_c && !one){
			printf("%s:%d\n", filenames,count);
	}
	if (arg.flag_c && one){
			printf("%d\n", count);
	}
			

free(temp);	
}
int func_reg(flag_grep arg, regex_t* regex, char * temp)
{
	for (size_t i = 0; i < arg.count_words; i++){
		int res = regexec(&(regex[i]),temp,0,NULL,0);
		if (!res){
			return 1;
		}
	}
	return 0;
}