#include <iostream>
#include <cstring>
#include "list.h"
#include "tree.h"

using namespace std;

const int DISK_SPACE = 70000000;

void init(fileSystem &root){
    root = new folder;
    root->name = "root";
    root->folders = NULL;
    root->father = NULL;
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
        new_folder->father = _folder;
        init(new_folder->files);
        new_folder->next = NULL;

        if(ptr == NULL){
            _folder->folders = new_folder;
        }else{
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

        cout << '/' << root->name << "  (" << get_folder_size(root) << ')';
        
        /*  for debugging info
        cout << "   folders:" << ((root->folders != NULL) ? "true" : "false");
        cout << "   father:" << ((root->father != NULL) ? "true" : "false");
        cout << "   next:" << ((root->next != NULL) ? "true" : "false");
        */

        cout << endl;

        if(root->files != NULL)
            print_list(root->files, level + 1);

        if(root->folders != NULL)
            print_filesystem(root->folders, level + 1);
        
        if(root->next != NULL)
            print_filesystem(root->next, level);
    }
}

void print_folder(fileSystem &root){
    if(root != NULL){
        cout << '/' << root->name << "  (" << get_folder_size(root) << ')' << endl;

        if(root->files != NULL)
            print_list(root->files, 1);

        if(root->folders != NULL)
            print_filesystem(root->folders, 1);
    }
}

fileSystem get_folder_by_name(fileSystem &root, char *name){
    if(root != NULL){
        if(strcmp(root->name, name) == 0){
            return root;
        }else{
            fileSystem tmp = NULL;

            if(root->next != NULL){
                tmp = get_folder_by_name(root->next, name);
                if(tmp != NULL)
                    return tmp;
            }
        }    
    }

    return NULL;
}

int get_folder_size(fileSystem &root){
    int size = 0;

    if(root->files != NULL)
        size += get_files_size(root->files);

    if(root->folders != NULL){
        fileSystem ptr = root->folders;
        while (ptr != NULL)
        {
            size += get_folder_size(ptr);
            ptr = ptr->next;
        }
    }

    return size;
}

int get_answer_problem_1(fileSystem &root){
    int total = 0, size = 0;

    if(root != NULL){
        fileSystem ptr = root;
        size = get_folder_size(ptr);

        if(size <= 100000)
            total += size;

        if(ptr->folders != NULL){
            ptr = ptr->folders;

            while(ptr != NULL){
                total += get_answer_problem_1(ptr);
                ptr = ptr->next;
            }
        }
    }

    return total;
}

int recursive_solution(fileSystem root, int space_to_be_clear, int min_size_folder_available){
    int size = get_folder_size(root);

    if(size >= space_to_be_clear && size <= min_size_folder_available)
        min_size_folder_available = size;
    
    if(root->folders != NULL)
        min_size_folder_available = recursive_solution(root->folders, space_to_be_clear, min_size_folder_available);

    if(root->next != NULL)
        min_size_folder_available = recursive_solution(root->next, space_to_be_clear, min_size_folder_available);

    return min_size_folder_available;
}

int get_answer_problem_2(fileSystem &root){
    if(root != NULL){
        fileSystem ptr = root;
        int size = get_folder_size(ptr);
        int free_space = DISK_SPACE - size;
        int space_to_be_clear = 30000000 - free_space;
        int min_size_folder_available = DISK_SPACE - free_space;

        return recursive_solution(root, space_to_be_clear, min_size_folder_available);
    }

    return -1;
}
