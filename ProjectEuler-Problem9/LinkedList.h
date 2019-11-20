#ifndef LinkedList_h
#define LinkedList_h

struct node{
    int root;
    int square;
    node *next;
};

class LinkedList{
    public: 
        node * head;
        int listLength;

        //default constructor creates head node
        LinkedList();

        //setter method
        bool insertNode(node * newNode);
        
        //getter method. not implemented as we don't need it
        /*
          code
        */

        //destructor de-allocates memory used by the list
        ~LinkedList();
};

#endif