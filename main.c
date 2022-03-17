#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"

int main()
    {
    #ifdef MAKE_LIST
        List* queue = new_queue();
    #else
        Vector* queue = new_queue();
    #endif

    fill_queue(queue);
    print_queue(queue);
    free_queue(queue);
    }
