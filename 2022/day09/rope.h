#ifndef ROPE_H
#define ROPE_H

struct node{
    int x;
    int y;
    node* next;
};
typedef node* nodeList;

struct knot{
    nodeList nodes;
    int nNodesVisited;
    knot* next;
};

void init(knot *&h, int dim);
void move_head(knot *&h, int x, int y);
nodeList get_last(nodeList list);
bool next_touches_prev(knot *&t, knot *&h);
bool contain_position(knot *&t, int x, int y);
void print_positions(nodeList list);
knot* get_tail(knot *head);


#endif