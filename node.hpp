#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Node {
    private:
        int data;
        Node *next;
    
    public:
        Node(int a) 
        {
            data = a;
            next = NULL;
        }
        Node(int a, Node *node)
        {
            data = a;
            next = node;
        }
        // Sobrecarga de operador
        void operator+(Node *node)
        {
            this->setNext(node);
        }
        
        int getData() 
        {
            return data;
        }
        void setData(int a) 
        {
            data = a;
        }
        Node *getNext() {
            return next;
        }
        void setNext(Node *node) 
        {
            next = node;
        }
};

#endif