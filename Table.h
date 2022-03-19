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

    #ifdef MAKE_LIST
        List** rows;
    #else
        Vector** rows;
    #endif

    }Table;

Table* new_table();
void create_table(Table*);
void push_to_table(Table*,Registration*);
void print_table(Table*);

#endif