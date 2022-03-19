#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"
#include "Table.h"

void get_info()
    {
    
    }

void algorithm()
    {
    Table* table = new_table();
    create_table(table);
    size_t time = 0;

    #ifdef MAKE_LIST
        List* buffer = new_queue();
        create_queue(buffer);
    #else   
        Vector* buffer = new_queue();
        create_queue(buffer);
    #endif

    while(1)
        {
        Passenger* pas = new_Passenger();
        add_info(pas);

        Registration* reg = new_registration();
        add_passenger(reg,pas);

        push(buffer,reg);
        }
    }

int main()
    {
    }
