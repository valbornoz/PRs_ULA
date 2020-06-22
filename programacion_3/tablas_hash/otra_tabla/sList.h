#ifndef SLIST_H_INCLUDED
#define SLIST_H_INCLUDED
#include "iostream"
#include "sNode.h"

using namespace std;

template <class T>
class Slist{

    protected:
        sNode<T>   head;
        int size;

    public:

        Slist():size(0) { /*empty*/}
        sNode<T>* getFirst(){return head.getNext();}
        bool isEmpty(){return (head.getNext() == &head);}
        sNode<T>* getNext(sNode<T> *nodO){return static_cast<sNode<T>*>(nodO->getNext());};
        int getSize() { return (int)size;}
        ~Slist(){
            sNode<T>* retVal;
            while(!isEmpty()){
               // cout<<"eliminando"<<endl;
                retVal=removeFirst();
                retVal->reset();
                //cout<<" is empty()  "<<isEmpty()<<"  el valor es "<<retVal->getData()<<endl;
                delete (retVal);
                retVal=0;
            }
        }


    void insertFirst(sNode<T>* nod){

        if (nod!= 0){
            nod->insertNext(head.getNext());
            head.insertNext(nod);
        }
        size++;
       return;
    }


    sNode<T>* removeFirst(){

        sNode<T>* retVal;

        retVal = head.getNext();
        head.insertNext(retVal->getNext());
        retVal->reset();
        return retVal;
    }

    void insert(sNode<T> *nodO,sNode<T>* nodN){

        if(nodN != 0 ){
            nodN->insertNext(nodO->getNext());
            nodO->insertNext(nodN);
            size++;
        }
    }

    sNode<T>* remove(sNode<T> *nodO){

        sNode<T>* retVal;

        retVal = nodO->getNext();
        this->insertNext(retVal->getNext());
        size--;
        return retVal;
    }

class Iterator{

private:

    Slist*   list;
    sNode<T>* current;

public:

    Iterator(Slist& _list): list(&_list), current(list->getFirst()) {}
    sNode<T>* getCurrent(){return current;}
    bool hasCurrent(){return (current->getNext()!=list->getFirst());}
    void next(){current=current->getNext();}
    void resetFirst(){current = list->getFirst();}
    Iterator& operator =(sNode<T>* aux){
        if (this == aux) return this;
        current=aux;
        return *this;
    }
};
};


#endif // SLIST_H_INCLUDED


