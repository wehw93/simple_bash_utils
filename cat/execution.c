#include"flags.h"
#include"work_with_file.h"
void execution(flag_cat arg, char * argv[], int argc, size_t quantity_files){
	char * buffer  = calloc(1,sizeof(char));	
	size_t size_file = 0;
	for (int i = argc-quantity_files; i <argc ; i++){
		read_file(argv[i], &buffer,&size_file); 
	}
	int flag_b = 0;
	int flag_s = 0;
	int flag_e = 0;
	int flag_n = 0;
	int flag_t = 0;
	int flag_v = 0;
	for (int i = 0; i < quantity_files; i++){
		if (arg.baza){
			cat_defalut( &buffer, size_file);
		}
		if (arg.cat_s && !flag_s)
		{
			flag_s = 1;
			cat_s(&buffer,&size_file);
		}
		if (arg.cat_b && !flag_b){
			flag_b = 1;
			cat_b( &buffer, &size_file);
		}
		if (arg.cat_e && !flag_e){
			flag_e = 1;
			cat_E(&buffer, &size_file);
		}
		if (arg.cat_n && !flag_n){
			flag_n = 1;
			cat_n(&buffer, &size_file);
		}
		if (arg.cat_t && !flag_t)
		{
			flag_t = 1;
			cat_t(&buffer,&size_file);
		}
		if (arg.cat_v && !flag_v){
			flag_v = 1;
			cat_v(&buffer, &size_file);
		}
	}
	for (int i = 0; i < strlen(buffer);i++){		
		printf("%c", buffer[i]);
	}
	free(buffer);
}
