#ifndef POLINOMIO_H
#define POLINOMIO_H
#include <iostream>
#include "Dnode.h"
#include "Dlist.h"
#include "termino.h"

class Polinomio
{
    protected:
       Dlist<Termino>  polinomio;

    public:
        Polinomio() {}
        virtual ~Polinomio() {}
        void operator+(Termino newTerm){

            Dnode<Termino>*  termAux;

            termAux= new Dnode<Termino>(newTerm);
            polinomio.append(termAux);
            return;
        }


        void operator+(Polinomio& p2){

            Dnode<Termino>*  termAux1;
            Dnode<Termino>*  termAux2;
            Dnode<Termino>*  nodAux;

            termAux1=this->polinomio.getFirst();
            termAux2=p2.polinomio.getFirst();

            while((termAux1->getNext() != this->polinomio.getFirst()) &&
                  (termAux2->getNext() != p2.polinomio.getFirst())){

                // cout<<"ENTRANDO"<<endl;

                 if (termAux1->getData().getExponente()> termAux2->getData().getExponente())
                     termAux1=termAux1->getNext();
                 else if (termAux2->getData().getExponente()> termAux1->getData().getExponente()){
                        termAux2=termAux2->getNext();
                        nodAux=termAux2->removePrev();
                        termAux1->append(nodAux);
                      }
                      else{
                        termAux1->getData()+(termAux2->getData());
                        if (termAux1->getData().getCoeficiente()==0){
                         termAux1=termAux1->getNext();
                         nodAux=termAux1->removePrev();
                         delete nodAux;
                        }
                        termAux2=termAux2->getNext();
                        nodAux=termAux2->removePrev();
                        delete nodAux;
                      }
            }
            //
            //  falta el codigo de merge en Dlist
            //  this->polinomio.merge(p2.polinomio)
            //  cout<<"SALIENDO"<<endl;

            return;
        }



        void escribe(){

            Dnode<Termino>*  termAux;

            termAux=polinomio.getFirst();
            cout<<endl;
            cout<<"    ";
            while(termAux->getNext() != polinomio.getFirst()){
                cout<<termAux->getData().getCoeficiente()<<"X";
                cout<<termAux->getData().getExponente()<<"  +  ";
                termAux=termAux->getNext();
            }
            //cout<<"SALIENDO"<<endl;
            return;
        }



        /*ostream& operator<<(ostream& o, Polinomio& pol){

            return o;
        }*/


    protected:
    private:
};

#endif // POLINOMIO_H
