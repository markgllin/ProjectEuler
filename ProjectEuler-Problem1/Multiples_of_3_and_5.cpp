#include <iostream>
using namespace std;

int main(){
    int c = 0;

    for(int i = 2; i<1000; i++){
        if ((i%3 == 0) || (i%5 == 0)){
            c += i;
        }
    }

    cout << c;
    return 0;
}
