#ifndef STACKLIST_H
#define STACKLIST_H
#include "sList.h"
#include "sNode.h"


using namespace std;

template <class T>
class Stack{

    protected:

        Slist<T>   stack;
        int        size;

    public:
        Stack(): size(0){}
        virtual ~Stack(){}

	 Stack(const Stack& other){

            size=other.size;
            //copiar elementos de la pila
        }

	Stack& operator=(const Stack& other){

            if (this == &other) return *this; // handle self assignment
            size=other.size;
	    //copiar elementos de la pila
            return *this;
        }

        void push(T ele){
            Snode<T>* nod;

            nod=new Snode<T>(ele);
            if (nod != 0){
                stack.insertFirst(nod);
                size++;}
         //   else
         //       throw ("Error memoria no disponible");
            return;
        }

        T pop(){

            Snode<T>* nod;
            T retVal;

            if (!stack.isEmpty()){
                nod=stack.removeFirst();
                retVal=nod->getData();
                delete nod;
                size--;
            }
          else
            throw ("Error");
        return retVal;
        }

        T top(){

            if (!stack.isEmpty())
                return stack.getFirst()->getData();
             else
                return 0;
        }

        int getSize(){return stack.getSize();}
        bool isEmpty(){return stack.isEmpty();}

};
#endif // STACKLIST_H
