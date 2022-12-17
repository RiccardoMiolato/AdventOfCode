#include <iostream>
#include "list.h"

using namespace std;

static cave head;
static cave tail;

void init(){
    head = NULL;
    tail = NULL;
}

cave get_head(){
    return head;
}

void add_rock(){
    if(head == NULL){
        head = new rock;
        head->positions = NULL;
        head->next = NULL;
        tail = head;
    }else{
        tail->next = new rock;
        tail = tail->next;
        tail->positions = NULL;
        tail->next = NULL;
    }
}

void add_coordinates(int x, int y){
    if(tail->positions == NULL){
        tail->positions = new point;
        tail->positions->x = x;
        tail->positions->y = y;
        tail->positions->next = NULL;
    }else{
        pointList tmp = tail->positions;

        while(tmp->next != NULL)
            tmp = tmp->next;

        tmp->next = new point;
        tmp = tmp->next;
        tmp->x = x;
        tmp->y = y;
        tmp->next = NULL;
    }
}

void get_matrix_dimensions(int &maxX, int &minX, int &maxY, int &minY){
    maxX = INT_MIN;
    maxY = INT_MIN;
    minX = INT_MAX;
    minY = INT_MAX;

    cave ptr = head;
    pointList tmp;

    while(ptr != NULL){
        tmp = ptr->positions;

        while (tmp != NULL)
        {
            if(tmp->x > maxX)
                maxX = tmp->x;
            else if(tmp->x < minX)
                minX = tmp->x;

            if(tmp->y > maxY)
                maxY = tmp->y;
            else if(tmp->y < minY)
                minY = tmp->y;
                
            tmp = tmp->next;
        }
        
        ptr = ptr->next;
    }
}

void printPositions(cave rock){
    pointList tmp = rock->positions;

    while(tmp != NULL){
        cout << tmp->x << ',' << tmp->y;

        if(tmp->next != NULL)
            cout << " -> ";
        
        tmp = tmp->next;
    }
    cout << endl;
}

void printRocks(){
    cave tmp = head;

    while(tmp != NULL){
        printPositions(tmp);
        tmp = tmp->next;
    }
}

void deinitPositions(pointList list){
    while(list != NULL){
        pointList tmp = list;
        list = list->next;
        delete tmp;
    }
}

void deinit(){
    while(head != NULL){
        deinitPositions(head->positions);

        cave tmp = head;
        head = head->next;
        delete tmp;
    }
}
