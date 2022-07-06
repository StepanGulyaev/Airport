#ifndef TREE_H
#define TREE_H

#include "node.h"

typedef struct Tree{
	Node * root;
}Tree;

Tree * create_tree();
int insert(Tree *, char*, char*);
void print_tree(Node *);
void del_tree_nodes(Node *);
void erase_node(Node**, char*);
void search_tree(Node*, char*, Node***, int*);
void del_tree(Tree *);
void special_search(Node*, char*, Node***, int*);
void tree_form(int, int, Node *);
Tree * file_tree();


#endif
