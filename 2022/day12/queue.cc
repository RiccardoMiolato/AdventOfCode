#include <iostream>
#include "queue.h"

using namespace std;

static linkedList head;
static linkedList tail;

void init(){
    head = NULL;
    tail = NULL;
}

void enqueue(int x, int y, int dist){
    linkedList tmp = new node;
    tmp->x = x;
    tmp->y = y;
    tmp->dist = dist;
    tmp->next = NULL;

    if(head == NULL){
        head = tmp;
        tail = head;
    }else{
        tail->next = tmp;
        tail = tail->next;
    }
}

linkedList first_el(){
    if(head == NULL)
        return NULL;
    else
        return head;
}

linkedList dequeue(){
    if(head == NULL)
        return NULL;
    else{
        linkedList tmp = head;
        head = head->next;
        tmp->next = NULL;
        
        return tmp;
    }
}

void print(){
    linkedList tmp = head;
    while(tmp != NULL){
        cout << "(" << tmp->x << "," << tmp->y << ")  - dist: " << tmp->dist << endl;
        tmp = tmp->next;
    }
}

bool empty(){
    if(head != NULL)
        return false;
    else
        return true;
}

void deinit(){
    linkedList tmp;
    while(head != NULL){
        tmp = head;
        head = head->next;
        delete tmp;
    }
}
