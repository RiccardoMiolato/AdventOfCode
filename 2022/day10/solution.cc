#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void find_register_values();
void inrease_cycle(int &cycle, int value, int &strength);

int main(){
    find_register_values();

    return 0;
}

void find_register_values(){
    fstream stream;
    stream.open("mypuzzle.txt", ios::in);
    int current_cycle = 0;
    int v = 1, strenght = 0;
    char buffer[15];
    
    if(!stream.fail()){
        while(stream >> buffer){
            if(strcmp(buffer, "noop") == 0)
                inrease_cycle(current_cycle, v, strenght);
            else{
                inrease_cycle(current_cycle, v, strenght);
                inrease_cycle(current_cycle, v, strenght);

                stream >> buffer;
                v += stoi(buffer);
            }
        }
    }else
        cout << "Error opening input file!" << endl;

    cout << "Total strenght is " << strenght << endl;

    stream.close();
}

void inrease_cycle(int &cycle, int value, int &strength){
    cycle += 1;

    //part 1
    if(cycle == 20 || (cycle - 20) % 40 == 0)
        strength += cycle * value;

    //part 2
    int index = cycle - 1;

    if(index % 40 >= value - 1 && index % 40 <= value + 1)
        cout << '#';
    else 
        cout << '.';

    if(cycle % 40 == 0) 
        cout << endl;
}