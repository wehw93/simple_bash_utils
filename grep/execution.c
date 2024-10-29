#include"flagc.h"
#include"../common/work_with_file.h"
void execution(flag_grep arg, char * argv[], int argc, size_t quantity_files, char *file_names[]){
	char * buffer = calloc(1, sizeof(char));	
	size_t size_file = 0;
	if (quantity_files == 1){
		execute_options(arg, &buffer,&size_file); 
		for (int i = 0; i < size_file; i++){
			printf("%c", buffer[i]);
		}
	}
	else{
		for (int i = 0; i < quantity_files; i++){
			execute_options(arg, &buffer, &size_file);
			for (int j = 0;j < size_file; j++){
				if (j == 0){
					printf("%s", file_names[i]);
				}
				if ( j!=0 &&buffer[j-1] == '\n' ){
					printf("%s", file_names[i]);
				}
				printf("%c", buffer[j]);
			}	
		}
	}
}
void execute_options( flag_grep arg, char *buffer[], size_t *size_file){
		if (arg.baza){
			printf("baza");
		}	
		if (arg.grep_e){
			printf("eee");
		}
		if (arg.grep_i){
			printf("iii");
		}
		if (arg.grep_v){
			printf("vvv");
		}
		if (arg.grep_c){
			printf("ccc");
		}
		if (arg.grep_l){
			printf("lll");
		}
		if (arg.grep_n){
			printf("nnn");
		}
}
