#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "node.h"
#include "tree.h"
#include <time.h>
#include <malloc.h>


int correct_int(const char *str) {
        for (; *str != '\0' && *str != '\n'; ++str){
                if (!('0' <= *str && *str <= '9')){
                        return 1; // FAILURE
                }
        }
        return 0; // SUCCESS
}

int get_int(int a, int b) {
        char str[140];
        int size;
        fgets(str, 140, stdin);
        while (correct_int(str) == 1 || (size = atoi(str)) < a || size > b){
                printf("NOT CORRECT VALUE: ");
                fgets(str, 140, stdin);
        }
        return size;
}

int menu() {
	printf("1. SEARCH\n"
         	"2. ADD\n"
         	"3. DELETE ELEM\n"
         	"4. DISPLAY\n"
         	"5. SEARCH CLOSEST\n"
		"6. TREE FORM\n"
         	"0. EXIT\n"
         	"> ");
  	return get_int(0, 6);
}

int main(){
	Tree * tree = create_tree();
        while (1){
    		int choice = menu();
    		if (choice == 0){
      			break;
		}
		char key[140], info[140];
		Node **buff = NULL;
		int size = 0;
		int i = 0;
		switch(choice){
			case 1:
				printf("ENTER (KEY): ");
				scanf("%s%*c", key);
				search_tree(tree->root, key, &buff, &size);
				if(size != 0){
                                        while(i < size){
                                                printf("key - %s , info - %s \n", buff[i]->key, buff[i]->info);
                                                i++;
                                        }
                                }
				break;
			case 2:
				printf("ENTER (KEY INFO): ");
				scanf("%s %s%*c", key, info);
				insert(tree, key, info);
				break;
			case 3:
				printf("ENTER (KEY INFO): ");
				scanf("%s%*c", key);
				erase_node(&(tree->root), key);
				break;
			case 4:
				if (tree->root != NULL){
					print_tree(tree->root);
				}
				else {
					printf("TREE IS EMPTY\n");
				}
				break;
			case 5:
				printf("ENTER (KEY INFO): ");
                                scanf("%s%*c", key);
				special_search(tree->root, key, &buff, &size);
				if(size != 0){
                        		while(i < size){
						printf("key - %s , info - %s \n", buff[i]->key, buff[i]->info);
						i++;
					}
                		}
				break;
			case 6:
				tree_form(0,3, tree->root);
				break;
		}
		printf("\n\n");
		free(buff);
	}
	del_tree(tree);
        return 0;
}

