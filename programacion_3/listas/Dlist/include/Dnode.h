#ifndef DNODE_H
#define DNODE_H

template< class T>
class Dnode
{
    protected:
        T data;
        Dnode<T> *next;
        Dnode<T> *prev;

    public:
        Dnode() : next(this), prev(this) {}
        Dnode(Dnode<T> *nod ) next(this), prev(this){
            data = nod->data;
        }
        Dnode( t dat ): data(dat),  next(this), prev(this){ }
        virtual ~Dnode();
        T& getData() { return data; }
        void setData( const T& dat ) { data = dat;}
        void setNext( Dnode<T> * nod){next= nod;}
        void setPrev( Dnode<T> * nod){prev= nod;}
        Dnode<T>* getNext(){return next;}
        Dnode<T> *getPrev() {return prev;}
        void reset() { next = this; prev = this; }
};

#endif // DNODE_H
