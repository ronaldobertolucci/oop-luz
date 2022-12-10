#ifndef QUEUE_H
#define QUEUE_H

#include "list.hpp"


class Queue : public List
{
    protected:
        Node *tail;
        void setTail(Node *node)
        {
            tail = node;
        }
    
    public:
        Queue() 
        {
            size = 0;
            head = NULL;
            tail = NULL;
        };
        Node *getTail() 
        {
            return tail;
        }
        void add(int data)
        {
            Node *previous = NULL;
            if(getSize() == 0){
                setHead(new Node(data));
                setTail(getHead());
            } else {
                previous = getTail();   
                setTail(new Node(data));
                getTail()->setNext(getHead());
                previous->setNext(getTail());
            }
            setSize(getSize() + 1);
        }
        void remove()
        {
            Node *tempHead = getHead();
            if (getSize() > 1)  // head != tail
            {
                setHead(tempHead->getNext());
                getTail()->setNext(getHead());
                delete tempHead;
            }
            else if (getSize() == 1) // head == tail
            {
                delete tempHead;
                setHead(NULL);
                setTail(NULL);
            } 
            else 
                return;
            setSize(getSize() - 1);
        }
        void empty()
        {
            Node *current = getHead();
            Node *next = current;
            if (getSize() > 0) 
            {
                while(current != getTail())
                {
                    next = current->getNext();
                    delete current;
                    setSize(getSize() - 1);
                    current = next;
                }
                delete current; 
                setSize(getSize() - 1);
            }
            setHead(NULL);
            setTail(NULL);
        }
};

#endif