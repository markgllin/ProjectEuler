#include <iostream>

using namespace std;

/**finding gcd using Euclid's algorithm.
* takes in two integers and returns the
* greatest common divisor.
**/
int gcd(int a, int b){
    if (a==0) return b;
    else if (b==0) return a;
    else if (a==b) return a;

    if(a>b) 
        gcd(b, a%b);
    else
        gcd(a, b%a);
}

int main(){
    int answer=1;

    //determine lcm using gcd ('lcm(a,b) = a / gcd(a,b) * b')
    for(int i = 2; i<20;i++)
        answer = (answer/gcd(answer,i))*i;

    cout << "Answer:" << answer<<"\n";
    
}