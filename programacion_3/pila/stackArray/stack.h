#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

template <class T>
class StackA{

protected:
    int tope;
    int size;
    T* stack;

public:

    StackA():tope(0){
        size=100;
        stack = new T[size];
    }
    StackA(const int tam):tope(0),size(tam){
        stack = new T[size];
    }
    ~StackA(){delete []stack;}

    bool isEmpty(){return tope == 0;}
    bool isFull(){return tope==size;}
    int cardinalidad(){return tope;}

    void push(T ele){

        stack[tope]=ele;
        tope++;
        return;

    }

    T pop(){
        T aux;
        aux = stack[tope-1];
        tope--;
        return aux;
    }

    T& top(){return stack[tope-1];}
};
#endif // STACK_H_INCLUDED
