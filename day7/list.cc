#include <iostream>
#include "list.h"

using namespace std;

void init(fileList &list){
    list = NULL;
}

void deinit(fileList &list){
    while(list != NULL){
        fileList tmp = list;
        list = list->next;
        delete tmp;
    }
}

void add_file(fileList &list, int size, char *name){
    fileList _file = new file;
    _file->name = name;
    _file->size = size;
    _file->next = NULL;

    fileList ptr = list;
    
    if(ptr == NULL)
        list = _file;
    else{
        while(ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = _file;
    }
}

int get_files_size(fileList &list){
    fileList ptr = list;
    int size = 0;

    while(ptr != NULL){
        size += ptr->size;
        ptr = ptr->next;
    }

    return size;
}

void print_list(fileList &list, int level){
    fileList ptr = list;

    while(ptr != NULL){
        for(int i = 0; i < level; i++)
            cout << "  ";

        cout << "-" << ptr->name << "   " << ptr->size << endl;
        ptr = ptr->next;
    }
}
