#include <fstream>
#include <iostream>

using namespace std;

const char *FILENAME = "mypuzzle.txt";
int ** init_map(int &row, int &column);
void print_map(int **map, int row, int col);
int how_many_visible(int **matrix, int row, int col);
bool is_visible(int **matrix, int row, int col, int i, int j);

bool visible_top(int **matrix, int row, int col, int i, int j);
bool visible_bottom(int **matrix, int row, int col, int i, int j);
bool visible_left(int **matrix, int row, int col, int i, int j);
bool visible_right(int **matrix, int row, int col, int i, int j);

int how_many_top(int **matrix, int row, int col, int i, int j);
int how_many_bottom(int **matrix, int row, int col, int i, int j);
int how_many_left(int **matrix, int row, int col, int i, int j);
int how_many_right(int **matrix, int row, int col, int i, int j);

int max_how_many_visibles(int **matrix, int row, int col);

int lenght(char *string);
int file_lines();

int main(){
    int **matrix;
    int row, col;

    matrix = init_map(row, col);
    print_map(matrix, row, col);

    cout << "Visible trees: " << how_many_visible(matrix, row, col) << endl;
    cout << "The tree where you can see most trees shows " << max_how_many_visibles(matrix, row, col) << " trees" << endl;

    return 0;
}

int ** init_map(int &row, int &column){
    int **matrix;
    fstream stream;
    char buffer[150];
    row = file_lines();
    matrix = new int*[row];

    stream.open(FILENAME, ios::in);

    if(!stream.fail()){
        for(int i = 0; i < row; i++){
            stream >> buffer;

            if(i == 0)
                column = lenght(buffer);

            matrix[i] = new int[column];
            for(int j = 0; j < column; j++){
                matrix[i][j] = buffer[j] - 48;
            }    
        }
    }else
        cout << "Error opening input file!" << endl;

    stream.close();

    return matrix;
}

int file_lines(){
    int lines = 0;
    fstream file;
    file.open(FILENAME, ios::in);
    char buffer[150];

    while (!file.eof())
    {
        if(file >> buffer)
            lines++;
    }

    file.close();
    return lines;
}

int lenght(char *string){
    int lenght = 0;

    for(int i = 0; string[i] != '\0'; i++)
        lenght++;

    return lenght;
}


void print_map(int **map, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++)
            cout << map[i][j];
    
        cout << endl;
    }
}

bool visible_tree(int **matrix, int row, int col, int i, int j){
    if(i == 0 || j == 0 || i == row - 1 || j == col - 1)
        return true;
    else{
        bool visible = false;

        if(visible_top(matrix, row, col, i, j) ||
            visible_bottom(matrix, row, col, i, j) ||
            visible_right(matrix, row, col, i, j) ||
            visible_left(matrix, row, col, i, j)){
                visible = true;
            }

        
        return visible;
    }
}

int how_many_visible(int **matrix, int row, int col){
    int count = 0;

    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            if(visible_tree(matrix, row, col, i, j))
                count++;

    return count;
}

bool visible_top(int **matrix, int row, int col, int i, int j){
    bool visible = true;

    for(int x = i - 1; x >= 0 && visible; x--)
        if(matrix[x][j] >= matrix[i][j])
            visible = false;

    return visible;
}

bool visible_bottom(int **matrix, int row, int col, int i, int j){
    bool visible = true;

    for(int x = i + 1; x < row && visible; x++)
        if(matrix[x][j] >= matrix[i][j])
            visible = false;

    return visible;    
}

bool visible_left(int **matrix, int row, int col, int i, int j){
    bool visible = true;

    for(int x = j - 1; x >= 0 && visible; x--)
        if(matrix[i][x] >= matrix[i][j])
            visible = false;

    return visible;    
}

bool visible_right(int **matrix, int row, int col, int i, int j){
    bool visible = true;

    for(int x = j + 1; x < col && visible; x++)
        if(matrix[i][x] >= matrix[i][j])
            visible = false;

    return visible;    
}

int how_many_top(int **matrix, int row, int col, int i, int j){
    int visible = 0;

    for(int x = i - 1; x >= 0; x--)
        if(matrix[x][j] < matrix[i][j])
            visible++;
        else{
            visible++;
            break;
        }

    //cout << "t: "  << visible << endl;
    return visible;    
}

int how_many_bottom(int **matrix, int row, int col, int i, int j){
    int visible = 0;

    for(int x = i + 1; x < row; x++)
        if(matrix[x][j] < matrix[i][j])
            visible++;
        else{
            visible++;
            break;
        }

    //cout << "b: "  << visible << endl;
    return visible;  
}

int how_many_left(int **matrix, int row, int col, int i, int j){
    int visible = 0;

    for(int x = j - 1; x >= 0; x--)
        if(matrix[i][x] < matrix[i][j])
            visible++;
        else{
            visible++;
            break;
        }

    //cout << "l: "  << visible << endl;
    return visible;  
}

int how_many_right(int **matrix, int row, int col, int i, int j){
    int visible = 0;

    for(int x = j + 1; x < col; x++)
        if(matrix[i][x] < matrix[i][j])
            visible++;
        else{
            visible++;
            break;
        }

    //cout << "r: "  << visible << endl;
    return visible;
}

int max_how_many_visibles(int **matrix, int row, int col){
    int max = 0, tmp = 0;

    for(int i = 1; i < row - 1; i++)
        for(int j = 1; j < col - 1; j++){
            //cout << endl << i << "  " << j << endl;
            tmp = how_many_top(matrix, row, col, i, j) * how_many_bottom(matrix, row, col, i, j) *
                     how_many_left(matrix, row, col, i, j) * how_many_right(matrix, row, col, i, j);

            if(tmp > max)
                max = tmp;
        }

    return max;
}
