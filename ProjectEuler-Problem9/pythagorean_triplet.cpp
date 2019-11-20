#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){
    int square, sum, answer = -1;
    int start = 1;

    LinkedList tripletChoices;    

    while (start<999){
        //create new node
        node * factor = new node;
        factor->root = start;
        square = start*start;
        factor->square = square;

        //insert into list
        tripletChoices.insertNode(factor);

        start++;
    }

    node * a_factor = tripletChoices.head;

    while(a_factor->next!=NULL){

        node * b_factor = a_factor->next;

        while(b_factor->next!=NULL){
            sum = a_factor->square + b_factor->square;


            node * c_factor = tripletChoices.head;

            while(c_factor->next!=NULL){

                if (sum == c_factor->square){

  
                    if ((a_factor->root + b_factor->root + c_factor->root)==1000){
                        cout << "A:" << a_factor->root << " B:" << b_factor->root << " C:" << c_factor->root << endl;

                        answer = a_factor->root * b_factor->root * c_factor->root;
                        break;
                    }
                }

                c_factor = c_factor->next;
            }

            b_factor = b_factor->next;
        }

        a_factor = a_factor->next;
    }

    cout<<"Answer: " << answer << endl;

    return 0;
}