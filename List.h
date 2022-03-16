#ifndef LIST_H_
#define LIST_H_

#include "stdio.h"
#include "stdlib.h"
#include "Registration.h"

typedef struct List
    {
    Registration* head;
    }List;


List* new_list();
void fill_list(List*);
void push(List*,Registration*);
void print_list(List*);
void free_list(List*);

#endif