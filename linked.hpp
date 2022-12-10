#ifndef LINKED_H
#define LINKED_H

#include "list.hpp"

class LinkedList : public List
{
    protected:
        Node *tail;
        void setTail(Node *node)
        {
            tail = node;
        }
    
    public:
        LinkedList() 
        {
            size = 0;
            head = NULL;
            tail = NULL;
        };
        Node *getTail() 
        {
            return tail;
        }
        void add(int data) //addTail
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
        void remove() //removeHead
        {
            Node *tempHead = getHead();
            Node *tempTail = getTail();
            if (getSize() > 2)  // head != tail
            {
                setHead(tempHead->getNext());
                getTail()->setNext(getHead());
                delete tempHead;
            }
            else if (getSize() == 2)
            {
                setHead(tempHead->getNext());
                delete tempHead;
                delete tempTail;
                setTail(getHead());
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
        void addHead(int data) 
        {
            Node *next = NULL;
            if(getSize() == 0){
                setHead(new Node(data));
                setTail(getHead());
            } else {
                next = getHead();
                setHead(new Node(data));
                getHead()->setNext(next);
                getTail()->setNext(getHead());
            }
            setSize(getSize() + 1);
        }
        void removeTail() // O(n)
        {
            Node *current = getHead();
            Node *tempTail = getTail();
            Node *previous = current;
            if(getSize() > 2) {
                while (current != getTail())
                {
                    previous = current;
                    current = current->getNext();
                }
                delete current;
                setTail(previous);
                getTail()->setNext(getHead());
            }
            else if (getSize() == 2)
            {
                delete tempTail;
                setTail(getHead());
            }
            else if (getSize() == 1)
            {
                delete current;
                setHead(NULL);
                setTail(NULL);
            } 
            else
                return;
            setSize(getSize() - 1);
        }
};

#endif