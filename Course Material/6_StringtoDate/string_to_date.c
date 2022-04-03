#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "string_to_date.h"
#include "unity.h"


error_t string_to_date_converter(char* input_string, my_date_t* result_date){
    if(input_string==NULL||result_date==NULL)
        return NULL_PTR;
        
	int init_size = strlen(input_string);
	char delim[] = "/";

	char *ptr = strtok(input_string, delim);
    int n[3],j=-1;
	while(ptr != NULL)
	{
        j++;
         n[j]=atoi(ptr);
		ptr = strtok(NULL, delim);
        
	}
    
    if(n[0]>0 && n[0]<32 && n[1]>0 && n[1]<13 && n[2]>0){
        result_date->date=n[0];
        result_date->month=n[1];
        result_date->year=n[2];
        return SUCCESS;
    }
    else
    return INCORRECT;
}



