#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "sList.h"
#include "sNode.h"


template <class T>
class Stack{

    protected:

        Slist<T>   stack;

    public:

        Stack(){}
        ~Stack(){}

        void push(Snode<T>* nod){

            if (nod != 0)
                stack.insertFirst(nod);
        }

        Snode<T>* pop(){

            if (!tope.isEmpty())
                return tope.removeFirst();
            else
                return 0;
        }

        Snode<T>* top(){

            if (!tope.isEmpty())
                return tope.getFirst();
             else
                return 0;
        }

        int size(){return tope.getSize();}
        bool isEmpty(){return tope.isEmpty();}
};

#endif // STACK_H_INCLUDED
