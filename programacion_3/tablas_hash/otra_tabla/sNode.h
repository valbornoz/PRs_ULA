#ifndef SNODE
#define SNODE
#include<iostream>
#include <assert.h>

using namespace std;

template <class T>
class sNode{

protected:
        T data;
        sNode<T>* next;

public:

        sNode(): next(this){}
        sNode(T dat): next(this), data(dat) {}
        sNode(sNode<T>& nod): next(this), data(nod.data) {}

        ~sNode() {}



        void setData(T& dat){
            data=dat;
        }

        T& getData(){
            return data;
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
          next=retVal->next;
          retVal->reset();
          return retVal;
       }

       sNode<T>* getNext() {
          return next;
       }

       bool reset(){
          next==this;
       }

};
#endif
