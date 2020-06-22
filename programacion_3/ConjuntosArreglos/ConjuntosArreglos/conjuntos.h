#ifndef CONJUNTOS_H
#define CONJUNTOS_H

template <class T>
class Conjuntos
{
    public:
        Conjuntos() {}
        virtual ~Conjuntos() {}
        virtual T* search(const T ele)=0;
        virtual void insert(T ele)=0;
        virtual T* remove(const T ele)=0;
        virtual void merge(Conjuntos& t2)=0;
        virtual void split(int pos,Conjuntos& t1, Conjuntos& t2)=0;
        virtual T* searchInPos(int pos)=0;


};
#endif // CONJUNTOs_H
