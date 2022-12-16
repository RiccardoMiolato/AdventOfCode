#include <iostream>
#include "treeList.h"

using namespace std;

static treeList head;

void init(){
    head = NULL;
}

void add_element(tree root){
    if(head == NULL){
        head = new listElement;
        head->root = root;
        head->next = NULL;
    }else{
        treeList tmp = new listElement;
        tmp->root = root;
        tmp->next = NULL;

        treeList ptr = head;
        bool inserted = false;

        while(!inserted && ptr != NULL){
            if(compare(ptr->root, tmp->root) == 1){
                tmp->next = ptr;
                
                if(ptr == head)
                    head = tmp;

                inserted = true;
            }else{
                if(ptr->next != NULL){
                    if(compare(ptr->next->root, tmp->root) == 1){
                        tmp->next = ptr->next;
                        ptr->next = tmp;
                        inserted = true;
                    }
                }else{
                    ptr->next = tmp;
                    inserted = true;
                }
            }
            ptr = ptr->next;
        }
    }
}

int get_index_of(tree root){
    if(head != NULL){
        treeList tmp = head;
        int index = 1;

        while(tmp != NULL){
            if(tmp->root == root)
                return index;

            tmp = tmp->next;
            index++;
        }
    }

    return -1;
}
void printList(){
    if(head != NULL){
        treeList tmp = head;

        while(tmp != NULL){
            print(tmp->root);
            cout << endl;
            tmp = tmp->next;
        }
    }
}

void deinit(){
    while(head != NULL){
        treeList tmp = head;
        head = head->next;
        deinit(tmp->root);
        delete tmp;
    }
}