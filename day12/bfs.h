#ifndef BFS_H
#define BFS_H

void init_bfs(int rows, int cols);
bool isValid(int row, int col);
int bfs(int **map, int startx, int starty, int endx, int endy);
void reset_visited_matrix();


#endif