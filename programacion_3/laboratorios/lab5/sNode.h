#ifndef SNODE_H_INCLUDED
#define SNODE_H_INCLUDED
#include "iostream"

using namespace std;

template <class T>
class Snode{

    protected:
        T data;
        Snode<T>* next;
    //friend class Slist;

    public:

    Snode(): next(this){ }
    Snode(const Snode<T>& other);
    Snode(const T& dat): data(dat), next(this) { }
    ~Snode(){}

    T& getData() {return data;}
    void  setData(T& dat);
    Snode<T>*  getNext() {return static_cast<Snode<T>*>(next);}
    void setNext(Snode<T>* nx);
    void reset();

};

template <class T>
Snode<T>::Snode(const Snode& other){
        data = other.data;
        next=this;
    }

template <class T>
void Snode<T>::setData(T& dat){
        data = dat;
        return;
        }

template <class T>
void Snode<T>::setNext(Snode<T>* nx){
        next = nx;
        }

template <class T>
void Snode<T>::reset(){
        next = this;
        }

#endif

