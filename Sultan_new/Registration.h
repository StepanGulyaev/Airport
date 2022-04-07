#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Passenger.h"

typedef struct Registration
    {
    Passenger* pas;
    struct Registration* next;
    } Registration;

Registration* new_registration();
void add_passenger(Registration*, Passenger*);
void free_registration(Registration*);
void print_reg(Registration*);

#endif