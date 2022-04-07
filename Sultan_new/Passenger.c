#include "Passenger.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void add_info(Passenger* pas)
    {
    printf("Enter info: ");
    char* buffer = (char*)calloc(0,sizeof(char));
    scanf("%s", buffer);
    pas->id = strtok(buffer,"/ .,");

    char* tmp_ta = strtok(NULL,"/ .,");
    pas->ta = atoi(tmp_ta); 

    char* tmp_ts = strtok(NULL,"/ .,");
    pas->ts = atoi(tmp_ts);
    }

void print_info(Passenger* pas)
    {
    printf("%s ",pas->id);
    }

Passenger* new_Passenger()
    {
    return (Passenger*)calloc(1,sizeof(Passenger));
    }

void free_passenger(Passenger* pas)
    {
    free(pas);
    }