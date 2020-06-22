#ifndef BINTREE_AVL_H
#define BINTREE_AVL_H
#include <stack.h>
#include <binNodeAVL.h>
#include <binTree.h>

Template <class T>
class BinTree_AVL : public BinTree
{
    public:
        BinTree_AVL() {}
        virtual ~BinTree_AVL() {}
        BinTree_AVL(const BinTree_AVL& other) {}
        BinTree_AVL& operator=(const BinTree_AVL& other) { return *this; }
        unsigned int GetCounter() { return m_Counter; }
        void SetCounter(unsigned int val) { m_Counter = val; }

        void insertABB(T clave ){
            Stack< BinNodeAVL<T>* >  camino;
            BinNodeAVL<T>*  nod, *aux, *aux1, *auxNod;

            if (root ==  NULL) {   //  arbol vacio
               root = new BinNodeAvl<T>(clave);
               return;
            }
            aux = root;
            while (aux != NULL){  // busca y guarda el camino de inserci'on
              if ( KEY(aux)== clave ) return;
              camino.push(aux);
              if  (KEY(aux) > clave)
                 aux=LLINK(aux):
              else
                 aux=RLINK(aux);
            }

            // inserta nuevo nodod
            nod= new BinNodeAvl<T>(clave);
            aux=camino.pop();
            if (KEY(aux) > clave) {
              LLINK(aux)=nod;
              DIFF(aux)-=1; }
            else{
              RLINK(aux)=nod;
              DIFF(aux)+=1; }


            // actualizo  diferencia en el camino de inserci'on
            nod=aux;
            while (!camino.isEmpty()){
               aux=camino.pop()
               if (KEY(aux) > KEY(nod))
                  DIFF(aux)-=1;
               else
                  DIFF(aux)+=1;
               if (DIFF(aux) == 2) !! (DIFF(aux)==-2){

                  nod= equilibrioAVL(aux, nod);

                  if (!camino.isEmpty()){
                    aux=camino.pop();
                    if (KEY(aux) > KEY(nod)) {
                       LLINK(aux)=nod;
                       DIFF(aux)-=1; }
                    else{
                       RLINK(aux)=nod;
                       DIFF(aux)+=1; }
                  }
                   else
                      root= nod;
                   return;
               }

               nod=aux;
            }

         return;
        }
    protected:
    private:

        equilibrioAVL(BinNodeAvl<T>* aux, BinNodeAvl<T>* nod ){

            BinNodeAvl<T>* aunNod;

            if (DIFF(aux)==2) && (DIFF(nod)>=0){
                 auxNod=rotar_izquierda(aux);
                 balanceNodos;
                 return;}
            else if (DIFF(aux)==2) && (DIFF(nod)==-1){
                   RLINK(aux)= rotar_derecha(nod);
                   auxNod=rotar_izquierda(aux);
                   balanceNodos; }
                 else if (DIFF(aux)==-2) && (DIFF(nod)<=0){
                        auxNod=rotar_derecho(aux);
                        balanceNodos;}
                      else if (DIFF(aux)==-2) && (DIFF(nod)==1){
                              LLINK(aux)= rotar_izquierda(nod);
                              auxNod=rotar_derecha(aux);
                              balanceNodos;}

             return auxNode;
        }
        unsigned int m_Counter;
};

#endif // BINTREE_AVL_H
