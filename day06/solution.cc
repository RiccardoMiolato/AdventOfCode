#include <iostream>
#include <fstream>

using namespace std;

int get_first_marker(const char *string, int dim);//dim = buffer dimension
bool check_double(char buffer[], int dim);
int how_many(char buffer[], char letter, int dim);

int main(){
    char filename[] = "mypuzzle.txt";
    fstream stream;
    int index = -1, dim = 4;

    stream.open(filename, ios::in);

    if(stream.fail())
        cout << "Error!" << endl;
    else{
        char string[4097];
        while(stream >> string){
            //PART 1
            //start of packet detection
            dim = 4; 
            index = get_first_marker(string, dim);

            if(index == -1)
                cout << "The signal has not a start marker!" << endl;
            else
                cout << "The start of packet marker is in position " << index << '!' << endl;

            //PART 2
            //start of message detection
            dim = 14;
            index = get_first_marker(string, dim);

            if(index == -1)
                cout << "The signal has not a start marker!" << endl;
            else
                cout << "The start of message marker is in position " << index << '!' << endl;
        }
    }

    stream.close();

    return 0;
}

//return the index of marker requested
//  if dim = 4 start of packet
//  if dim = 14 start of message
int get_first_marker(const char *string, int dim){
    char buffer[dim];
    for(int i = 0; i < dim; i++)
        buffer[i] = ' ';

    for(int i = 1; string[i - 1] != '\0'; i++){
        buffer[(i - 1) % dim] = string[i - 1];
        
        if(!check_double(buffer, dim))
            return i;
    }

    return -1;
}

//check if a char is present twice in my buffer
bool check_double(char buffer[], int dim){
    for(int i = 0; i < dim; i++)
        if(buffer[i] == ' ' || how_many(buffer, buffer[i], dim) > 1)
            return true;

    return false;
}

//count how many occurs has a letter inside the buffer
int how_many(char buffer[], char letter, int dim){
    int counter = 0;

    for(int i = 0; i < dim; i++){
        if(buffer[i] == letter)
            counter++;
    }

    return counter;
}
