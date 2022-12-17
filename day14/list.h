#ifndef LIST_H
#define LIST_H

struct point
{
    int x;
    int y;
    point* next;
};
typedef point* pointList;

struct rock{
    pointList positions;
    rock* next;
};
typedef rock* cave;

void init();
void add_rock();
cave get_head();
void add_coordinates(int x, int y);
void get_matrix_dimensions(int &maxX, int &minX, int &maxY, int &minY);
void printRocks();
void deinit();

#endif