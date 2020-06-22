#ifndef SLOT_H_INCLUDED
#define SLOT_H_INCLUDED


template <class T>
class Slot{

    protected:
        T   data;
        int edo;

    public:

        Slot():edo(0){}
        Slot(T dat):edo(1), data(dat){}
        ~Slot(){}

        T& getData() {return data;}
        void setData(T cl){data=cl;}
        void setEdo(int ed) {edo=ed;}
        int  getEdo(){return edo;}
    };
#endif // SLOT_H_INCLUDED
