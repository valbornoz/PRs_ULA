#ifndef DLIST_H
#define DLIST_H

template< class T>
class Dlist
{
    public:
        Dlist();
        virtual ~Dlist();

        void insertFirst( Dnode<T> *);
        void insertLast( Dnode<T> *);


    protected:
        Dnode<T> head;
        int size;
    private:
};

#endif // DLIST_H
