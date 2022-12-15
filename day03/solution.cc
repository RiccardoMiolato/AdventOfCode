#include <iostream>
#include <fstream>

using namespace std;

const char *filename = "mypuzzle.txt";

int get_lenght(const char *);
int get_prioritize();
int get_group_prioritize();
int get_value(char c);
bool is_present(const char *, char);

int main(){
    int sum = get_prioritize();
    int sum2 = get_group_prioritize();
    
    cout << "The answer to part 1 is " << sum << endl;
    cout << "The answer to part 2 is " << sum2 << endl;
    return 0;
}

int get_prioritize(){
    fstream stream;
    char buffer[256];
    bool present;
    int len;
    int sum = 0;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        while(!stream.eof()){
            stream.getline(buffer, 256);
            len = get_lenght(buffer);
            cout << buffer << " - " << len;

            present = false;
            for(int i = 0; i < len / 2 && !present; i++)
                if(is_present(buffer + (len / 2), buffer[i])){
                    present = true;
                    cout << " - " << buffer[i] << " : " << get_value(buffer[i]);
                    sum += get_value(buffer[i]);
                }
            
            cout << endl;
        }
    }

    stream.close();
    return sum;
}

int get_group_prioritize(){
    fstream stream;
    char **buffer = new char*[3];
    for(int i = 0; i < 3; i++)
        buffer[i] = new char[256];
    bool present;
    int len;
    int sum = 0, index = 0;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        while(!stream.eof()){
            cout << "In" << endl;
            while(index < 3 && stream >> buffer[index]){
                if(index == 0)
                    len = get_lenght(buffer[index]);

                index++;
            }
            cout << "Out" << endl;

            present = false;
            for(int i = 0; i < len && !present && index == 3; i++)
                if(is_present(buffer[1], buffer[0][i]) && is_present(buffer[2], buffer[0][i])){
                    present = true;
                    cout << " - " << buffer[0][i] << " : " << get_value(buffer[0][i]);
                    sum += get_value(buffer[0][i]);
                }
            
            cout << " --> " << sum << endl;
            index = 0;
        }
    }

    for(int i = 0; i < 3; i++)
        delete[] buffer[i];

    delete buffer;

    stream.close();
    return sum;
}

int get_lenght(const char *string){
    int count = 0;

    for(int i = 0; string[i] != '\0'; i++)
        count++;

    return count;
}

bool is_present(const char *string, char c){
    if(string[0] != '\0'){
        if(string[0] == c)
            return true;
        else
            return is_present(string + 1, c);
    }
    
    return false;
}

int get_value(char c){
    if(c <= 'Z' && c >= 'A')
        return (c - 'A' + 27);
    else
        return (c - 'a' + 1);
}
