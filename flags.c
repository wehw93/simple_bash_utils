#include"flags.h"
void par_flags( flag_cat *arg, int argc, char * argv[]){
	if (argc==2){
	   		arg->baza = 1;	
      }             
                    
      if (argc==3 && strcmp(argv[1], "-b")==0 ){
		  arg->cat_b = 1;
      }             
      if (argc==3 && strcmp(argv[1], "-E")==0){
		  arg->cat_e = 1;
      }             
      if (argc==3 && strcmp(argv[1], "-n")==0){
		  arg->cat_n = 1;
      }             
      if (argc==3 && strcmp(argv[1], "-s")==0){
		  arg->cat_s = 1;
      }             
      if (argc==3 && strcmp(argv[1], "-T")==0){
		  arg->cat_t = 1;
      }  		
}
