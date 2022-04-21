#ifndef PASSENGER_H
#define PASSENGER_H


typedef struct Passenger {
    char* id;
    int ta;
    int ts;
} Passenger;

void print_info(Passenger*);
int comp(const Passenger *, const Passenger *);
int add_info(Passenger**, int*, int*);
Passenger* new_passenger();
void free_passenger(Passenger*);

#endif
