#include <iostream>
#include <math.h>

using namespace std;

int numOfDivisors(double val){
    int divisors = 0;

    for(int i = 1; i<=sqrt(val); i++)
        if (fmod(val, i)==0)
            divisors+=2;
    

    if (floor(sqrt(val))==sqrt(val))
        divisors--;
    
    return divisors;
}

int main(){
    double trig_num = 1;
    double i = 2;

    while (true){
       if (numOfDivisors(trig_num)>500)
            break;

        trig_num += i++;
    }

    cout << fixed;
    cout << "Answer: " << trig_num <<endl;
}