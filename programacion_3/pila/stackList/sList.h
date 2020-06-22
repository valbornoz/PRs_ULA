#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED
#include "iostream"
#include "sNode.h"

using namespace std;

template <class T>
class Slist{

    protected:
        Snode<T>   head;
        int size;

    public:

        Slist():size(0) { /*empty*/}
        Snode<T>* getFirst(){return head.getNext();}
        bool isEmpty(){return (head.getNext() == &head);}
        Snode<T>* getNext(Snode<T> *nodO){return static_cast<Snode<T>*>(nodO->getNext());};
        int getSize() { return (int)size;}
        ~Slist(){
            Snode<T>* retVal;
            while(!isEmpty()){
                cout<<"eliminando"<<endl;
                retVal=removeFirst();
                retVal->reset();
                cout<<" is empty()  "<<isEmpty()<<"  el valor es "<<retVal->getData()<<endl;
                delete (retVal);
                retVal=0;
            }
        }


    void insertFirst(Snode<T>* nod){

        if (nod!= 0){
            nod->setNext(head.getNext());
            head.setNext(nod);
        }
        size++;
       return;
    }


    Snode<T>* removeFirst(){

        Snode<T>* retVal;

        retVal = head.getNext();
        head.setNext(retVal->getNext());
        retVal->reset();
        return retVal;
    }

    void insert(Snode<T> *nodO,Snode<T>* nodN){

        if(nodN != 0 ){
            nodN->setNext(nodO->getNext());
            nodO->setNext(nodN);
            size++;
        }
    }

    Snode<T>* remove(Snode<T> *nodO){

        Snode<T>* retVal;

        retVal = nodO->getNext();
        this->setNext(retVal->getNext());
        size--;
        return retVal;
    }

class Iterator{

private:

    Slist*   list;
    Snode<T>* current;

public:

    Iterator(Slist& _list): list(&_list), current(list->getFirst()) {}
    Snode<T>* getCurrent(){return current;}
    bool hasCurrent(){return (current->getNext()!=list->getFirst());}
    void next(){current=current->getNext();}
    void resetFirst(){current = list->getFirst();}
    Iterator& operator =(Snode<T>* aux){
        if (this == aux) return this;
        current=aux;
        return *this;
    }
};
};


#endif // SLIST_H_INCLUDED
