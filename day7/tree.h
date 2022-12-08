#ifndef TREE_H
#define TREE_H
#include "list.h"

struct folder{
    char *name;
    fileList files;
    folder* folders; //folders inside main folder
    folder* next; //linked list of folders
};
typedef folder* fileSystem;

void init(fileSystem &root);
void deinit(fileSystem &root);
fileSystem add_folder(fileSystem &_folder, char *name);
void print_filesystem(fileSystem &root, int level);

#endif