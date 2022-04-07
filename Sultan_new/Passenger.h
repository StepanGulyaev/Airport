#ifndef PASSENGER_H
#define PASSENGER_H

typedef struct Passenger 
    {
    char* id;
    int ta;
    int ts;
    } Passenger;

void print_info(Passenger*);
void add_info(Passenger*);
Passenger* new_Passenger();
void free_passenger(Passenger*);

#endif