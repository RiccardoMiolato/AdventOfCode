#ifndef ROPE_H
#define ROPE_H

struct node{
    int x;
    int y;
    node* next;
};
typedef node* nodeList;

struct head{
    nodeList nodes;
};

struct tail{
    nodeList nodes;
    int nNodesVisited;
};

void init(head *&h, tail *&t);
void move_head(head *&h, tail *&t, int x, int y);
void move_tail(head *&h, tail *&t);
nodeList get_last(nodeList list);
bool tail_touches_head(tail *&t, head *&h);
bool contain_position(tail *&t, int x, int y);
void print_positions(nodeList list);

#endif