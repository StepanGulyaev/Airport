#include "stdio.h"
#include "stdlib.h"
#include "Passenger.h"
#include "Registration.h"
#include "queue.h"
#include "table.h"


int main(){
	Queue* queue = new_queue();
	create_queue(queue);
	int count = 0;
	Table * table = new_table();
	Passenger *pas = (Passenger *)calloc(100,sizeof(Passenger ));
	Passenger **tmp = &pas;
	int size = 0;
	int i = 0;
	add_info(tmp,&size, &count);
	create_table(table,count);
	printf("\n");
	while(i < size){
		Registration * reg = new_registration();
		add_passenger(reg, (*tmp+i));
		push_to_table(table, reg);
		i++;
	}
	print_table(table);
	return 0;
}
