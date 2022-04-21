#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include "Registration.h"

#ifdef LIST_USE

//typedef struct Registration;

typedef struct Queue{
    	Registration* head;
	Registration* tail;
	size_t len;
}Queue;
void push(Queue*,Registration*);
void remove_f_q(Queue* queue,Registration* to_remove);
//void sort_queue(Queue *, Queue *);
#else
typedef struct Queue{
        Passenger* pas;
	int len;
}Queue;

void push(Queue*,Passenger*);
void remove_f_q(Queue* queue, Passenger* to_remove);
#endif

Queue* new_queue();
void create_queue(Queue*);
void fill_queue(Queue*);
void pop(Queue*);
//void move_all(Queue*,  size_t);
//Registration * peek(Queue*);
//void push(Queue*,Passenger*);
void print_queue(Queue*);
void free_queue(Queue*);

#endif
