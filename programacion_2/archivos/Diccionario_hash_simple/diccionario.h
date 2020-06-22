#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "slot.h"
#define MAXTAM  101
#define NULLSLOT 0

using namespace std;

template <class T>
class Diccionario{

    protected:

        Slot<T>*  tabla;
        size_t  numEle;
        size_t  tam;


    public:

        Diccionario(): numEle(0), tam(MAXTAM) {
            size_t i;
	    Slot<T> dat;
            tabla = new Slot<T>[tam];
        }

        Diccionario(size_t n): numEle(0) {
            size_t i;
	    Slot<T> dat;
            tam=tam= (25*n)/100 + n;
            tabla = new Slot<T>[tam];
        }

        ~Diccionario(){
            delete []  tabla;
        }

       
        T* search(T key){

            int i=0;
	    size_t pos,posi;
            T* aux;

            pos=hash(key)%tam;
            posi=pos;   
//            do{
              //cout<<"Pos del slot  es  "<<posi<<endl;
              if ((tabla[posi].getData() == key) && (tabla[posi].getEdo()==1)){
                //cout<<"Si "<<tabla[posi].getData()<<" Edo  "<<tabla[posi].getEdo()<<endl;
                return (&tabla[posi].getData());}
              else {
                if (tabla[posi].getEdo() ==0){
                  // cout<<" Ranura vacia fin de la busqueda "<<endl;                         
	          return aux;}
              i=i+1;
	      posi=(posi+i)%tam; // condicion innecesaria,se garantiza espacio libre puede escribirse  while(1)
            return aux;
        }}

        void insert(T key){	int i=0;

            size_t pos,posi;
            Slot<T> dat(key);

            if (numEle/tam> 0.75)
              recall();
            pos=hash(key)%tam;
            posi=pos;
            do{
              if ((tabla[posi].getEdo()!=1)){
                tabla[pos]=dat;
                numEle++;
                return; }
              i=i+1;
	      posi=(posi+i)%tam;
            }while (posi!=pos); // condicion innecesaria,se garantiza espacio libre puede escribirse  while(1)

        }

        void remove(T ele){

            size_t pos;

            pos = searchPos(ele);
            if (pos<tam){
              tabla[pos].setEdo(2);
              // cout<<"Estado eliminado "<< tabla[pos].getEdo()<<endl;
              numEle--;
            }
            return;
        }

    private:

        size_t searchPos(T key){
            int i=0;  
            size_t pos,posi;

            pos=hash(key)%tam;
            posi=pos;             
            do{
              cout<<"Pos en eliminado  "<<posi<<endl;
              if (tabla[posi].getData() == key && tabla[posi].getEdo()==1)
                return posi;
              else 
                if (tabla[posi].getData() == 0)
                  return tam;
              i=i+1;
	      posi=(posi+i)%tam;
            }while (posi!=pos); // condicion innecesaria,se garantiza espacio libre puede escribirse  while(1)
            return tam;
        }

        void recall(){return;}

        size_t hash(T cl){
            return (cl%tam);
        }


};
#endif // DICCIONARIO_H_INCLUDED

