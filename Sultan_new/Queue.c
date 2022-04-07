#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"

#ifdef LIST_USE

Queue* new_queue(){
        return (Queue*)calloc(1,sizeof(Queue));
}

void fill_queue(Queue* queue,size_t n)
        {
        for (size_t i = 0; i < n; i++)
                {
                Passenger* pas = new_Passenger();
                add_info(pas);

                Registration* reg = new_registration();
                add_passenger(reg,pas);

                push(queue,reg);
                }
        }

void create_queue(Queue* queue){
        queue->head = NULL;
        queue->tail = NULL;
        queue->len = 0;
}

void push(Queue* queue,Registration* to_push){
        if (queue->head == NULL){
                queue->head = to_push;
                queue->tail = queue->head;
        }
        else{
                queue->tail->next = to_push;
                queue->tail = to_push;
        }
}

void pop(Queue* queue)
        {
        Registration* tmp = queue->head;
        queue->head = queue->head->next;
        free_registration(tmp);
        queue->len--;
        }

void remove_f_q(Queue* queue,Registration* to_remove)
        {
        Registration* pre_tmp = queue->head;
        Registration* tmp = pre_tmp->next;

        if(to_remove == queue->head)
                {
                pop(queue);
                return;
                }
        else    
                {
                while(tmp != to_remove)
                        {
                        pre_tmp = tmp;
                        tmp = tmp->next;
                        }
                pre_tmp->next = tmp->next;
                queue->len--;
                }
        }


void print_queue(Queue* queue){
        Registration* tmp = queue->head;
        while(tmp != NULL){
                print_info(tmp->pas);
                tmp = tmp->next;
        }
}

void free_queue(Queue* queue){
        Registration* tmp = queue->head;
        Registration* next = tmp;
        while(tmp != NULL){
                next = tmp->next;
                free_registration(tmp);
                tmp = next;


}
        free(queue);
}
/*Passenger* peek(Queue* queue)
        {
        return queue->head->pas;
        }*/

#else

Qeueu* new_queue(){
        return (Queue*)calloc(1,sizeof(Queue));
}

void fill_queue(Queue* queue){
        queue->len = 0;
        queue->vector = (Registration**)calloc(queue->len,sizeof(Registration*));
        for (size_t i = 0; i < 3; i++){
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

void push(Queue* queue,Registration* reg){
        queue->vector[queue->len - 1] = reg;
}

void print_queue(Queue* queue){
        for (size_t i = 0; i < queue->len; i++){
                print_info(queue->vector[i]->pas);
        }
}

void free_queue(Queue* queue){
        for (size_t i = 0; i < queue->len; i++){
                free(queue->vector[i]);
        }
        free(queue->vector);
        free(queue);
}

#endif