#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node * new_node(){
        return (Node*)calloc(1,sizeof(Node));
}

void create_node(Node * node, char * key, char * info){
        if(node == NULL){
                return;
        }
        int len_key = strlen(key);
        int len_info = strlen(info);
        node->key = malloc(sizeof(char) *(len_key + 1));
        node->info = malloc(sizeof(char) *(len_info + 1));
        strcpy(node->key, key);
        strcpy(node->info, info);
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
}

void del_node(Node * node){
	free(node->key);
	free(node->info);
	free(node);
}

