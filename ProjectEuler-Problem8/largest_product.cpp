#include <iostream>
#include <fstream>

using namespace std;

int main(){
    int size, length;
    double value;
    double prevAnswer = 0;
    double answer = 1;

    //open the file containing number
    ifstream inputFile;
    inputFile.open("number.txt", ios::in);

    //get size of file to create buffer
    inputFile.seekg(0, ios::end);
    size = inputFile.tellg();
    char num[size];

    //reset file pointer to beginning
    inputFile.seekg(0, ios::beg);

    //read file contents into buffer
    if(inputFile.read(num, size)){

        for(int i=0; i<size-12; i++){

            answer = 1;
            length = 13;

            //multiply 13 digits.
            //ignore newline chars. 
            //if val=0, restart after '0' occurrence
            for (int j=0; j<length; j++){
                //convert from char to int
                value = (double)num[i+j]-48;
                
                if (value>0 && value<10){
                    answer *= value;
                }else if (value == 0){
                    i+=j;
                    break;
                }else{
                   length +=1;
                }
            }

            if (answer>prevAnswer)
                prevAnswer = answer;
        }

    }
    inputFile.close();

    cout<<fixed;
    cout << "Answer: " << prevAnswer <<endl;
    
}