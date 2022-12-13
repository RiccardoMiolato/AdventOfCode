#include <iostream>
#include "queue.h"
#include "bfs.h"

using namespace std;

static bool **visited_map;
static int rows;
static int cols;

void init_bfs(int _rows, int _cols){
    rows = _rows;
    cols = _cols;

    visited_map = new bool*[rows];

    for(int i = 0; i < rows; i++){
        visited_map[i] = new bool[cols];

        for(int j = 0; j < cols; j++)
            visited_map[i][j] = false;
    }    
}


bool isValid(int row, int col){
    return (row >= 0) && (col >= 0) && (row < rows) && (col < cols);
}

int bfs(int **map, int startx, int starty, int endx, int endy){
    int rowNum[] = {-1, 0, 0, 1};
    int colNum[] = {0, -1, 1, 0};
    int rowtmp, coltmp;

    cout << "Start position: (" << startx << "," << starty << ")" << endl;
    cout << "Finish position: (" << endx << "," << endy << ")" << endl;

    if(!(map[startx][starty] == 0) || !(map[endx][endy] == ('z' - 'a')))
        return -1;

    visited_map[startx][starty] = true; // set start position as visited
    init(); // init queue

    enqueue(startx, starty, 0);

    while(!empty()){
        linkedList curr = first_el();

        if(curr->x == endx && curr->y == endy){
            int dist = curr->dist;
            deinit();
            return dist;
        }
        
        dequeue();

        for(int i = 0; i < 4; i++){
            rowtmp = curr->x + rowNum[i];
            coltmp = curr->y + colNum[i];

            if(isValid(rowtmp, coltmp) &&
                map[rowtmp][coltmp] <= map[curr->x][curr->y] + 1 &&
                !visited_map[rowtmp][coltmp])
            {
                visited_map[rowtmp][coltmp] = true;
                enqueue(rowtmp, coltmp, curr->dist + 1);
            }
        }
    }

    return -1;
}

void reset_visited_matrix(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++)
            visited_map[i][j] = false;
    }   
}
