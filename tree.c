#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

Tree * file_tree() {
        Tree *tree = (Tree*)calloc(1,sizeof(Tree));
        char filename[128];
        printf("Enter filename: ");
        scanf("%s%*c", filename);
        FILE *file = fopen(filename, "r");
        if (file == NULL) {
                printf("File not found\n");
        }
        else {
                char key[140], info[140];
                while (!feof(file)) {
                        if (fscanf(file, "%s\n%s", key, info) == 2) {
                                insert(tree, key, info);
                        }
                }
        }
        fclose(file);
        return tree;
}

Tree * create_tree(){
	int choice;
	printf("NEED LOAD FROM FILE: (1 - YES)\n");
	scanf("%d", &choice);
	if(choice == 1){
		return file_tree();
	}
	return (Tree*)calloc(1,sizeof(Tree));
}

int STR_CMP(const char *p1, const char *p2){
	const unsigned char *s1 = (const unsigned char *) p1;
	const unsigned char *s2 = (const unsigned char *) p2;
	unsigned char c1, c2;
  	do{
      		c1 = (unsigned char) *s1++;
      		c2 = (unsigned char) *s2++;
      		if (c1 == '\0'){
        		return c1 - c2;
		}
    	}while (c1 == c2);
  	return c1 - c2;
}

int insert(Tree* tree, char* key, char* info) {
	Node * new_elem = new_node();
	create_node(new_elem, key, info);
  	if (tree->root == NULL) {
    		tree->root = new_elem;
    		return 0;
  	}
  	Node *direction = tree->root;
  	Node *curr = tree->root;
  	int res;
  	while (direction) {
    		curr = direction;
    		res = STR_CMP(curr->key, key);
    		if (res == 0){
      			break;
		}

    		if (res > 0){
      			direction = curr->left;
		}
    		else{
      			direction = curr->right;
		}
  	}
  	new_elem->parent = curr;
  	if (res == 0) {
    		new_elem->right = curr->right;
    		curr->right = new_elem;
    		if (new_elem->right){
      			new_elem->right->parent = new_elem;
    		}
  	}
  	else if (res > 0){
    		curr->left = new_elem;
  	}
	else{
    		curr->right = new_elem;
  	}
	return 0;
}

Node * search_node(Node * root, char * key){
    	Node * res = NULL;
    	if (root == NULL){
        	return res;
    	}
    	int cmp = 0;
    	cmp = STR_CMP(root->key, key);
    	if (cmp == 0){
        	res = root;
    	}
    	else if(cmp > 0){
        	res = search_node(root->left, key);
    	}
    	else{
        	res = search_node(root->right, key);
    	}
    	return res;
}

void search_tree(Node * root, char * key, Node ***vector, int *size) {
	if (root == NULL){
		return;
	}
  	int cmp;
 	while (root != NULL) {
    		cmp = STR_CMP(root->key, key);
    		if (cmp == 0) {
      			if (*vector == NULL) {
        			*vector = calloc(10, sizeof(Node*));
      			}
      			(*vector)[*size] = root;
      			++*size;

      			if (*size % 10 == 0){
        			*vector = realloc(*vector, sizeof(Node*) * (*size + 10));
			}
    		}
    		if (cmp > 0){
      			root = root->left;
		}
    		else{
      			root = root->right;
		}
  	}
  	if (*size != 0){
    		*vector = realloc(*vector, sizeof(Node*) * (*size));
	}
}


void swap_node(Node *n1, Node *n2) {
  	Node tmp;
  	tmp.key = n1->key;
  	tmp.info = n1->info;

  	n1->key = n2->key;
  	n1->info = n2->info;

  	n2->key = tmp.key;
  	n2->info = tmp.info;
}

void erase_node(Node **root, char *key) {
  	Node *deleted_node = search_node(*root, key);
  	if (deleted_node == NULL){
    		return;
  	}
  	if (deleted_node->left && deleted_node->right) {
    		Node *victim = deleted_node->right;
    		while (victim->left){
      			victim = victim->left;
		}
    		swap_node(victim, deleted_node);
    		deleted_node = victim;
  	}

  	Node *grandson = deleted_node->left;
  	if (deleted_node->right){
    		grandson = deleted_node->right;
	}
	if (deleted_node->parent != NULL){
  		Node *parent = deleted_node->parent;
  		if (parent->left == deleted_node){
    			parent->left = grandson;
		}
  		else{
    			parent->right = grandson;
		}
	}
  	if (deleted_node == *root){
    		if ((*root)->left){
      			*root = (*root)->left;
		}
    		else{
      			*root = (*root)->right;
		}
  	}

  	del_node(deleted_node);
}

void print_tree(Node * root){
	if (root == NULL){
		return;
	}
	if (root->key && root->info){
		printf("key - %s , info - %s \n", root->key, root->info);
	}
	print_tree(root->left);
	print_tree(root->right);
}

void del_tree_nodes(Node * root){
	if (root == NULL){
		return;
	}
	del_tree_nodes(root->left);
	del_tree_nodes(root->right);
	if (root->key && root->info){
		free(root->key);
		free(root->info);
	}
	free(root);
}

void del_tree(Tree * tree){
	if (tree->root != NULL){
		del_tree_nodes(tree->root);
	}
	free(tree);
}

void special_search(Node *root, char *key, Node ***vector, int *size) {
	if (root == NULL){
    		return;
  	}
	special_search(root->left, key, vector, size);
	special_search(root->right, key, vector, size);

  	int cmp = STR_CMP(root->key, key);
  	if (cmp == 0){
    		return;
	}
  	if (*size == 0) {
    		if (*vector == NULL) {
      			*vector = calloc(20, sizeof(Node*));
    		}
    		(*vector)[*size] = root;
    		++*size;
  	}
  	else {
    		int diff = STR_CMP((*vector)[0]->key, key);
    		printf("ROOT: %10s\tCMP: %d\tVECTOR: %10s\tDIFF %d\n", root->key, cmp, (*vector)[0]->key, diff);
    		if (abs(cmp) < abs(diff)) {
      			(*vector)[0] = root;
      			*size = 1;
    		}
    		else if (abs(cmp) == abs(diff)) {
      			(*vector)[*size] = root;
     			++*size;
    		}
  	}
}

void tree_form(int depth, int isLeftNode, Node *node) {
  	if (node == NULL){
		return;
	}

  	tree_form(depth + 1, 0, node->right);
  	for (int i = 0; i < depth; ++i) {
    		printf(" ");
  	}
  	if (isLeftNode == 0){
    		printf("/");
	}
  	else if (isLeftNode == 1){
   		printf("\\");
	}
  	printf("%s\n", node->key);
  	tree_form(depth + 1, 1, node->left);
}
