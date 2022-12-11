#ifndef TREE_H
#define TREE_H
#include "list.h"

struct folder{
    char *name;
    fileList files;
    folder* folders; //folders inside main folder
    folder* father;
    folder* next; //linked list of folders
};
typedef folder* fileSystem;

//my library function
void init(fileSystem &root);
void deinit(fileSystem &root);
fileSystem add_folder(fileSystem &_folder, char *name);
fileSystem get_folder_by_name(fileSystem &root, char *name);
void print_filesystem(fileSystem &root, int level);
void print_folder(fileSystem &root);
int get_folder_size(fileSystem &root);

//return the result to the part 1 of the problem
int get_answer_problem_1(fileSystem &root);

#endif