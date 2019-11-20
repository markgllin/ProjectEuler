#include "LinkedList.h"
#include <iostream>

//Default Constructor - initilizes list with head node
LinkedList::LinkedList(){
    head = NULL;
    listLength = 0;
}

// setter method for inserting a new node
// inserts new node at the head of the list
bool LinkedList::insertNode(node * newNode){
    if(head==NULL){
        head = NULL;
    }
    
    newNode->next = head;
    head = newNode;
    listLength++;
    return true;
}

//Destructor de-allocates memory used by list
LinkedList::~LinkedList(){
    node * p = head;
    node * q = head;

    while(q){
        p = q;
        q = p->next;
        if (q) delete p;
    }
}