#include <iostream>
#include <fstream>
#include "queue.h"
#include "bfs.h"

using namespace std;

const char *filename = "mypuzzle.txt";

int ** get_map(int &row, int &col, int &startx, int &starty, int &finishx, int &finishy);
void get_rows_cols(int &row, int &col);
void print_map(int **map, int row, int col);
int get_lowest_path(int **map, int row, int col, int finishx, int finishy);

int main(){
    int **map;
    int row, col, startx, starty, finishx, finishy;
    map = get_map(row, col, startx, starty, finishx, finishy);

    init_bfs(row, col);
    cout << "Part 1 solution" << endl;
    int path_lenght = bfs(map, startx, starty, finishx, finishy);

    if(path_lenght == -1)
        cout << "Path not found" << endl;
    else
        cout << "Steps = " << path_lenght << endl;

    cout << "Part 2 solution" << endl;
    path_lenght = get_lowest_path(map, row, col, finishx, finishy);

    if(path_lenght == -1)
        cout << "Path not found" << endl;
    else
        cout << "Lowest path = " << path_lenght << endl;
    return 0;
}

int ** get_map(int &row, int &col, int &startx, int &starty, int &finishx, int &finishy){
    fstream stream;
    int **map;
    char buffer[128];
    get_rows_cols(row, col);
    cout << "row: " << row <<  "    col: " << col << endl;
    map = new int*[row];
    stream.open(filename, ios:: in);

    if(!stream.fail()){
        int line = 0;
        while(stream >> buffer){
            map[line] = new int[col];

            for(int i = 0; buffer[i] != '\0'; i++){
                if(buffer[i] == 'S'){
                    startx = line;
                    starty = i;
                    buffer[i] = 'a';
                } else if(buffer[i] == 'E'){
                    finishx = line;
                    finishy = i;
                    buffer[i] = 'z';
                }

                map[line][i] = (int)(buffer[i] - 'a');
            }
            line++;
        }
    }else
        cout << "Error opening file|\n";

    stream.close();

    return map;
}

void get_rows_cols(int &row, int &col){
    row = 0;
    col = 0;
    
    fstream stream;
    char buffer[128];
    bool have_cols = false;
    stream.open(filename, ios:: in);

    if(!stream.fail()){
        while(stream >> buffer){
            row++;
            for(int i = 0; buffer[i] != '\0' && !have_cols; i++){
                col++;
            }
            if(!have_cols)
                have_cols = true;
        }
    }else
        cout << "Error opening file|\n";

    stream.close();
}

void print_map(int **map, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << '-' << map[i][j];

        cout << endl;
    }
}

int get_lowest_path(int **map, int row, int col, int finishx, int finishy){
    int min = INT_MAX;
    int curr_dist = -1;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++){
            reset_visited_matrix();
            if(map[i][j] == 0){
                curr_dist = bfs(map, i, j, finishx, finishy);

                if(curr_dist != -1 && curr_dist < min)
                    min = curr_dist;
            }
        }

    return min;
}
