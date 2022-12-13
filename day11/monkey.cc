#include <iostream>
#include "monkey.h"

using namespace std;

void init(monkey* &_monkey, int id, int test){
    _monkey = new monkey;
    _monkey->id = id;
    _monkey->test = test;
    _monkey->items_processed = 0;
    _monkey->items = NULL;
    _monkey->true_test = NULL;
    _monkey->false_test = NULL;
}

void process_items(monkey* _monkey){
    while(_monkey->items != NULL){
        _monkey->items_processed += 1;

        item* tmp = get_item(_monkey);
        switch(_monkey->id){
            case 0:
                tmp->value = tmp->value * 13;
                break;
            case 1:
                tmp->value = tmp->value * tmp->value;
                break;
            case 2:
                tmp->value = tmp->value + 6;
                break;
            case 3:
                tmp->value = tmp->value + 2;
                break;
            case 4:
                tmp->value = tmp->value + 3;
                break;
            case 5:
                tmp->value = tmp->value + 4;
                break;
            case 6:
                tmp->value = tmp->value + 8;
                break;
            case 7:
                tmp->value = tmp->value * 7;
                break;
        }

        tmp->value = tmp->value / 3;
        if(tmp->value % _monkey->test == 0)
            throw_item(_monkey->true_test, tmp);
        else
            throw_item(_monkey->false_test, tmp);
    }
}

void throw_item(monkey* _monkey, item* _item){
    item* ptr = _monkey->items;
   
    if(ptr == NULL){
        _monkey->items = _item;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = _item;
    }
}

void add_item(item* &items, int value){
    item* tmp = new item;
    tmp->next = NULL;
    tmp->value = value;

    if(items == NULL)
        items = tmp;
    else{
        item* ptr = items;

        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = tmp;
    }
}

item* get_item(monkey* _monkey){
    if(_monkey->items == NULL)
        return NULL;
    else{
        item* tmp = _monkey->items;
        _monkey->items = _monkey->items->next;
        tmp->next = NULL;
        return tmp;
    }
}

void print_items(monkey* _monkey){
    item* ptr = _monkey->items;

    cout << "Monkey " << _monkey->id << " (" << _monkey->items_processed << "): ";

    while(ptr != NULL){
        cout << ptr->value << ' ';
        ptr = ptr->next;
    }

    cout << endl;
}
