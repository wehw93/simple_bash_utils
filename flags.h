#include"options.h"
typedef struct flag_cat{
	int baza;
	int cat_b;
	int cat_e;
	int cat_n;
	int cat_s;
	int cat_t;
} flag_cat;
void par_flags(flag_cat * arg, int argc, char * argv[]);
void execution(flag_cat arg, char * argv[]);  
