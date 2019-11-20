#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(double val){
    if (fmod(val, 2)==0) return false;

    for (int i=3; i<=sqrt(val); i+=2)
        if (fmod(val, i)==0) return false;

    return true;
}

int main(){
    double answer = 2;
    
    for (double i=3; i<2000000; i+=2)
        if(isPrime(i)) answer += i;

    cout <<fixed;
    cout << "Answer: " << answer << endl;
}