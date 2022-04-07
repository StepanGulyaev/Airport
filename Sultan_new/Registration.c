#include "Registration.h"
#include "stdio.h"
#include "stdlib.h"

Registration* new_registration()
    {
    return (Registration*)calloc(1,sizeof(Registration));
    }

void add_passenger(Registration* reg, Passenger* new_one)
    {
    reg->pas = new_one;
    }

void free_registration(Registration* reg)
    {
    free_passenger(reg->pas);
    free(reg);
    }
