#ifndef ARRGLOORD_H
#define ARRGLOORD_H

#define NULL 0L
#include <iostream>

using namespace std;

template <class T>
class ArregloOrd {
protected:

    T*  vector;
    int size;
    int numEle;

public:
        ArregloOrd():size(100), numEle(0){
            vector = new T[size];
        }

         ArregloOrd(int tam):size(tam), numEle(0){
            vector = new T[size];
        }

        ArregloOrd(const ArregloOrd& other){
            int i;

            size = other.size;
            numEle = other.numEle;
            vector=new T[size]; // vector= other.vector
            for (i=0; i<numEle; i++)
                vector[i]= other.vector[i];
            }

        virtual ~ArregloOrd(){
            delete [] vector;
        }

        ArregloOrd<T>& operator=(const ArregloOrd<T>& other){
            int i;
            if (size>=other.size){
                numEle = other.numEle;
                for (i=0; i<numEle; i++)
                    vector[i]= other.vector[i];
            }
            return *this;
        }

        int searchPos(T ele){
          return busBin(0,numEle-1,ele);
        }

        T* search(T ele){
            int pos;
            T* retVal=NULL;

            pos=busBin(0,numEle-1,ele);
            if (vector[pos]==ele)
                retVal=&vector[pos];
            return retVal;
        }


        T* searchInPos(int pos){

           T* retVal=NULL;

           if (pos >= numEle) return retVal;
           retVal=&vector[pos];
           return retVal;
        }

        void insertNum(T ele){
            int pos;

            if (numEle==size) return;

            pos=busBin(0,numEle-1,ele);

            if (vector[pos]==ele) return;

            openSpace(pos);
            vector[pos]=ele;
            numEle++;

            return;
        }
//
	void insert2(T ele){

            if (numEle<size){
              vector[numEle]=ele;
               numEle++;
            }
            return;
        }
//
        T* remove(T ele){
            int pos;
            T* retVal;
            T aux;

            pos=busBin(0,numEle-1,ele);
            if (vector[pos]!=ele) return NULL;
            aux=vector[pos];
            retVal=&aux;
            closeSpace(pos);
            numEle--;
            return retVal;

        }

        bool isEmpty(){return numEle==0;}
        int getSize(){ return size;}
        int getNumEle(){return numEle;}

        void splitByPos(int pos, ArregloOrd<T>& arLeft, ArregloOrd<T>& arRight){
           int i;

           for (i=0; i<pos; i++)
              arLeft.vector[i]=vector[i];

           for (i=0; i+pos<numEle; i++)
              arRight.vector[i]=vector[i+pos];
           arLeft.numEle=pos;
           arRight.numEle=numEle-pos;
           numEle=0;
           return;
        }

        void splitByKey(T key, ArregloOrd<T>& arLeft, ArregloOrd<T>& arRight){
           int pos;

            pos=searchPos(key);
            if (pos<numEle)
                splitByPos(pos,arLeft,arRight);
            return;
        }


protected:
private:

        int busBin(int li,int ls,T ele){
            int medio=0;

            while (li<=ls){
                medio=(li+ls)/2;
                if (vector[medio]==ele)
                    return medio;
              //  else
                //    if (vector[medio]>ele)
                  //      ls=medio-1;
                    //else
                      //  li=medio+1;
            }
            return li;
        }

        void openSpace(int pos){

            int i;

            for(i=numEle; i>=pos; i--)
                vector[i]=vector[i-1];
        }

        void closeSpace(int pos){

            int i;

            for(i=pos; i<numEle-1; i++)
                vector[i]=vector[i+1];
        }

};

#endif // ARRGLOORD_H
