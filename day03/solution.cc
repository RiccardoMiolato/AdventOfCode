#include <iostream>
#include <fstream>

using namespace std;

int get_lenght(const char *);
int get_prioritize();
int get_value(char c);
bool is_present(const char *, char);

int main(){
    int sum = get_prioritize();
    
    cout << "The answer to part 1 is " << sum << endl;
    return 0;
}

int get_prioritize(){
    fstream stream;
    char buffer[256];
    bool present;
    int len;
    int sum = 0;
    stream.open("mypuzzle.txt", ios::in);

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
