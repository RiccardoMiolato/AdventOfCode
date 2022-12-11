#include <iostream>
#include <fstream>

using namespace std;

int match(char opponent1, char opponent2); //return the total score for the second opponent
int match_by_result(char opponent1, char result);

int main(){
    fstream stream;
    int score1 = 0, score2 = 0; //the first for the part 1 and the second for the part 2
    stream.open("mypuzzle.txt");

    if(!stream.fail()){
        char buffer1[2], buffer2[2];

        while(!stream.eof()){
            if(stream >> buffer1 && stream >> buffer2){
                score1 += match(buffer1[0], buffer2[0]);
                score2 += match_by_result(buffer1[0], buffer2[0]);
            }
        }
        
        cout << "Your score will be " << score1 << " if you read (X,Y,Z) as rock, paper and scissor" << endl;
        cout << "Your score will be " << score2 << " if you read (X,Y,Z) as lose, draw and win" << endl;
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

int match_by_result(char opponent1, char result){
    int res = 0;

    switch (result)
    {
        case 'X':
            if(opponent1 == 'A')
                res += match(opponent1, 'Z');
            else if(opponent1 == 'B')
                res += match(opponent1, 'X');
            else
                res += match(opponent1, 'Y');
            break;
        case 'Y':
            if(opponent1 == 'A')
                res += match(opponent1, 'X');
            else if(opponent1 == 'B')
                res += match(opponent1, 'Y');
            else
                res += match(opponent1, 'Z');
            break;
        case 'Z':
            if(opponent1 == 'A')
                res += match(opponent1, 'Y');
            else if(opponent1 == 'B')
                res += match(opponent1, 'Z');
            else
                res += match(opponent1, 'X');
            break;
    }

    return res;
}
