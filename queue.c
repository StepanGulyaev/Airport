#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "queue.h"
#include <limits.h>
//#include "Table.h"

#ifdef LIST_USE

Queue* new_queue(){
   	return (Queue*)calloc(1,sizeof(Queue));
}

void fill_queue(Queue* queue){
	Passenger * pas_mas = (Passenger *)calloc(10,sizeof(Passenger ));
	Passenger **tmp = &pas_mas;
	int count = 0;
	int size = 10;
	add_info(tmp, &size, &count);
	int i = 0;
	while(i<size){
		if ((*tmp +i)->id == NULL){
			break;
		}
		Registration* reg = new_registration();
		add_passenger(reg, *tmp + i);
		push(queue,reg);
		i++;
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
		queue->tail->next = NULL;
	}
    	else{
       		queue->tail->next = to_push;
		queue->tail = to_push;
		queue->tail->next = NULL;
        }
	queue->len++;
}

void pop(Queue* queue){
    	Registration* tmp = queue->head;
    	queue->head = queue->head->next;
    	free_registration(tmp);
    	queue->len--;
}

void remove_f_q(Queue* queue,Registration* to_remove){
        Registration* pre_tmp = queue->head;
        Registration* tmp = pre_tmp->next;
        if(to_remove == queue->head){
                pop(queue);
                return;
      	}
        else{
                while(tmp != to_remove){
                        pre_tmp = tmp;
                        tmp = tmp->next;
                }
                pre_tmp->next = tmp->next;
                queue->len--;
       	}
}

/*void sort_queue(Queue* queue, Queue * sorted_q){
        //Queue* sorted_q = new_queue();
        //create_queue(sorted_q);
        while(queue->len != 0){
                Registration* tmp = queue->head;
                int ta_min = INT_MAX;
                Registration* save_adress = NULL;
		printf("GOOD\n");
                while(tmp!= NULL){
			//print_info(tmp->pas);
                        if(tmp->pas->ta < ta_min){
                                ta_min=tmp->pas->ta;
                                save_adress = tmp;
				printf("123\n");
                        }
			tmp=tmp->next;
                }
		print_info(save_adress->pas);
                push(sorted_q,save_adress);
                remove_f_q(queue,save_adress);
        }
}*/

/*Registration* peek(Queue* queue){
    	return queue->head;
}*/
/*void move_all(Queue* queue, Table* table, size_t time){
	Registration* tmp = queue->head;
	while(tmp != NULL){
		if (tmp->pas->ta == time){
			push_to_table(table, tmp);
			remove_f_q(queue,tmp);
		}
		tmp = tmp->next;
	}
}*/

void print_queue(Queue* queue){
    	Registration* tmp = queue->head;
    	while(tmp != NULL){
        	print_info(tmp->pas);
        	tmp = tmp->next;
        }
	printf("\n");
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

#else

Queue* new_queue(){
    	return (Queue*)calloc(1,sizeof(Queue));
}

void fill_queue(Queue* queue, size_t len){
    	queue->len = len;
    	queue->pas = (Passenger*)calloc(queue->len,sizeof(Passenger));
    	for (size_t i = 0; i < len; i++){
        	queue->len++;
        	queue->pas = (Passenger*)realloc(queue->vector, (queue->len)*(sizeof(Passenger)));
        	queue->pas[i] = (Passenger*)calloc(1,sizeof(Passenger));
        	Passenger* pas = new_Passenger();
        	add_info(pas);
        	push(queue,pas);
        }
}

void push(Queue* queue,Passenger *pas){
    	queue->vector[queue->len - 1] = pas;
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
