#ifndef TREE_H
#define TREE_H

struct node{
    int value;
    node* father;
    node* sons;
    node* next;
};
typedef node* tree;

void init(tree &);
void deinit(tree &);
void add_value(tree &, int value);
void add_next(tree &);
void add_sons(tree &);
int compare(tree t1, tree t2);
void print(tree);

#endif