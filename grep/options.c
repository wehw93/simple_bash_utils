#define _GNU_SOURCE
#include"options.h"
void grep_default(char *buffer[], size_t *size_file, char word[], int flag_i, int flag_v){
	int sz = 0;
	char* buf = calloc(*size_file, sizeof(char));
	char* temp = calloc(*size_file, sizeof(char));
	int indexForTemp = 0;
	int indexForBuf = 0;
	if (flag_v){
		for (int i = 0; i < *size_file; i++){
			while  ((*buffer)[i]!='\n'){
				temp[indexForTemp++] = (*buffer)[i];
				i++;
			}
			if (flag_i){
				if (strcasestr(temp,word)==NULL ){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
				}
			}
			else{ 
				if (strstr(temp,word)==NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
				}
			}
			memset(temp, 0, sizeof(char)*indexForTemp);	
			 indexForTemp = 0;
		}
	}
	else{
		for (int i = 0; i < *size_file; i++){
			while  ((*buffer)[i]!='\n'){
				temp[indexForTemp++] = (*buffer)[i];
				i++;
			}
			if (flag_i){
				if (strcasestr(temp,word)!=NULL ){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
				}
			}
			else{ 
				if (strstr(temp,word)!=NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
				}
			}
			memset(temp, 0, sizeof(char)*indexForTemp);	
			 indexForTemp = 0;
		}
	}
	*size_file = indexForBuf;
	*buffer = buf;
}
void grep_E(char *buffer[], size_t *size_file, char word[][100], int count_words, int flag_i, int flag_v){
	int sz = 0;
	char* buf = calloc(*size_file, sizeof(char));
	char* temp = calloc(*size_file, sizeof(char));
	int indexForTemp = 0;
	int indexForBuf = 0;
	for (int i = 0; i < *size_file; i++){
		while  ((*buffer)[i]!='\n'){
			temp[indexForTemp++] = (*buffer)[i];
			i++;
		}
		if (flag_v){
			if (flag_i){
				for (int j = 0; j < count_words; j++){
					if (strcasestr(temp,word[j])==NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
						break;
					}
				}
			}
			else {
				for (int j = 0; j < count_words; j++){
					if (strstr(temp,word[j])==NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
						break;
					}
				}
			}
		}
		else{
			if (flag_i){
				for (int j = 0; j < count_words; j++){
					if (strcasestr(temp,word[j])!=NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
						break;
					}
				}
			}
			else {
				for (int j = 0; j < count_words; j++){
					if (strstr(temp,word[j])!=NULL){
						indexForBuf+=sprintf(buf+indexForBuf, "%s\n",temp);	
						break;
					}
				}
			}
		}
		memset(temp, 0, sizeof(char)*indexForTemp);	
		 indexForTemp = 0;
	}
	*size_file = indexForBuf;
	*buffer = buf;
}
