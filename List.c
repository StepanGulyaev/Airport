#include "stdio.h"
#include "stdlib.h"
#include "List.h"

List* new_list()
    {
    return (List*)calloc(1,sizeof(List));   
    }

void fill_list(List* queue)
    {
    for (size_t i = 0; i < 3; i++)
        {
        Passenger* pas = new_Passenger();
        add_info(pas);

        Registration* reg = new_registration();
        add_passenger(reg,pas);

        push(queue,reg);
        }
    }

void push(List* queue,Registration* to_push)
    {
    if (queue->head == NULL)
        {
        queue->head = to_push;
        }
    else 
        {
        Registration* tmp = queue->head;
        Registration* traceback = tmp;
        while ( tmp != NULL)
            {
            traceback = tmp;
            tmp = tmp->next;
            }
        traceback->next = to_push;
        }
    }

void print_list(List* queue)
    {
    Registration* tmp = queue->head;
    while(tmp != NULL)
        {
        print_info(tmp->pas);
        tmp = tmp->next;
        }
    }