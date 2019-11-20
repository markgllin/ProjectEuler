#include <iostream>
#include <math.h>

int main(){
    int length=0;
    int prevLength = 0;
    int answer = 0;
    double num;

    for (int i=1; i<1000000; i++){
        length = 0;
        num = i;

        while (true){
            length++;

            if (num == 1){
                break;
            }else if (fmod(num, 2.0) == 0){
                num /= 2.0;
            }else{
                num = (3.0*num)+1.0;
            }
        }

        if (length>prevLength){
            prevLength = length;
            answer = i;
        }
    }

    std::cout << "Answer: " << answer << std::endl;
}