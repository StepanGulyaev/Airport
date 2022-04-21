#include "Registration.h"
#include "queue.h"
#include "table.h"
#include "limits.h"


Table* new_table(){
    	return (Table*)calloc(1,sizeof(Table));
}

void create_table(Table* table, int count){
    	//printf("Enter number of rows: ");
    	//scanf("%llu",&(table->n));
	table->n = count;
        table->rows = (Queue**)calloc(table->n,sizeof(Queue*));
    	for (size_t i = 1; i <= table->n; i++){
        	table->rows[i] = new_queue();
        	create_queue(table->rows[i]);
        }
}
#ifdef LIST_USE 
void push_to_table(Table* table, Registration * reg){
    	size_t min_len = ULLONG_MAX;
    	size_t index_min_len = 1;
    	for(size_t i = 1; i<= table->n;i++){
        	if (table->rows[i]->len <= min_len){
            		min_len = table->rows[i]->len;
            		index_min_len = i;
		}
        }
    	push(table->rows[index_min_len],reg);
}
#else

#endif
void print_table(Table* table){
    	for(size_t i = 1; i <= table->n;i++){
        	printf("%llu  ",i + 1);
        	print_queue(table->rows[i]);
        	printf("\n");
        }
}
