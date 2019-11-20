#include <iostream>
#include <list>
#include <math.h>

std::list<int> power(std::list<int> base, int exponent){
    std::list<int> result;
    int carry = 0;

    if (exponent == 0) return base;

    for (int digit : base){
        std::cout << digit << std::endl;
        digit = (digit+carry)*digit;

        result.push_back(digit%10);
        carry = floor(digit/10);
    }

    if (carry!=0) result.push_back(carry);

    return power(result, exponent-1);

}

int main(){
    int exponent = 4;
    int answer = 0;
    
    std::list<int> base = {2};

    std::list<int> result = power(base, exponent-1);

    for (int i : result){
        std::cout <<  i;
        answer +=i;
    }

    std::cout << "Answer: " << answer << std::endl;
}