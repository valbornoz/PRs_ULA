#ifndef SLIST_H
#define SLIST_H

#include <iostream>
#include "sNode.h"

using namespace std;

template <class T>

class sList{

	protected:

		sNode<T> head;
/*size_T*/	int numele; //opcional

	public:

	sList():numele(0){}

	sList(sList<T>& l1){
		sNode<T>* auxNod;
		sNode<T>* auxlist, *aux;

	aux=&(this->head);
	auxlist=l1.head.getNext();

		while(auxlist!=&l1.head){
			auxNod=new sNode<T>(auxlist->getData());
			aux->insertNext(auxNod);
			aux=auxNod;    //aux=aux->getNext();
			auxlist=auxlist->getNext();
			this->numele=l1.numele;
		}
	}

	virtual ~sList(){
		sNode<T>* aux;

		while(!this->head.isEmpty()){
			aux=this->head.removeNext(); //}
			delete aux;
		}
	}

	sNode<T>* gethead(){

		sNode<T>* retval;

		retval=&head;
		return retval;

	}

	sNode<T>* getFirt(){
		return head.getNext();
	}

	void insertFirt(sNode<T>* nod){
		if(nod!=NULL)	head.insertNext(nod);
		numele++;
		return;
	}

	sNode<T>* removeFirt(){
		if(!head.isEmpty()) numele--;
		return head.removeNext();
	}

	bool isEmpty(){
	return head.isEmpty();
	}

	/*size_T*/ int size(){ return numele;}

	void setsize(/*size_T*/ int num){
		numele=numele+num;
	}


class Iterator{

	protected:
		sNode<T> acthead;
		sNode<T> *current;

	public:

	Iterator(sList<T>& l1){
		acthead=l1.head;
		current=l1.getFirt();
	}
	Iterator(Iterator& it){
		acthead=it.acthead;
		current=it.current;
	}


	~Iterator(){}

	void Next(){
		current=current->getNext();
	}

	bool hascurrent(){

		return (current!=&acthead);
	}

	void resert(){
		current=acthead.getNext();
	}

	sNode<T>* getcurrent(){
		return current;
	}

	Iterator& operator=(Iterator& it){
		acthead=it.acthead;
		current=it.current;
	}
};
};

#endif
