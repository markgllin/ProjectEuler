#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

int main(){
    double answer = 0;

    std::ifstream file("numbers.txt");
    std::string line;
    

    while(std::getline(file, line)){
        answer += std::stod(line);
    }

    file.close();

    while (answer>9999999999)
        answer /= 10;

    std::cout << std::fixed;
    std::cout << floor(answer) << std::endl;

}