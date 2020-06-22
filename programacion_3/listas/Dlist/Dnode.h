#ifndef DNODE_H_INCLUDED
#define DNODE_H_INCLUDED
#include <assert.h>
#include <iostream>


template <class T>
class Dnode {

    protected:
        T data;
        Dnode<T>* next;
        Dnode<T>* prev;

    public:
        Dnode():next(this), prev(this) {}
        Dnode(const Dnode<T>& nod){
            next=this;
            prev=this;
            data = nod.data;
        }
        Dnode(const T& dat){
            data=dat;
            next=this;
            prev=this;
        }
        virtual ~Dnode(){}
        T& getData() {return data; }
        void setData( const T& dat ) { data = dat;}
        Dnode<T>* getNext(){return next;}
        Dnode<T>* getPrev() {return prev;}
        void setNext(Dnode<T>* nx){next=nx;}
        void setPrev(Dnode<T>* pv){prev=pv;}
        void reset() { next = this; prev = this; }

        void insert(Dnode<T>* nod){

            assert(nod!=NULL);
            nod->next= this->next;
            nod->prev= this;
            this->next->prev=nod;
            this->next=nod;
            return;
        }

        void append(Dnode<T>* nod){

            assert(nod!=NULL);
            nod->prev= this->prev;
            nod->next=this;
            this->prev->next= nod;
            this->prev=nod;
            return;
        }

        void remove(){
            next->prev=prev;
            prev->next=next;
            return;
        }

        Dnode<T>* removeNext(){

            Dnode<T>* retVal=0;
            if (next!= this){
                retVal=next;
                retVal->remove();
                retVal->reset();
            }
            return retVal;
        }



        Dnode<T>* removePrev(){

            Dnode<T>* retVal=0;

            if (prev!=this){
                retVal=prev;
                retVal->remove();
                retVal->reset();
            }
            return retVal;

        }

};


#endif // DNODE_H_INCLUDED
