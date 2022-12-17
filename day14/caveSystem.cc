#include <iostream>
#include "list.h"
#include "caveSystem.h"

using namespace std;

int **caveMap; // 0 air, 1 rock, 2 sand, 3 sandStart
int rows;
int cols;
int diffX;

void initCave(){
    int minX, maxX, minY, maxY;
    get_matrix_dimensions(maxX, minX, maxY, minY);
    rows = maxY + 1;
    cols = maxX - minX + 2;
    diffX = minX - 1;

    /*
        FOR DEBUGGING
    cout << "Rows: " << rows << endl;
    cout << "Cols: " << cols << endl;
    cout << "Diffx: " << diffX << endl;
    */

    caveMap = new int*[rows];
    for(int i = 0; i < rows; i++){
        caveMap[i] = new int[cols];

        for(int j = 0; j < cols; j++){
            caveMap[i][j] = 0;
        }
    }

    caveMap[0][500 - diffX] = 3;
    addRocks();
}

void addRocks(){
    cave tmp = get_head();

    while(tmp != NULL){
        pointList points = tmp->positions;

        if(points != NULL)
            caveMap[points->y][points->x - diffX] = 1;

        while(points->next != NULL){
            if(points->x == points->next->x){
                if(points->y < points->next->y){
                    for(int i = points->y + 1; i <= points->next->y; i++)
                        caveMap[i][points->x - diffX] = 1;
                }else{
                    for(int i = points->y - 1; i >= points->next->y; i--)
                        caveMap[i][points->x - diffX] = 1;
                }
            }else if(points->y == points->next->y){
                if(points->x < points->next->x){
                    for(int i = points->x + 1; i <= points->next->x; i++)
                        caveMap[points->y][i - diffX] = 1;
                }else{
                    for(int i = points->x - 1; i >= points->next->x; i--)
                        caveMap[points->y][i - diffX] = 1;
                }
            }


            
            points = points->next;
        }
        tmp = tmp->next;
    }
}

void printCave(){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            switch(caveMap[i][j]){
                case 0:
                    cout << '.';
                    break;
                case 1:
                    cout << '#';
                    break;
                case 2:
                    cout << 'o';
                    break;
                case 3:
                    cout << '+';
                    break;
            }
        }
        cout << "  " << i << endl;
    }
    
}

bool recursiveSandFall(int y, int x){
    if(y + 1 == rows)
        return false;

    if(caveMap[y + 1][x] == 0)
        return recursiveSandFall(y + 1, x);
    else if(caveMap[y + 1][x - 1] == 0)
        return recursiveSandFall(y + 1, x - 1);
    else if(caveMap[y + 1][x + 1] == 0)
        return recursiveSandFall(y + 1, x + 1);
    else{
        caveMap[y][x] = 2;
        return true;
    }
}

int sandFall(){
    int sandunits = 0;

    while(recursiveSandFall(0, 500 - diffX)){
        sandunits++;
        cout << endl << "Sands = " << sandunits << endl;
    }

    return sandunits;
}

void deinitCave(){
    for(int i = 0; i < rows; i++)
        delete[] caveMap[i];
    
    delete caveMap;
}
