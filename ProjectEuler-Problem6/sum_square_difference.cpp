#include <iostream>

using std::cout;

int main(){
    int squareOfSum=0, sumOfSquares=0;

    for (int i=1; i<=100; i++){
        squareOfSum += i;
        sumOfSquares += (i*i);
    }

    cout << "Answer: " << (squareOfSum*squareOfSum)-sumOfSquares << std::endl;
}