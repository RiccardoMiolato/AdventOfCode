#include <iostream>
#include <fstream>
#include "stack.h"

using namespace std;

/*
Test
    [D]    
[N] [C]    
[Z] [M] [P]
 1   2   3 

Problem
[T]     [Q]             [S]        
[R]     [M]             [L] [V] [G]
[D] [V] [V]             [Q] [N] [C]
[H] [T] [S] [C]         [V] [D] [Z]
[Q] [J] [D] [M]     [Z] [C] [M] [F]
[N] [B] [H] [N] [B] [W] [N] [J] [M]
[P] [G] [R] [Z] [Z] [C] [Z] [G] [P]
[B] [W] [N] [P] [D] [V] [G] [L] [T]
 1   2   3   4   5   6   7   8   9 
 */
char *filename = "test.txt";

void move_from_to(stack &from, stack &to);
void read_file_part1(stack stacks[]);
void read_file_part2(stack stacks[]);

int main(){
    bool test = false; // test case or not
    int dim;

    if(test){
        dim = 3;
        filename = "test.txt";
    }else{
        dim = 9;
        filename = "mypuzzle.txt";
    }

    stack stacks[dim];

    for(int i = 0; i < dim; i++)
        init(stacks[i]);

    if(test){
        push(stacks[0], 'Z');
        push(stacks[0], 'N');

        push(stacks[1], 'M');
        push(stacks[1], 'C');
        push(stacks[1], 'D');

        push(stacks[2], 'P');
    }else{
        push(stacks[0], 'B');
        push(stacks[0], 'P');
        push(stacks[0], 'N');
        push(stacks[0], 'Q');
        push(stacks[0], 'H');
        push(stacks[0], 'D');
        push(stacks[0], 'R');
        push(stacks[0], 'T');

        push(stacks[1], 'W');
        push(stacks[1], 'G');
        push(stacks[1], 'B');
        push(stacks[1], 'J');
        push(stacks[1], 'T');
        push(stacks[1], 'V');

        push(stacks[2], 'N');
        push(stacks[2], 'R');
        push(stacks[2], 'H');
        push(stacks[2], 'D');
        push(stacks[2], 'S');
        push(stacks[2], 'V');
        push(stacks[2], 'M');
        push(stacks[2], 'Q');

        push(stacks[3], 'P');
        push(stacks[3], 'Z');
        push(stacks[3], 'N');
        push(stacks[3], 'M');
        push(stacks[3], 'C');

        push(stacks[4], 'D');
        push(stacks[4], 'Z');
        push(stacks[4], 'B');

        push(stacks[5], 'V');
        push(stacks[5], 'C');
        push(stacks[5], 'W');
        push(stacks[5], 'Z');

        push(stacks[6], 'G');
        push(stacks[6], 'Z');
        push(stacks[6], 'N');
        push(stacks[6], 'C');
        push(stacks[6], 'V');
        push(stacks[6], 'Q');
        push(stacks[6], 'L');
        push(stacks[6], 'S');

        push(stacks[7], 'L');
        push(stacks[7], 'G');
        push(stacks[7], 'J');
        push(stacks[7], 'M');
        push(stacks[7], 'D');
        push(stacks[7], 'N');
        push(stacks[7], 'V');

        push(stacks[8], 'T');
        push(stacks[8], 'P');
        push(stacks[8], 'M');
        push(stacks[8], 'F');
        push(stacks[8], 'Z');
        push(stacks[8], 'C');
        push(stacks[8], 'G');
    }

    read_file_part1(stacks);

    cout << "Solution to part 1 is: ";
    for(int i = 0; i < dim; i++){
        cout << stacks[i]->letter;
        deinit(stacks[i]);
    }
    cout << endl;

    for(int i = 0; i < dim; i++)
        init(stacks[i]);

    if(test){
        push(stacks[0], 'Z');
        push(stacks[0], 'N');

        push(stacks[1], 'M');
        push(stacks[1], 'C');
        push(stacks[1], 'D');

        push(stacks[2], 'P');
    }else{
        push(stacks[0], 'B');
        push(stacks[0], 'P');
        push(stacks[0], 'N');
        push(stacks[0], 'Q');
        push(stacks[0], 'H');
        push(stacks[0], 'D');
        push(stacks[0], 'R');
        push(stacks[0], 'T');

        push(stacks[1], 'W');
        push(stacks[1], 'G');
        push(stacks[1], 'B');
        push(stacks[1], 'J');
        push(stacks[1], 'T');
        push(stacks[1], 'V');

        push(stacks[2], 'N');
        push(stacks[2], 'R');
        push(stacks[2], 'H');
        push(stacks[2], 'D');
        push(stacks[2], 'S');
        push(stacks[2], 'V');
        push(stacks[2], 'M');
        push(stacks[2], 'Q');

        push(stacks[3], 'P');
        push(stacks[3], 'Z');
        push(stacks[3], 'N');
        push(stacks[3], 'M');
        push(stacks[3], 'C');

        push(stacks[4], 'D');
        push(stacks[4], 'Z');
        push(stacks[4], 'B');

        push(stacks[5], 'V');
        push(stacks[5], 'C');
        push(stacks[5], 'W');
        push(stacks[5], 'Z');

        push(stacks[6], 'G');
        push(stacks[6], 'Z');
        push(stacks[6], 'N');
        push(stacks[6], 'C');
        push(stacks[6], 'V');
        push(stacks[6], 'Q');
        push(stacks[6], 'L');
        push(stacks[6], 'S');

        push(stacks[7], 'L');
        push(stacks[7], 'G');
        push(stacks[7], 'J');
        push(stacks[7], 'M');
        push(stacks[7], 'D');
        push(stacks[7], 'N');
        push(stacks[7], 'V');

        push(stacks[8], 'T');
        push(stacks[8], 'P');
        push(stacks[8], 'M');
        push(stacks[8], 'F');
        push(stacks[8], 'Z');
        push(stacks[8], 'C');
        push(stacks[8], 'G');
    }

    read_file_part2(stacks);

    cout << "Solution to part 2 is: ";
    for(int i = 0; i < dim; i++){
        cout << stacks[i]->letter;
        deinit(stacks[i]);
    }
    cout << endl;

    return 0;
}

void read_file_part1(stack stacks[]){
    fstream stream;
    char buffer[32];
    int quantity, from, to;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        while(stream >> buffer){
            stream >> buffer;
            quantity = stoi(buffer);
            stream >> buffer;
            stream >> buffer;
            from = stoi(buffer) - 1;
            stream >> buffer;
            stream >> buffer;
            to = stoi(buffer) - 1;

            for(int i = 0; i < quantity; i++)
                move_from_to(stacks[from], stacks[to]);
        }
    }
    else
        cout << "Error opening file!" << endl; 

    stream.close();
}

void read_file_part2(stack stacks[]){
    fstream stream;
    char buffer[32];
    int quantity, from, to;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        stack tmp;
        init(tmp);

        while(stream >> buffer){
            stream >> buffer;
            quantity = stoi(buffer);
            stream >> buffer;
            stream >> buffer;
            from = stoi(buffer) - 1;
            stream >> buffer;
            stream >> buffer;
            to = stoi(buffer) - 1;

            for(int i = 0; i < quantity; i++)
                move_from_to(stacks[from], tmp);

            for(int i = 0; i < quantity; i++)
                move_from_to(tmp, stacks[to]);
        }
    }
    else
        cout << "Error opening file!" << endl; 

    stream.close();
}

void move_from_to(stack &from, stack &to){
    stack tmp = pop(from);
    push(to, tmp);
}