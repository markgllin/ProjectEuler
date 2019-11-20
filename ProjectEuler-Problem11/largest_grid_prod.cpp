#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int** readGrid(string file){
    int** grid = new int*[20];

    for(int i = 0; i<20; i++)
        grid[i]=new int[20];

    //open file containing grid
    ifstream inputFile;
    inputFile.open("grid.txt", ios::in);

    //read grid into 2D array
    for(int i = 0; i<20; i++)
        for (int j = 0; j<20; j++)
            inputFile >> grid[i][j];

    //close file
    inputFile.close();

    return grid;
}

double largestGridProduct_verticalHorizontal(int **grid, double answer, string dir){
    double product = 1;
    int row, col;

    for (int i = 0; i<20; i++){
        if (product>answer)
            answer = product;

        product = 1;

        for (int j = 0; j<20; j++){

            if (dir == "horizontal"){
                row = i;
                col = j;
            } else if (dir == "vertical"){
                row = j;
                col = i;
            }

            if (grid[row][col]!=0){
                product *= grid[row][col];

            }else{
                if (product > answer)
                    answer = product;

                product = 1;
            }
        }
    }

    return answer;

}

double largestGridProduct_diagonal(int **grid, double answer, string dir){
    int row, col;
    double product = 1;
    
    for (int i=19; i>=0; i--){
        cout << "product: " << product << endl;
        if (product > answer)
            answer = product;
        
        row = i;
        col = 0;
        product = 1;

        while (row!=20 && col !=20){
            if (grid[row][col]!=0){
                product *= grid[row++][col++];
            }else{
                cout << "product: " << product << endl;
                if (product>answer)
                    answer = product;
                
                product = 1;
                row++;
                col++;
            }
        }
    }

    return answer;
}

int main(){
    double answer = 1;

    int** grid = readGrid("grid.txt");
    
    answer = largestGridProduct_verticalHorizontal(grid, answer, "horizontal");
    answer = largestGridProduct_verticalHorizontal(grid, answer, "vertical");

    double test = largestGridProduct_diagonal(grid, 1, "diag");

    cout << fixed;
    cout << "Answer: " << answer << endl;
    cout << "diag : " << test << endl;
    return 0;
}