#ifndef QUEVE_H_INCLUDED
#define QUEVE_H_INCLUDED
#include "Dnode.h"
//	cola dinamica

template <class T>
class Queve{

	Dnode<T> queve;
	int numele;

    public:

        Queve(){
		numele=0;
	}

        ~Queve(){
	}

        void put(T ele){	//inserta de ultimo
		Dnode<T>* auxNode;

		auxNode=new Dnode<T>(ele);
		queve.insert(auxNode);
		numele++;
        }

	T get(){	//saca el primero
		Dnode<T>* retval;
		if(isEmpty()) return 0;

		retval=queve.removePrev();
		numele--;

		return retval->getData();
	}

	T Head(){	//muestra el primero
		if(isEmpty()) return NULL;
		return queve.getPrev()->getData();
	}

	int size(){
		return numele;
	}

	bool isEmpty(){
		return (queve.isEmpty());
	}
};

#endif // QUEVES_H_INCLUDED
