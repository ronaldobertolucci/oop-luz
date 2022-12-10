#ifndef LIST_H
#define LIST_H

#include "node.hpp"

class List 
{
    protected:
        int size;
        Node *head;
        void setHead(Node *node) 
        {
            head = node;
        }
        void setSize(int a) 
        {
            size = a;
        }
    
    public:
        Node *getHead() 
        {
            return head;
        }
        int getSize() 
        {
            return size;
        }
        void display()
        {
            int i = 1;
            Node *current = getHead();
            if(getSize() == 0) {
                cout << "\n[]\n";
                return;
            }

            cout << "\n[";

            while(getSize() >= i) {
                if(i == getSize()) // última iteração
                    cout << current->getData();
                else
                    cout << current->getData() << ", ";

                current = current->getNext();
                i++;
            };

            cout << "]\n";
        }
        virtual void add(int data) = 0;
        virtual void remove() = 0;
        virtual void empty() = 0;
};

#endif