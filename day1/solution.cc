#include <iostream>
#include <fstream>

using namespace std;

int get_max_calories(const char *filename);
int lenght(const char *);

int main(){
    int max = get_max_calories("mypuzzle.txt");

    cout << "The max is " << max << endl;

    return 0;
}

int get_max_calories(const char *filename){
    fstream stream;
    char *buffer = new char[7];

    int max = 0;
    int sum = 0;

    stream.open(filename, ios::in);

    if(stream.fail())
        cout << "Error opening file!" << endl;
    else{
        while(!stream.eof()){
            stream.getline(buffer, 7);
            if(lenght(buffer) == 0){
                if(sum > max)
                    max = sum;
                
                cout << "Total: " << sum << endl;
                sum = 0;
            }else
                sum += atoi(buffer);
        }
        if(sum > max){
            max = sum;
            sum = 0;
        }
    }

    stream.close();

    return max;
}

int lenght(const char *string){
    cout << "   \"" << string << '"';
    int count = 0;

    while(string[count] != '\0')
        count++;
    
    cout << "   lenght = " << count << endl;
    return count;
}
