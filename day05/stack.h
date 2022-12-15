#ifndef STACK_H
#define STACK_H

struct crate{
    char letter;
    crate* next;
};
typedef crate* stack;

void init(stack &s);
void push(stack &s, char letter);
void push(stack &s, stack element);
stack pop(stack &s);
char top(stack s);
void deinit(stack &s);
void print(stack s);

#endif