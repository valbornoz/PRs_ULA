#ifndef SNODE_H
#define SNODE_H

#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

template <class T>
class sNode{

protected:
        T data;
        sNode<T>* next;

public:

        sNode():next(this){}
        sNode(T dat): data(dat), next(this){}
        sNode(sNode<T>& nod): data(nod.data), next(this){}
	sNode(sNode<T> *nod): next(this){ data=nod->data; }

        ~sNode() {}

        T& getData(){
            return data;
        }

        void setData(T& dat){
            data=dat;
        }

        void insertNext(sNode<T>* nod){

	      assert(nod != 0);
          nod->next= next;
          next=nod;
          return;
        }

       sNode<T>* removeNext(){

          sNode<T>* retVal;

          retVal=next;
          next=retVal->getNext();
          retVal->reset();
          return retVal;

       }

       sNode<T>* getNext() {
          return next;
       }

       void reset(){
           next=this;
           return;
       }

	bool isEmpty(){
	return (next==this);
	}

};

#endif // SNODE_H
