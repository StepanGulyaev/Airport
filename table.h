#ifndef TABLE_H
#define TABLE_H

#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "queue.h"
#include "limits.h"
#include "table.h"
typedef struct Table{
    size_t n;
    Queue** rows;
}Table;
#ifdef LIST_USE
void push_to_table(Table*,Registration*);
#else
void push_to_table(Table*,Passenger*);
#endif

Table* new_table();
void create_table(Table*, int );
void print_table(Table*);

#endif
