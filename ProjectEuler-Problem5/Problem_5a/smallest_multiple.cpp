#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next;
};

/**checks if 'value' is an existing factor of
* any number in 'factors'. if so, return 0
* (can be ignored) otherwise, return 1.
**/
int isFactor(Node *factors, int value){
    while(factors->next!=NULL){
        if (factors->val%value==0) return 0;

        factors = factors->next;
    }

    return 1;
}

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
    
    int answer=0, factor=0;

    //initilize linked list with first factor
    Node *factors = new Node();
    factors->val = 20;
    factors->next = NULL;

    //search for all possible factors
    for(int i=20; i>1; i--){
        if(isFactor(factors, i)){
            Node *newFactor = new Node();
            newFactor->val = i;
            newFactor->next = factors;

            factors = newFactor;
        }
    }

    answer = factors->val;
    factors = factors->next;

    //determine lcm using gcd ('lcm(a,b) = a*b/gcd(a,b)')
    while(factors->next!=NULL){
        factor = factors->val;

        //lcm(a,b) = a/gcd(a,b) * b to avoid overflow
        answer = (answer/gcd(answer,factor))*factor;
        factors = factors->next;
    }

    cout << "Answer:" << answer<<"\n";
    
}
