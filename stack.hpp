#ifndef STACK_H
#define STACK_H

#include "list.hpp"

class Stack : public List 
{
    public:
        Stack() 
        {
            size = 0;
            head = NULL;
        };
        void add(int data)
        {
            Node *next = NULL;
            if(getSize() == 0){
                setHead(new Node(data));
            } else {
                next = getHead();
                setHead(new Node(data));
                getHead()->setNext(next);
            }
            setSize(getSize() + 1);
        }
        void remove()
        {
            Node *temp = getHead();
            if(getSize() > 0) 
            {
                setHead(temp->getNext());
                setSize(getSize() - 1);
            }
            delete temp;
        }
        void empty()
        {
            Node *current = getHead();
            Node *next = current;
            while(getSize() > 0)
            {
                next = current->getNext();
                delete current;
                setSize(getSize() - 1);
                current = next;
            }
            setHead(NULL);
        }
};

#endif