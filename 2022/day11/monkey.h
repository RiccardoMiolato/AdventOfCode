#ifndef MONKEY_H
#define MONKEY_H

struct item
{
    long long int value;
    item* next;
};


struct monkey
{
    int id;
    int items_processed;
    int test;
    monkey* true_test;
    monkey* false_test;
    item* items;
};

void init(monkey* &_monkey, int id, int test);
void process_items_test(monkey* _monkey, int divisor);
void process_items_puzzle(monkey* _monkey, int divisor);
void add_item(item* &items, int value);
void throw_item(monkey* _monkey, item* _item);
item* get_item(monkey* _monkey);
void print_items(monkey* _monkey);


#endif