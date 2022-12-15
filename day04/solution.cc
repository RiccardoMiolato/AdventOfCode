#include <iostream>
#include <fstream>

using namespace std;

const char *filename = "test.txt";

int count_fully_contained(int &overlapped);
bool is_contained(int startA, int endA, int startB, int endB);
bool is_overlapped(int startA, int endA, int startB, int endB);

int main(){
    int overlaps = 0;
    int fully_contained = count_fully_contained(overlaps);
    
    cout << "The answer to part 1 is " << fully_contained << endl;
    cout << "The answer to part 2 is " << overlaps << endl;
    return 0;
}

int count_fully_contained(int &overlaps){
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


                if(is_overlapped(indexes[0], indexes[1], indexes[2], indexes[3])){
                    overlaps++;
                    cout << "(Overlaps)";
                    if(is_contained(indexes[0], indexes[1], indexes[2], indexes[3])){
                        cout << "-(Fully contained)";
                        total++;
                    }
                    cout << endl;
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

bool is_overlapped(int startA, int endA, int startB, int endB){
    if((startB >= startA && startB <= endA) || (endB >= startA && endB <= endA))
        return true;
    else if((startA >= startB && startA <= endB) || (endA >= startB && endA <= endB))
        return true;
    else
        return false;
}