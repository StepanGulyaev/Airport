#include "Passenger.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>

int comp(const Passenger *i, const Passenger *j){
        return i->ta - j->ta;
}

int add_info(Passenger ** pas, int* size, int *count){
    	//char* buffer = (char*)calloc(0,sizeof(char));
    	//scanf("%s", buffer);
	int i = 0;
	char * buffer = readline("Enter info: ");
	if (buffer != NULL){
		char* temp = strtok(buffer,"/ .,");
		if(temp == NULL){
			return 1;
		}
		*count = atoi(temp); 
	}
	while(i<10){
    		(*pas+i)->id = strtok(NULL,"/ .,");
		if ((*pas+i)->id == NULL){
			break;
		}
		//printf("%s\n", *pas[i].id);
		char* tmp_ta = strtok(NULL,"/ .,");
		if (tmp_ta == NULL){
			return 1;
		}
    		(*pas + i)->ta = atoi(tmp_ta);
		//printf("%d\n", *pas[i].ta);
		char* tmp_ts = strtok(NULL,"/ .,");
		if (tmp_ts == NULL){
                        return 1;
                }
                (*pas + i)->ts = atoi(tmp_ts);
		//printf("%d\n", *pas[i].ts);
		i++;
	}
	*size = i;
	*pas = realloc(*pas, sizeof(Passenger)* (*size));
	printf("work\n");
	qsort(*pas, *size, sizeof(Passenger), (int(*)(const void *, const void *)) comp);
	i = 0;
	while(i<*size){
		printf("%d - %s %d %d\n", i, (*pas + i)->id, (*pas + i)->ta, (*pas + i)->ts);
		i++;
	}
	return 0;
}


void print_info(Passenger* pas){
    	printf("%s/%d/%d ",pas->id,pas->ta,pas->ts);
}

Passenger* new_passenger(){
    	return (Passenger*)calloc(1,sizeof(Passenger));
}

void free_passenger(Passenger* pas){
    	free(pas);
}
