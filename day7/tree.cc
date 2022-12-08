#include <iostream>
#include "list.h"
#include "tree.h"

using namespace std;

void init(fileSystem &root){
    root = new folder;
    root->name = "root";
    init(root->files);
    root->next = NULL;
}


void deinit(fileSystem &root){
    
}

fileSystem add_folder(fileSystem &_folder, char *name){
    fileSystem new_folder = NULL;

    if(_folder != NULL){
        fileSystem ptr = _folder->folders;
        new_folder = new folder;

        new_folder->name = name;
        new_folder->folders = NULL;
        init(new_folder->files);
        new_folder->next = NULL;

        if(ptr == NULL)
            _folder->folders = new_folder;
        else{
            while(ptr->next != NULL)
                ptr = ptr->next;
            
            ptr->next = new_folder;
        }
    }
    
    return new_folder;
}

void print_filesystem(fileSystem &root, int level){
    if(root != NULL){
        for(int i = 0; i < level; i++){
            cout << "  ";
        }

        cout << '/' << root->name << endl;

        if(root->files != NULL)
            print_list(root->files, level + 1);

        if(root->folders != NULL)
            print_filesystem(root->folders, level + 1);
        
        if(root->next != NULL)
            print_filesystem(root->next, level);
    }
}

