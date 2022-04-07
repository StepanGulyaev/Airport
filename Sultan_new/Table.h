#ifndef TABLE_H
#define TABLE_H

#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"
#include "limits.h"

typedef struct Table
    {
    
    size_t n;

    #ifdef LIST_USE
        Queue** rows;
    #else
        //Vector** rows;
    #endif

    }Table;

#ifdef LIST_USE
    void push_to_table(Table*,Registration*);
    void move_all(Queue*,Table*,size_t);
#else

#endif

Table* new_table();
void create_table(Table*);
void print_table(Table*);

#endif