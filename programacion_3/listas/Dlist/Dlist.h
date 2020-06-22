#ifndef DLIST_H_INCLUDED
#define DLIST_H_INCLUDED
#include <iostream>
#include <assert.h>
#include "Dnode.h"


template <class T>
class Dlist{

    typedef Dnode<T> Node;
    protected:

        Dnode<T> head;

    public:


        Dlist(){}
        Dlist(Dlist<T>& l1){
		Dnode<T>* auxNod;
		Dnode<T>* auxlist, *aux;

	aux=&(this->head);
	auxlist=l1.head.getNext();

		while(auxlist!=&l1.head){
			auxNod=new Dnode<T>(auxlist-> getNext());
			aux->head.insert(auxNod);
			aux=auxNod;
			auxlist=auxlist->getNext();
		}

	}
        virtual ~Dlist(){
		Dnode<T>* aux;

		while(!this->head.isEmpty()){
			this->head.removeNext(); //}
			delete aux;
		}
	}
        bool isEmpty(){return head.getNext() == &head && head.getPrev() == &head;}
        bool hasOne(){return head.getNext() == head.getPrev() && head.getNext()!= &head;}
        void insert(Node* nod){
            assert(nod!=NULL);
            //nod->setNext(head.getNext());
            //nod->setPrev(&head);
            //head.getNext()->setPrev(nod);
            head.insert(nod);
            return;
        }

         void append(Node* nod){
            assert(nod!=NULL);
            //nod->setNext(&head);
            //nod->setPrev(head.getPrev());
            //head.getPrev()->setNext(nod);
            head.append(nod);
            return;
        }

        Node* getFirst(){return head.getNext();}
        Node* getLast(){return head.getPrev();}

        Node* removeFirst(){

            Node* retVal=0;

            retVal=head.removeNext();
            return retVal;
        }

        Node* removeLast(){
            Node* retVal=0;

            retVal=head.removePrev();
            return retVal;
        }

       void split(Node* nod, Dlist<T>& right){

            Node* aux;

            assert(nod!=NULL);
            aux=nod->getNext();
            nod->setNext(&head);
            right.head.setNext(aux);
            aux->setPrev(&right.head);
            right.head.setPrev(head.getPrev());
            head.getPrev()->setNext(&right.head);
            head.setPrev(nod);
            return;
        }

        //void join(Dlist<T>& right){} escribir el c'odigo

};

#endif // DLIST_H_INCLUDED


