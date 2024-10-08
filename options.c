#include"options.h"
void cat_n(char filename[]){
      FILE * fp = fopen(filename,"r");
      if (fp){
          char c[1];
          int i = 1;
		  int flag=1;
          while ((c[0]=getc(fp))!=EOF){
			  if (flag ){
		  		printf("%d ", i);
			  i++;
				flag=0;
			  }
			  if (strcmp(c,"\n") ==0){
				  flag=1;
			  }
              printf("%s", c);
          }   
      }   
      fclose(fp);
}
void cat_b(char filename[]){
      FILE * fp = fopen(filename,"r");
      if (fp){
          char c[1];
          int i = 1;
		  int flag=1;
          while ((c[0]=getc(fp))!=EOF){
			  if (flag && strcmp(c,"\n")!=0){
		  		printf("%d ", i);
              i++;
				flag=0;
			  }
			  if (strcmp(c,"\n") ==0){
				  flag=1;
			  }
              printf("%s", c);
          }   
      }   
      fclose(fp);
}

void  cat_defalut(char filename[]){
      FILE * fp = fopen(filename,"r");
      if (fp){
          char c;
          while ((c=getc(fp))!=EOF){
              printf("%c", c);
          }   
      }   
      fclose(fp);
}

void cat_t(char filename[]){
	FILE *fp = fopen(filename,"r");
	if (fp){
		char c[1];
		while((c[0]=getc(fp))!=EOF){
			if (strcmp(c,"\t")==0){
					printf("^I");
			}
			else 
				printf("%s", c);
		}	
	}
	fclose(fp);
}
void  cat_s(char filename[]){
      FILE * fp = fopen(filename,"r");
      if (fp){
		  int flag = 0;
		  int flag_line=0;
          char c[1];
          while ((c[0]=getc(fp))!=EOF){
         	if (!flag &&  strcmp(c,"\n")==0){
				flag_line=0;
					printf("%s", c);
					flag=1;	
			} 
			if (flag && !flag_line && strcmp(c, "\n")==0){
				continue;
			}
			if (strcmp(c,"\n")!=0){
				if (!flag_line)
					flag_line=1;
				printf("%s", c);
				flag=0;
			}
		  }   
      }   
      fclose(fp);
}

void cat_E(char filename[]){
      FILE * fp = fopen(filename,"r");
      if (fp){
          char c[1];
          while ((c[0]=getc(fp))!=EOF){
			  if (strcmp(c,"\n")==0){
				  printf("$");
			  }
              printf("%s", c);
          }   
      }   
      fclose(fp);
}
