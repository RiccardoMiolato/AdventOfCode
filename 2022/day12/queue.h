#ifndef QUEUE_H
#define QUEUE_H

struct node{
    int x;
    int y;
    int dist;
    node* next;
};
typedef node* linkedList;

void init();
void enqueue(int x, int y, int dist);
linkedList dequeue();
linkedList first_el();
bool empty();
void print();
void deinit();

#endif