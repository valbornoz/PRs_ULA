#ifndef DICCIONARIOABIERTO_H_INCLUDED
#define DICCIONARIOABIERTO_H_INCLUDED
#include "../../Slist1/sList.h"
#include "../../Slist1/sNode.h"

#define MAXTAM  101

using namespace std;

template <class T>
class Diccionario{

    protected:

        Slist<T>*  tabla;
        size_t  numEle;
        size_t  tam;

    protected:
        int hash(T key){
          return (cl%tam);
        };
    public:

        Diccionario(): numEle(0), tam(MAXTAM) {
            tabla = new Slist<T>[tam];
        }

        Diccionario(size_t n): numEle(0), tam(n) {
           tabla = new Slist<T>[tam];
        }

        ~Diccionario(){
            delete []  tabla;
        }

        T search(T key){

            size_t pos;
            Snode<T>* aux,*aux1;
            pos=hash(key)%tam;

            aux1=tabla[pos].getFirst();
            aux=aux1;
            while (aux1->getNext()!=aux){
                  if (aux->getData()==key)
                        return aux->getData();
                  aux1=aux1->getNext();
            }
            return aux->getData();
        }

        void insert(T key){

            Snode<T>* nod;
            size_t pos;

            pos=hash(key)%tam;
            nod = new Snode<T>(key);
            tabla[pos].insertFirst(nod);
            numEle++;
            return;
        }

        void remove(T key){

            size_t pos;
            Snode<T>* aux, *aux1;
            Snode<T>* retVal;

            pos=hash(key)%tam;
            aux=tabla[pos].getFirst();
            aux1=aux;
            if (aux->getData()==key){
                retVal=tabla[pos].removerFirst();
                delete retVal;
                return;
            }
            do{
             if(aux->getNext()->getData()==key){
                retVal=aux.removeNext();
                delete retVal;
             }
             aux=aux->getNext();
            }while (aux->getNext()!=aux1);
            return;
        }


};




#endif // DICCIONARIOABIERTO_H_INCLUDED
