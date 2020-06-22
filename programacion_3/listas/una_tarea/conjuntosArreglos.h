#ifndef CONJUNTOSARREGLOS_H
#define CONJUNTOSARREGLOS_H
#include <iostream>

//#define NULL 0

//#include "conjuntos.h"

template <class T>
class ConjuntosArreglos{

    protected:

        T* conjunto; //!< Member variable "conjunto"
        int size; //!< Member variable "size"
        int numEle; //!< Member variable "numEle"public:

    public:

        /** Default constructor */
        ConjuntosArreglos():size(100), numEle(0){
            conjunto = new T[size];
        }
	


        /** Constructor parametrizado*/
         ConjuntosArreglos(int tam):size(tam), numEle(0){
            conjunto = new T[size];
        }
        /** Copy constructor *  \param other Object to copy from */
        ConjuntosArreglos(const ConjuntosArreglos<T>& other){
            int i;

            size = other.size;
            numEle = other.numEle;
            conjunto=new T[size]; // conjunto= other.conjunto
            for (i=0; i<numEle; i++)
                conjunto[i]= other.conjunto[i];
            }

        /** Default destructor */

        virtual ~ConjuntosArreglos(){
            delete [] conjunto;
        }

        /**  Sobrecarga del operador d asignacion */

        ConjuntosArreglos<T>& operator=(const ConjuntosArreglos<T>& other){
            int i;
            if (size>=other.size){
                numEle = other.numEle;
                for (i=0; i<numEle; i++)
                    conjunto[i]= other.conjunto[i];
            }
            return *this;
        }

        /** Observador del tamano del arreglo */

        int GetSize() { return size; }

        /** Observador del tamano del arreglo */

        int GetNumEle() { return numEle; }

        /** Transformador del tamano del arreglo */

        void SetNumEle(int val) { numEle = val; }

        /** busqueda de un elemento en el conjunto */

        T* search(const T ele){

            int i;
            T* retVal=NULL;

            for(i=0;i<numEle;i++)
                  if (conjunto[i]==ele)
                    retVal= &conjunto[i];  // encontrado

            return retVal;
        }

        /** verifica que el conjunto este vacio*/

        bool isEmpty(){return numEle==0;}


        /** busqueda de un elemento en una posici'on */

        T* searchInPos(const int pos){

            T* retVal=NULL;
            if (pos<numEle)
                retVal= &conjunto[pos];

            return retVal;
        }

        /** inseta ele en el conjunto*/

        void insert(T ele){

            if (numEle<size){
               conjunto[numEle]=ele;
               numEle++;
            }
            return;
        }

	void insertInPos(int pos, const T& ele){	// esto es mio. Victor

            if (numEle<size){
               conjunto[pos]=ele;
               numEle++;
            }
            return;

         /** elimina ele en el conjunto*/

	T* remove(const T ele){

            int pos;
            T* retVal=NULL;

            pos = searchPos(ele);
            if (pos<numEle){
                swap(pos,numEle-1);
                numEle--;
                retVal=&conjunto[numEle];
            }
            return retVal;
        }

       /** Parte el conjunto en dos subconjuntos. Se pica a partir de la pos */

        void split(int pos, ConjuntosArreglos<T>& arLeft, ConjuntosArreglos<T>& arRight){
           int i;
           if (pos>=numEle) return;

           for (i=0; i<pos; i++)
              arLeft.conjunto[i]=conjunto[i];

           for (i=0; i+pos<numEle; i++)
              arRight.conjunto[i]=conjunto[i+pos];
           arLeft.numEle=pos;
           arRight.numEle=numEle-pos;
           numEle=0;
           return;
        }

        /** Une el conjunto arRight a This */

        void merge(ConjuntosArreglos<T>& arRight){
            int i;

            if (numEle+arRight.numEle>size) return;
            if (numEle==0 && arRight.numEle==0) return;
            if (numEle==0 || arRight.numEle==0) {
                if (arRight.numEle==0) return;
                else{
                   for (i=0;i<arRight.numEle;i++)
                       conjunto[i]=arRight.conjunto[i];
                   numEle=arRight.numEle;
                   arRight.numEle=0;
                   return;
                }
            }
            for (i=0;i<arRight.numEle;i++)
                conjunto[numEle+i]=arRight.conjunto[i];
            numEle+=arRight.numEle;
            arRight.numEle=0;

            return;
        }


    protected:

        /** Busca en que posici'on se encuentra un elemento */

        int searchPos(T ele){
            int i;

            for(i=0;i<numEle;i++)
                  if (conjunto[i]==ele)
                    break;  // encontrado

            return i;
        }

        void swap(int i, int j){

            T auxiliar;

            auxiliar = conjunto[i];
            conjunto[i]=conjunto[j];
            conjunto[j]=auxiliar;
            return;
        }

        /** Transformador*/
        void SetSize(int val) { size = val; }
        /** Access numEle
         * \return The current value of numEle
         */




};

#endif // CONJUNTOSARREGLOS_H
