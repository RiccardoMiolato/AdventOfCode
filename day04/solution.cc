#include <iostream>
#include <fstream>

using namespace std;

const char *filename = "mypuzzle.txt";

int count_overlapping();
bool is_contained(int startA, int endA, int startB, int endB);

int main(){
    int total_overlaps = count_overlapping();
    
    cout << "The answer to part 1 is " << total_overlaps << endl;
    return 0;
}

int count_overlapping(){
    fstream stream;
    char buffer[16];
    int indexes[4] = {0,0,0,0}, index = 0;
    int total = 0;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        while(!stream.eof()){
            stream.getline(buffer, 16);

            if(buffer[0] != '\0'){
                for(int i = 0; buffer[i] != '\0'; i++){
                    if(buffer[i]  != '-' && buffer[i]  != ','){
                        indexes[index] = indexes[index] * 10 + (buffer[i] - '0');
                    }else
                        index++;
                }

                cout << indexes[0] << '-' << indexes[1] << endl;
                cout << indexes[2] << '-' << indexes[3] << endl;


                if(is_contained(indexes[0], indexes[1], indexes[2], indexes[3])){
                    cout << "SI" << endl;
                    total++;
                }

                cout << endl;

                for(int i = 0; i < 4; i++)
                    indexes[i] = 0;
                
                index = 0;
            }
        }
    }

    stream.close();
    return total;
}

bool is_contained(int startA, int endA, int startB, int endB){
    if(startA >= startB && endA <= endB)
        return true;
    else if(startB >= startA && endB <= endA)
        return true;
    else
        return false;
}
