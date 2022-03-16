#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "List.h"

int main()
    {
    List* queue = new_list();
    fill_list(queue);
    print_list(queue);
    }