#include <iostream>
#include <fstream>
#include "rope.h"

using namespace std;

void init(head *&h, tail *&t){
    h = new head;
    h->nodes = new node;
    h->nodes->x = 0;
    h->nodes->y = 0;
    h->nodes->next = NULL;

    t = new tail;
    t->nNodesVisited = 1;
    t->nodes = new node;
    t->nodes->x = 0;
    t->nodes->y = 0;
    t->nodes->next = NULL;
}

void move_head(head *&h, tail *&t, int x, int y){
    nodeList _node = new node;
    _node->x = x;
    _node->y = y;
    _node->next = NULL;

    nodeList tmp = get_last(h->nodes);
    tmp->next = _node;

    if(!tail_touches_head(t, h))
        move_tail(h, t);
}

void move_tail(head *&h, tail *&t){
    nodeList head_pos = get_last(h->nodes);
    nodeList tail_pos = get_last(t->nodes);
    nodeList new_pos = new node;
    new_pos->x = tail_pos->x;
    new_pos->y = tail_pos->y;
    new_pos->next = NULL;

    if(head_pos->x < tail_pos->x - 1){
        new_pos->x -= 1;
        new_pos->y = head_pos->y;
    }else if(head_pos->x > tail_pos->x + 1){
        new_pos->x += 1;
        new_pos->y = head_pos->y;
    }
    
    if(head_pos->y < tail_pos->y - 1){
        new_pos->y -= 1;
        new_pos->x = head_pos->x;
    }else if(head_pos->y > tail_pos->y + 1){
        new_pos->y += 1;
        new_pos->x = head_pos->x;
    } 
    
    if(!contain_position(t, new_pos->x, new_pos->y))
        t->nNodesVisited += 1;

    tail_pos->next = new_pos;
}

nodeList get_last(nodeList list){
    if(list != NULL){
        while(list->next != NULL)
            list = list->next;

        return list;
    }
    return NULL;
}

void print_positions(nodeList list){
    int i = 0;
    while(list != NULL){
        cout << ++i << " - x: " << list->x << "  |  y: " << list->y << endl;
        list = list->next;
    }
}


bool tail_touches_head(tail *&t, head *&h){
    nodeList head_pos = get_last(h->nodes);
    nodeList tail_pos = get_last(t->nodes);

    if(head_pos->x < tail_pos->x - 1 || head_pos->x > tail_pos->x + 1)
        return false;

    if(head_pos->y < tail_pos->y - 1 || head_pos->y > tail_pos->y + 1)
        return false;

    return true;
}

bool contain_position(tail *&t, int x, int y){
    nodeList tmp = t->nodes;
    bool contains = false;

    while(tmp != NULL && !contains){
        if(tmp->x == x && tmp->y == y)
            contains = true;

        tmp = tmp->next;
    }

    return contains;
}
