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

void create_queue(List* queue)
    {
    queue->head = NULL;
    queue->len = 0;
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
    queue->len++;
    }

void pop(List* queue)
    {
    Registration* tmp = queue->head;
    queue->head = queue->head->next;
    free_registration(tmp);
    queue->len--;
    }

Registration* peek(List* queue)
    {
    return queue->head;
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

void create_queue(Vector* queue)
    {
    queue->len = 0;
    queue->vector = (Registration**)calloc(queue->len,sizeof(Registration*));
    }

void push(Vector* queue,Registration* to_push)
    {
    queue->len++;
    queue->vector = (Registration**)realloc(queue->vector, (queue->len)*(sizeof(Registration*)));
    queue->vector[queue->len-1] = (Registration*)calloc(1,sizeof(Registration));
    queue->vector[queue->len - 1] = to_push;
    }

void pop(Vector* queue)
    {
    for(size_t i = 1; i < queue->len; i++)
        {
        queue->vector[i-1] = queue->vector[i]; 
        }
    free_registration(queue->vector[queue->len]);
    queue->len--;
    queue->vector = (Registration**)realloc(queue->vector, (queue->len)*(sizeof(Registration*)));
    }

Vector* peek(Vector*queue)
    {
    return queue->vector[0];
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
        free_registration(queue->vector[i]);
        }
    free(queue->vector);
    free(queue);
    }

#endif 
