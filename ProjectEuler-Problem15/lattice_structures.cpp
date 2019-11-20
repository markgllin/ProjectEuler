#include <iostream>

using namespace std;

//note: this is just Pascal's Triangle'

int main(){
    int gridSize = 21;

    double **grid = new double*[gridSize];

    //initilize columns
    for (int i = 0; i<gridSize; i++)
       grid[i] = new double[gridSize];
   
   //set boundary conditions
   for (int i = 0; i<gridSize; i++){
       grid[gridSize-1][i] = 1;
       grid[i][gridSize-1] = 1;
   }

   //sum possibilities
   for (int i = 1; i<gridSize; i++){
       for(int j = 1; j<gridSize; j++){
           grid[gridSize-1-i][gridSize-1-j] = grid[gridSize-1-i][gridSize-j] + grid[gridSize-i][gridSize-1-j];
           cout << "Coord: " << gridSize-1-i << "," << gridSize-1-j << " " << grid[gridSize-1-i][gridSize-1-j] << endl;
       }
   }
   cout << fixed;
   cout << grid[0][0] << endl;
}