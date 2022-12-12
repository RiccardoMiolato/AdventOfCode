#include <iostream>
#include <fstream>
#include "rope.h"

using namespace std;

void move(head *&h, tail *&t, char dir, int steps);

int main(){
    fstream stream;
    head* h;
    tail* t;
    stream.open("mypuzzle.txt", ios::in);

    if(stream.fail()){
        cout << "Error opening file" << endl;
    }else{
        init(h, t);
        char buffer_dir[2];
        char buffer_steps[3];

        while(!stream.eof()){
            if(stream >> buffer_dir && stream >> buffer_steps){
                move(h, t, buffer_dir[0], stoi(buffer_steps));
            }
        }

        //cout << "HEAD:" << endl;
        //print_positions(h->nodes);
        cout << "TAIL:" << endl; 
        print_positions(t->nodes);
        cout << "Tail moved " << t->nNodesVisited << " times!" << endl;
    }

    stream.close();
    return 0;
}

void move(head *&h, tail *&t, char dir, int steps){
    nodeList h_pos;
    for(int i = 0; i < steps; i++){
        h_pos = get_last(h->nodes);
        switch(dir){
            case 'U':
                    move_head(h, t, h_pos->x + 1, h_pos->y);
                break;
            case 'D':
                    move_head(h, t, h_pos->x - 1, h_pos->y);
                break;
            case 'L':
                    move_head(h, t, h_pos->x, h_pos->y - 1);
                break;
            case 'R':
                    move_head(h, t, h_pos->x, h_pos->y + 1);
                break;
        }
    }
}