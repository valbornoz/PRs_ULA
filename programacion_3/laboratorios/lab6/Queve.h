#ifndef QUEVE_H_INCLUDED
#define QUEVE_H_INCLUDED

//	cola estatica

template <class T>
class Queve{

	T* queve;
	int head, tail, tam, numele;

    public:

        Queve(){
		queve=new T[100];
		head=-1;
		tam=100;
		tail=-1;
		numele=0;
	}

        ~Queve(){
		delete [] queve;
	}

        void put(T ele){
		if(head==-1) head=0;
		if(head==tail+2) return;   //lleno
		tail=(tail+1)%tam;
		queve[tail]=ele;
		numele++;
        }

	T get(){
		T retval=0;

		if(numele==0) return retval;

		retval=queve[head];
		head=(head+1)%tam;
		numele--;

		if(numele==0){
			head=-1;
			tail=-1;
		}

		return retval;
	}

	T Head(){
		if(isEmpty()) return NULL;
		return queve[head];
	}

	int size(){
		return numele;
	}

	bool isEmpty(){
		return (numele==0);
	}

	bool isFull(){
		return (numele==tam);
	}
};

#endif // QUEVES_H_INCLUDED
