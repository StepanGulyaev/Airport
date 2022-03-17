#ifndef QUEUE_H
#define QUEUE_H

#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"

//#define MAKE_LIST

#ifdef MAKE_LIST

    typedef struct List
    {
    Registration* head;
    }List;

    List* new_queue();
    void fill_queue(List*);
    void push(List*,Registration*);
    void print_queue(List*);
    void free_queue(List*);

#else

    typedef struct Vector
    {
    Registration** vector;
    size_t len;
    } Vector;

    Vector* new_queue();
    void fill_queue(Vector*);
    void push(Vector*,Registration*);
    void print_queue(Vector*);
    void free_queue(Vector*);

#endif

#endif