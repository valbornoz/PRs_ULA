#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED
#include "sList.h"
#include "sNode.h"


template <class T>
class Stack{

    protected:

        Slist<T> stack;

    public:

        Stack(){}
        ~Stack(){}

        void push(T& ele){
            Snode<T>* nod;

            nod=new Snode<T>(ele);
            if (nod != 0)
                stack.insertFirst(nod);
        }

        T pop(){

            Snode<T>* nod;
            T aux;
            if (!stack.isEmpty()){
                nod = stack.removeFirst();
                aux=nod->getData();
                delete nod;
            }
            return aux;
        }

        T top(){

            Snode<T>* nod;
            T aux;
            if (!stack.isEmpty()){
                nod = stack.getFirst();
                aux=nod->getData();
            }
            return aux;
        }

        int size(){return stack.getSize();}
        bool isEmpty(){return stack.isEmpty();}
};

#endif // PILAS_H_INCLUDED
