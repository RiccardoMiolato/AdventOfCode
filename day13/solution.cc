#include <iostream>
#include <fstream>
#include <cstring>
#include "tree.h"

using namespace std;

int read_file();
void build_tree(tree &, const char *);

const char *filename = "mypuzzle.txt";

int main(){
    int sum_ordered_indexes = read_file();

    cout << "Answer to part 1 is " << sum_ordered_indexes << endl;
    return 0;
}

int read_file(){
    tree root1, root2;
    fstream stream;
    char buffer1[256];
    char buffer2[256];
    int line = 1, index_sum = 0;
    stream.open(filename, ios::in);

    if(!stream.fail()){
        while(!stream.eof()){
            stream.getline(buffer1, 256);
            if(strlen(buffer1) == 0 && !stream.eof())
                stream.getline(buffer1, 256);
            else if(stream.eof())
                break;

            stream.getline(buffer2, 256);
            
            init(root1);
            init(root2);

            build_tree(root1, buffer1);
            build_tree(root2, buffer2);

            cout << "== Pair " << line << " ==";
            int cmp = compare(root1, root2);
            if(cmp == 1){
                cout << " WRONG ORDER" << endl;
                cout << '\t' << buffer1 << endl;
                cout << '\t' << buffer2 << endl;
            }else{
                cout << " RIGHT ORDER " << endl;
                cout << '\t' << buffer1 << endl;
                cout << '\t' << buffer2 << endl;
                cout << "  Sum = " << index_sum << '+' << line << " = " << (index_sum + line) << endl; 
                index_sum += line;
            }
            cout << endl;
            deinit(root1);
            deinit(root2);

            line++;
        }
    }
    else
        cout << "Error opening file!" << endl; 

    stream.close();
    return index_sum;
}

void build_tree(tree &root, const char *string){
    if(root != NULL){
        tree tmp = root;
        int number = -1;
        bool prev_close_bracket = false;

        for(int i = 0; string[i] != '\0'; i++){
            if(string[i] == '['){
                add_sons(tmp);
                tmp = tmp->sons;                
                prev_close_bracket = false;
            }else if(string[i] == ']'){
                if(number != -1){
                    add_value(tmp, number);
                    number = -1;
                }
                tmp = tmp->father;
                prev_close_bracket = true;
            }else if(string[i] == ','){
                if(!prev_close_bracket){
                    add_value(tmp, number);
                    number = -1;
                }

                add_next(tmp);
                tmp = tmp->next;

                prev_close_bracket = false;
            }else{
                if(number == -1)
                    number = 0;
                
                number = 10 * number + string[i] - '0';
            }
        }
    }
}