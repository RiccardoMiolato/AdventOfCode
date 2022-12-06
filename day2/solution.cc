#include <iostream>
#include <fstream>

using namespace std;

int match(char opponent1, char opponent2); //return the total score for the second opponent

int main(){
    fstream stream;
    int score = 0;
    stream.open("mypuzzle.txt");

    if(!stream.fail()){
        char buffer1[2], buffer2[2];
        int i = 1;
        while(!stream.eof()){
            if(stream >> buffer1 && stream >> buffer2){
                score += match(buffer1[0], buffer2[0]);
                cout <<  i++ << " - Your score will be " << score << endl;
            }
        }
        
        cout << "Your score will be " << score << endl;
    }

    stream.close();
    return 0;
}

int match(char opponent1, char opponent2){
    int score = 0;

    switch(opponent2){
        case 'X':
            score += 1;

            if(opponent1 == 'A')
                score += 3;
            else if(opponent1 == 'C')
                score += 6;
            break;
        case 'Y':
            score += 2;

            if(opponent1 == 'B')
                score += 3;
            else if(opponent1 == 'A')
                score += 6;
            break;
        case 'Z':
            score += 3;

            if(opponent1 == 'C')
                score += 3;
            else if(opponent1 == 'B')
                score += 6;
            break;
    }

    return score;
}
