#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"

#ifdef MAKE_LIST

List* new_queue()
    {
    return (List*)calloc(1,sizeof(List));   
    }

void fill_queue(List* queue)
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

void print_queue(List* queue)
    {
    Registration* tmp = queue->head;
    while(tmp != NULL)
        {
        print_info(tmp->pas);
        tmp = tmp->next;
        }
    }

void free_queue(List* queue)
    {
    Registration* tmp = queue->head;
    Registration* next = tmp;
    while(tmp != NULL)
        {
        next = tmp->next;
        free_registration(tmp);
        tmp = next;
        }
    free(queue);
    }

#else

Vector* new_queue()
    {
    return (Vector*)calloc(1,sizeof(Vector));
    }

void fill_queue(Vector* queue)
    {
    queue->len = 0;
    queue->vector = (Registration**)calloc(queue->len,sizeof(Registration*));
    for (size_t i = 0; i < 3; i++)
        {
        queue->len++;
        queue->vector = (Registration**)realloc(queue->vector, (queue->len)*(sizeof(Registration*)));
        queue->vector[i] = (Registration*)calloc(1,sizeof(Registration));
        
        Passenger* pas = new_Passenger();
        add_info(pas);

        Registration* reg = new_registration();
        add_passenger(reg,pas);

        push(queue,reg);
        }
    }

void push(Vector* queue,Registration* reg)
    {
    queue->vector[queue->len - 1] = reg;
    }

void print_queue(Vector* queue)
    {
    for (size_t i = 0; i < queue->len; i++)
        {
        print_info(queue->vector[i]->pas);
        }
    }

void free_queue(Vector* queue)
    {
    for (size_t i = 0; i < queue->len; i++)
        {
        free(queue->vector[i]);
        }
    free(queue->vector);
    free(queue);
    }

#endif 