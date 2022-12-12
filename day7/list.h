#ifndef LISTA_H
#define LISTA_H

struct file{
    int size;
    char *name;
    file *next;
};
typedef file* fileList;


void init(fileList &list);
void deinit(fileList &list);
void add_file(fileList &list, int size, char *name);
int get_files_size(fileList &list);
void print_list(fileList &list, int level);

#endif