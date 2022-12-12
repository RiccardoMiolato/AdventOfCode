#include <iostream>
#include <fstream>
#include "rope.h"

using namespace std;

void init(knot *&h, int dim){
    if(dim > 1){
        h = new knot;
        h->nodes = new node;
        h->nodes->x = 0;
        h->nodes->y = 0;
        h->nodes->next = NULL;
        init(h->next, dim - 1);
    }else if(dim == 1){
        h = new knot;
        h->nodes = new node;
        h->nodes->x = 0;
        h->nodes->y = 0;
        h->nodes->next = NULL;
        h->next = NULL;
        h->nNodesVisited = 1;
    }
}

void move_head(knot *&h, int x, int y){
    nodeList _node = new node;
    _node->x = x;
    _node->y = y;
    _node->next = NULL;

    nodeList tmp = get_last(h->nodes);
    tmp->next = _node;

    if(h->next != NULL && !next_touches_prev(h->next, h)){
        nodeList head_pos = get_last(h->nodes);
        nodeList tail_pos = get_last(h->next->nodes);

        x = tail_pos->x;
        y = tail_pos->y;

        if(x == head_pos->x || x == head_pos->x + 1 || x == head_pos->x - 1)
            x = head_pos->x;
        else if(x > head_pos->x - 2)
            x -= 1;
        else
            x += 1;

        if(y == head_pos->y || y == head_pos->y + 1 || y == head_pos->y - 1)
            y = head_pos->y;
        else if(y > head_pos->y - 2)
            y -= 1;
        else
            y += 1;
            
        if(h->next->next == NULL && !contain_position(h->next, x, y))
            h->next->nNodesVisited += 1;

        move_head(h->next, x, y);
    }
}

nodeList get_last(nodeList list){
    if(list != NULL){
        while(list->next != NULL)
            list = list->next;

        return list;
    }
    return NULL;
}

bool next_touches_prev(knot *&next, knot *&prev){
    nodeList next_pos = get_last(next->nodes);
    nodeList prev_pos = get_last(prev->nodes);

    if(next_pos->x < prev_pos->x - 1 || next_pos->x > prev_pos->x + 1)
        return false;

    if(next_pos->y < prev_pos->y - 1 || next_pos->y > prev_pos->y + 1)
        return false;

    return true;
}

bool contain_position(knot *&h, int x, int y){
    nodeList tmp = h->nodes;
    bool contains = false;

    while(tmp != NULL && !contains){
        if(tmp->x == x && tmp->y == y)
            contains = true;

        tmp = tmp->next;
    }

    return contains;
}

void print_positions(nodeList list){
    while(list != NULL){
        cout << "x: " << list->x << "  |  y: " << list->y << endl;
        list = list->next;
    }
}

knot* get_tail(knot *head){
    while(head->next != NULL)
        head = head->next;

    return head;
}