#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
        char * key;
        char * info;
        struct Node * left;
        struct Node * right;
        struct Node * parent;
} Node;

Node * new_node();
void create_node(Node * elem, char * key, char * info);
void del_node(Node * elem);



#endif
