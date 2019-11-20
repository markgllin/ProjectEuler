#include <iostream>
using namespace std;

int main(){
    int num1 = 1, num2 = 1, temp, sum=0;

    while (num1 < 4000000){
        temp = num1;
        num1 += num2;
        num2 = temp;

        if (num1%2==0){
            sum += num1;
        }
    }

    cout << sum << "\n";
}
