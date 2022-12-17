#include <iostream>
#include <fstream>
#include <cstring>
#include "list.h"
#include "caveSystem.h"

using namespace std;

const char *filename = "mypuzzle.txt";

void build_caveSystem();
void add_positions(char *string);

int main(){
    build_caveSystem();

    initCave();
    printCave();

    int answer1 = sandFall();
    cout << "Falling sands" << endl;
    printCave();

    expandCave();
    printCave();

    int answer2 = answer1 + 1 + sandFall();
    cout << "Falling sands" << endl;
    printCave();

    cout << "\nAnswer part 1 is " << answer1 << " sand units" << endl;
    cout << "\nAnswer part 2 is " << answer2 << " sand units" << endl;
    deinitCave();
    
    return 0;
}

void build_caveSystem(){
    fstream stream;
    char buffer[512];
    stream.open(filename, ios::in);

    init();

    if(!stream.fail()){
        while(!stream.eof()){
            stream.getline(buffer, 512);
            if(strlen(buffer) > 0){
                add_rock();
                add_positions(buffer);
            }
        }
    }else   
        cout << "Error opening the file" << endl;

    stream.close();
}

void add_positions(char *string){
    int x = 0, y = 0;
    bool modifyx = true;

    for(int i = 0; string[i] != '\0'; i++){
        if(string[i] == ' ' && string[i + 1] == '-'){
            add_coordinates(x,y);
            x = 0;
            y = 0;
            modifyx = true;
        }else if(string[i] == ',')
            modifyx = false;
        else if(string[i] != '>' && string[i] != ' ' && string[i] != '-'){
            if(modifyx){
                x = x * 10 + string[i] - '0';
            }else
                y = y * 10 + string[i] - '0';
        }
    }

    add_coordinates(x, y);
}