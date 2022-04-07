#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"
#include "Table.h"
#include "limits.h"


Table* new_table()
    {
    return (Table*)calloc(1,sizeof(Table));
    }

void create_table(Table* table)
    {
    
    printf("Enter number of rows: ");
    scanf("%llu",&(table->n));

    #ifdef LIST_USE
        table->rows = (Queue**)calloc(table->n,sizeof(Queue*));
    #else
        //table->rows = (Vector**)calloc(table->n,sizeof(Vector*));
    #endif

    for (size_t i = 1; i <= table->n; i++)
        {
        table->rows[i] = new_queue();
        create_queue(table->rows[i]);
        }
    }

void push_to_table(Table* table, Registration* reg)
    {
    size_t min_len = ULLONG_MAX;
    size_t index_min_len = 1;
    for(size_t i = 1; i<= table->n;i++)
        {
        if (table->rows[i]->len <= min_len)
            {
            min_len = table->rows[i]->len;
            index_min_len = i;
            }
        }
    push(table->rows[index_min_len],reg);
    }

void print_table(Table* table)
    {
    for(size_t i = 1; i <= table->n;i++)
        {
        printf("%llu  ",i);
        print_queue(table->rows[i]);
        printf("\n");
        }
    }

void move_all(Queue* queue,Table* table,size_t time)
        {
        Registration* tmp = queue->head;
        while(tmp != NULL)
            {
            if(tmp->pas->ta == time)
                {
                push_to_table(table,tmp);
                remove_f_q(queue,tmp);
                }
            tmp = tmp->next;
            }
        }
