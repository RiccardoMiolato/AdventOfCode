#include <iostream>
#include <fstream>

using namespace std;

int get_max_calories(const char *filename, int &);
int lenght(const char *);

int main(){
    int top = 0;
    int max = get_max_calories("mypuzzle.txt", top);

    cout << "The max is " << top << endl;
    cout << "The total of first 3 elves is " << max << endl;

    return 0;
}

//read the input form file and return the total of first 3 elves
//more it has as reference the elves who carry more than other
int get_max_calories(const char *filename, int &top){
    fstream stream;
    char *buffer = new char[7];

    int max1 = 0, max2 = 0, max3 = 0;
    int sum = 0;

    stream.open(filename, ios::in);

    if(stream.fail())
        cout << "Error opening file!" << endl;
    else{
        while(!stream.eof()){
            stream.getline(buffer, 7);
            if(lenght(buffer) == 0){
                if(sum > max1){
                    max3 = max2;
                    max2 = max1;
                    max1 = sum;
                }else if(sum > max2){
                    max3 = max2;
                    max2 = sum;
                }else if(sum > max3){
                    max3 = sum;
                }

                sum = 0;
            }else
                sum += atoi(buffer);
        }

        if(sum > max1){
            max3 = max2;
            max2 = max1;
            max1 = sum;
        }else if(sum > max2){
            max3 = max2;
            max2 = sum;
        }else if(sum > max3){
            max3 = sum;
        }
    }

    stream.close();

    top = max1;
    cout << max1 << '+' << max2 << '+' << max3 << endl;
    return max1 + max2 + max3;
}

//return the lenght of a given string
int lenght(const char *string){
    int count = 0;

    while(string[count] != '\0')
        count++;

    return count;
}
