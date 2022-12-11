#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "list.h"
#include "tree.h"

using namespace std;

void readFileSystem(fileSystem &);

int main(){
    fileSystem root;

    readFileSystem(root);

    print_filesystem(root, 0);

    cout << "Answer should be: " << get_answer_problem_1(root) << endl;

    return 0;
}

void readFileSystem(fileSystem &root){
    fstream stream;
    char buffer[20];
    fileSystem ptr;
    stream.open("mypuzzle.txt", ios::in);

    if(!stream.fail()){
        while(!stream.eof()){
            cout << line++ << endl;
            stream >> buffer;

            if(strcmp(buffer, "$") == 0){
                stream >> buffer;

                if(strcmp(buffer, "cd") == 0){
                    stream >> buffer;
                    if(strcmp(buffer, "/") == 0){
                        init(root);
                        ptr = root;
                    }else if(strcmp(buffer, "..") == 0){
                        ptr = ptr->father;
                    }else{
                        ptr = get_folder_by_name(ptr->folders, buffer);
                    }
                }
            }else if(strcmp(buffer, "dir") == 0){
                stream >> buffer;
                char *name = new char[20];
                strcpy(name, buffer);
                
                add_folder(ptr, name);
            }else{
                int size = atoi(buffer);
                stream >> buffer;
                char *name = new char[20];
                strcpy(name, buffer);

                add_file(ptr->files, size, name);
            }
        }
    }else{
        cout << "Fail opening file!" << endl;
    }

    stream.close();
}
