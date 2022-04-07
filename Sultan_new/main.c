#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "Queue.h"
#include "Table.h"


int main()
    {

        
    Queue* queue = new_queue();
    create_queue(queue);

    size_t size;
    printf("Enter size of a start queue: ");
    scanf("%llu",&size);
    fill_queue(queue,size);
    print_queue(queue);

    Table* table = new_table();
    create_table(table);

    push_to_table(table,queue->head);
    pop(queue);
    push_to_table(table,queue->head);
    //move_all(queue,table,4);

    print_queue(queue);
    printf("\n");
    print_table(table);
    }