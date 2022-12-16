#ifndef TREE_LIST_H
#define TREE_LIST_H
#include "tree.h"

struct listElement
{
    tree root;
    listElement* next;
};
typedef listElement* treeList;

void init();
void add_element(tree root);
void printList();
int get_index_of(tree root);
void deinit();


#endif