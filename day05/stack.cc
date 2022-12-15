#include <iostream>
#include "stack.h"

using namespace std;

void init(stack &s){
    s = NULL;
}

void push(stack &s, char letter){
    if(s == NULL){
        s = new crate;
        s->letter = letter;
        s->next = NULL;
    }else{
        stack tmp = new crate;
        tmp->letter = letter;
        tmp->next = s;
        s = tmp;
    }
}

void push(stack &s, stack element){
    if(s != NULL){
        element->next = s;
        s = element;
    }else{
        s = element;
    }
}

stack pop(stack &s){
    if(s != NULL){
        stack tmp = s;
        s = tmp->next;
        tmp->next = NULL;
        return tmp;
    }
    return NULL;
}

char top(stack s){
    if(s != NULL)
        return s->letter;

    return NULL;
}

void deinit(stack &s){
    while(s != NULL){
        stack tmp = s;
        s = tmp->next;
        tmp->next = NULL;
        delete tmp;
    }
}

void print(stack s){
    while(s != NULL){
        cout << s->letter << endl;
        s = s->next;
    }
}
