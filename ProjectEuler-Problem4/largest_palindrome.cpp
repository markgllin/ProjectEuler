#include <iostream>

using namespace std;

/**returns the 'digit' requested in 'value'Answer
**/
int getDigit(int value, int digit){
    while(digit--) value /= 10;

    return (value%10);
}

/**compare digits in number to determine if palindrome
**/
int compare(int value){
    if(value>=100000){
        if((getDigit(value,5)==getDigit(value,0)) &&
          (getDigit(value,4)==getDigit(value,1)) &&
          (getDigit(value,3)==getDigit(value,2)))
          return 1;
    }else if (value>=10000){
        if((getDigit(value,4)==getDigit(value,0)) &&
          (getDigit(value,3)==getDigit(value,1)))
          return 1;
    }

    return 0;
}

int main(){
    int start = 999*999;
    int stop = 100*100;
    int answer, mult, bStop=0;

    while(start>stop){
        //check if value is palindrome
        if(compare(start)){
            mult = 100;

            //determine the factors of palindrome.
            //break loop if 2 factors greater than 100 but less than 1000
            while (mult<1000){
                if ((start%mult==0)&&((start/mult)>99)&&((start/mult)<1000)){
                    answer = start;
                    bStop=1;
                    break;
                }
                mult++;
            }
        }

        if(bStop) break;
        start--;
    }

    cout << "Answer:"<<answer<<"\n";
}
