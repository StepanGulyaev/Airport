#ifndef QUEUE_H
#define QUEUE_H


#include <stdio.h>
#include <stdlib.h>
#include "Registration.h"

#define LIST_USE

#ifdef LIST_USE
typedef struct Queue{
        Registration* head;
        Registration* tail;
        size_t len;
}Queue;

void fill_queue(Queue*,size_t);
void remove_f_q(Queue*,Registration*);
void push(Queue*,Registration*);
Registration* peek(Queue*);


#else
typedef struct Queue{
        Passenger* pas;
        int len;
}Queue;

void remove_f_q(Queue*,Passenger*);

#endif

Queue* new_queue();
void create_queue(Queue*);
void pop(Queue*);
void print_queue(Queue*);
void free_queue(Queue*);
#endif

