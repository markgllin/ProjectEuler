#include <iostream>
#include <math.h>

int main(){
    int count = 0;
    bool bPrime = true;
    double primes[10001]={};
    double num=2;

    while(true){
        if (count==10001) break;

        for (int i=0; i<10000; i++){
            if (fmod(num, primes[i])==0){
                bPrime = false;
                break;
            }
        }

        if (bPrime)
            primes[count++]=num;
        else 
            bPrime =true;

        num++;
    }
  
    std::cout<<"Answer: " << primes[10000]<<std::endl;
}