#include <iostream>
#include <math.h>

using namespace std;

//struct for linked list
struct Node {
    double prime;
    Node *next;
};

/** check if 'value' is divisible by any primes listed in 'head'
* return 1 if divisible by an existing prime.
* return 0 otherwise.
**/
int isDivisible(Node *head, int value){
    while (head->next != NULL){
        //return 1 if value is divisible by existing prime
        if (fmod(value, head->prime)==0) return 1;
        head = head->next;
    }

    return 0;
}

int main(){
    double num = 600851475143;
    double p,currentPrime=0;
    
    //initialize list for storing all primes
    Node *head = new Node();
    head->prime = 1;
    head->next = NULL;

    //initalize list for storing all primes that are factors
    Node *primes = new Node();
    primes->prime = 1;
    primes->next = NULL;

    //must start at 2 because everything divisible by 1
    for(double p = 2; p<=num; p++){
        if(isDivisible(head, p)==0){

            //add new prime to linked list
            Node *newPrime = new Node();
            newPrime->prime = p;
            newPrime->next = head;

            head = newPrime;

            if (fmod(num, p)==0){

                //add new prime factor to linked list
                Node *primeFactor = new Node();
                primeFactor->prime = p;
                primeFactor->next = primes;

                primes = primeFactor;
                num = num/p;
            }    
        }
    }

    //cycle through linked list to find largest prime
    while(primes->next != NULL){
        if (primes->prime>currentPrime)
            currentPrime = primes->prime;

        primes = primes->next;
    }

    cout << "Answer:" <<currentPrime << "\n";

    return 0;
}
