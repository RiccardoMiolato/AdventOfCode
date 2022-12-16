#include <iostream>
#include "tree.h"

using namespace std;

void init(tree &t){
    t = new node;
    t->value = -1;
    t->father = NULL;
    t->sons = NULL;
    t->next = NULL;
}

void deinit(tree &t){
    if(t != NULL){
        if(t->sons != NULL)
            deinit(t->sons);

        if(t->next != NULL)
            deinit(t->next);

        delete t;
    }
}

void add_next(tree &t){
    if(t != NULL){
        t->next = new node;
        t->next->father = t->father;
        t->next->sons = NULL;
        t->next->value = -1;
        t->next->next = NULL;
    }

}

void add_value(tree &t, int value){
    if(t != NULL){
        t->value = value;
    }
}

void add_sons(tree &t){
    if(t != NULL){
        t->sons = new node;
        t->sons->next = NULL;
        t->sons->father = t;
        t->sons->sons = NULL;

        if(t->value == -1)
            t->sons->value = -1;
        else{
            t->sons->value = t->value;
            t->value = -1;
        }
    }
}

int compare(tree t1, tree t2){ // -1 t1 < t2; 0 t1 = t2; 1 t1 > t2
    if(t1 != NULL && t2 != NULL){
        /*cout << "Now comparing: ";
        print(t1);
        cout << " - ";
        print(t2);
        cout << endl;*/
        int return_value;

        if(t1->value != -1 && t2->value != -1){
            //cout << "- Compare " << t1->value << " vs " << t2->value << endl;
            if(t1->value > t2->value){
                //cout << "- Right side is smaller, so inputs are not in the right order" << endl;
                return_value = 1;
            }else if(t1->value < t2->value){
                //cout << "- Left side is smaller, so inputs are in the right order" << endl;
                return_value = -1;
            }else
                return_value = 0;
        }else if(t1->sons != NULL &&  t2->sons != NULL)
            return_value = compare(t1->sons, t2->sons);
        else if(t1->sons == NULL && t1->value != -1 && t2->sons != NULL){
            //cout << "- Mixed types, convert left to [" << t1->value << "] and retry" << endl; 
            add_sons(t1);
            return_value = compare(t1->sons, t2->sons);
        }else if(t2->sons == NULL && t2->value != -1 && t1->sons != NULL){
            //cout << "- Mixed types, convert right to [" << t2->value << "] and retry" << endl; 
            add_sons(t2);
            return_value = compare(t1->sons, t2->sons);
        }else if(t1->sons == NULL && t1->value == -1 && t2->sons != NULL){
            //cout << "- Left side ran out of items, so inputs are in the right order" << endl;
            return_value = -1;
        }else if(t2->sons == NULL && t2->value == -1 && t1->sons != NULL){
            //cout << "- Right side ran out of items, so inputs are not in the right order" << endl;
            return_value = 1;
        }else if(t1->sons == NULL && t2->sons == NULL){
            if(t1->value != -1){
                //cout << "- Right side ran out of items, so inputs are in the right order" << endl;
                return_value = 1;
            }else if(t2->value != -1){
                //cout << "- Left side ran out of items, so inputs are not in the right order" << endl;
                return_value = -1;
            }else
                return_value = 0;
        }

        if(return_value == 0){
            if(t1->next != NULL && t2->next != NULL)
                return_value = compare(t1->next, t2->next);
            else if(t1->next != NULL && t2->next == NULL){
                //cout << "- Right side ran out of items, so inputs are not in the right order" << endl;
                return_value = 1;
            }else if(t1->next == NULL && t2->next != NULL){
                //cout << "- Left side ran out of items, so inputs are in the right order" << endl;
                return_value = -1;
            }else
                return_value = 0;
        }
            

        return return_value;
    }else if(t1 == NULL && t2 == NULL)
        return 0;
    else if(t1 == NULL)
        return -1;
    else
        return 1;
}

void print(tree t){
    if(t != NULL){
        if(t->sons != NULL){
            cout << "[";
            print(t->sons);
        }

        if(t->value != -1)
            cout << t->value;

        if(t->next != NULL){
            cout << ',';
            print(t->next);
        }else if(t->father != NULL){
            cout << ']';
        }
    }
}