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
	bool isEmpty() {return (next==this and prev==this);}

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

	void swap(Dnode<T>* nod){
		if(this==nod) return;

		if((this->getNext()==nod) and (nod->getPrev()==this)){
			this->next->prev=this->prev;
			this->next=nod->next;
			this->prev->next=nod;
			nod->next=this;
			this->prev=nod;
			this->next->prev=this;
			return;
		}

		if((this->getPrev()==nod) and (nod->getNext()==this)){
			nod->next=this->next;
			nod->next->prev=nod->prev;
			nod->prev->next=this;
			this->next=nod;
			nod->prev=this;
			this->prev()=nod->next()->prev();
			nod->next->prev=nod;
			return;
		}

		Dnode<T>* auxtn, *auxtp;

		nod->prev->next =this;
		nod->next->prev =this;       
		this->prev->next =nod;
		this->next->prev =nod;
		auxtn = this->next;
		auxtp = this->prev;
		this->next = nod->next;
		this->prev = nod->prev;
		nod->next = auxtn;
		nod->prev = auxtp;
	}

};


#endif // DNODE_H_INCLUDED
