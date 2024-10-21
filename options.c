#include"options.h"
void cat_n( char * buf[], size_t *size_file){
	int sz = *size_file;				
	for (int i = 0; i <*size_file; i++) {
			if ((*buf)[i]=='\n')
			sz+=8;
		}
		char * buffer = calloc(sz,sizeof(char));
		  int flag=1;
		 size_t j = 0;
		size_t number_line = 1; 
		 for (int i = 0; i < *size_file; i++){
			  if (flag ){
				 sprintf(buffer+j, "%6lu\t", number_line); j+=7; 
				flag=0;
				number_line++;
			  }
			  if ((*buf)[i]=='\n'){
				  flag=1;
			  }
			  sprintf(buffer+j,"%c",(*buf)[i]);
			 
			  j++;
          }   
	 *buf = buffer; 
		*size_file = sz;
}
void cat_b( char * buf[], size_t *size_file){
	int sz = *size_file;
	for (int i = 0; i <*size_file; i++) {
			if ((*buf)[i]=='\n')
			sz+=8;
		}
		char *buffer =calloc(sz,sizeof(char));
		  size_t number_line = 1;
		  int flag=1;
		  int j = 0;
		 for (int i = 0; i < *size_file; i ++) {
			  if (flag && (*buf)[i]!='\n'){
				  sprintf(buffer+j, "%6lu\t",number_line);
				  j+=7;
             number_line++;
				flag=0;
			  }
             
			  if ((*buf)[i]=='\n'){
				  flag=1;
			  }
			  	sprintf(buffer+j, "%c", (*buf)[i]);
				j++;
		  }
		*size_file = sz;
       *buf = buffer; 
}

void  cat_defalut( char **buf, size_t size_file){
		char *buffer = calloc(size_file, sizeof(char));
		  for (int i = 0; i < size_file; i++){
			sprintf(buffer+i, "%c", (*buf)[i]);
          }   
	 *buf = buffer; 
      } 

void cat_t( char * buf[], size_t *size_file){
		int sz = *size_file;
		for (int i = 0; i < *size_file; i++){
			if ((*buf)[i]=='\t')
			sz+=2;	
		}
		char * buffer = calloc(sz,sizeof(char));
		int j = 0;
		for (int i = 0; i < *size_file; i++){
			if ((*buf)[i] == '\t'){
				sprintf(buffer+j, "^");
				j++;
				sprintf(buffer+j, "I");
				j++;
			}
			else{ 
				sprintf(buffer+j, "%c", (*buf)[i]);
				j++;
			}
		}	
	
	 *buf = buffer; 
		*size_file = sz;
}
void cat_s( char * buf[], size_t *size_file){
		int sz = 0;
		int per = 0; 
		  int j = 0;
		for (int i = 0; i < *size_file;i++){
		  if ( (*buf)[i]=='\n' && per <2){
					sz++;
					per++;
			} 
			if ( (*buf)[i]=='\n' && per >2){
				continue;
			}
			if ((*buf)[i]!='\n'){
				per = 0;
				sz++;
			}
		}
		char * buffer = calloc(sz,sizeof(char));
		per = 0;
         for (int i = 0; i < *size_file;i++){	
		  if ( (*buf)[i]=='\n' && per <2){
				sprintf(buffer+j, "%c", (*buf)[i]);
				j++;
				per++;
			} 
			if (per>2 && (*buf)[i]=='\n'){
				continue;
			}
			if ((*buf)[i]!='\n'){
				sprintf(buffer+j, "%c", (*buf)[i]);
				j++;
				per = 0;
			}
		  }  

	 *buf = buffer; 
	 *size_file = sz;
}

void cat_E( char * buf[], size_t *size_file){
	int sz = *size_file;
	for (int i = 0; i < *size_file;i++){
		if ((*buf)[i]=='\n')
				sz+=1;
		}
		char * buffer = calloc(sz,sizeof(char));
		int j = 0;
		for (int i = 0; i < *size_file;i++){		  
			if ((*buf)[i]=='\n'){
				  sprintf(buffer+j, "$");
				  j++;
			  }
			  sprintf(buffer+j, "%c", (*buf)[i]);
			  j++;
          }   
	 *buf = buffer; 
	 *size_file = sz;
}
