#include <iostream>
#include "binNode.h"
#include "binTree.h"
#include "binBusTree.h"


using namespace std;

void imprime(BinNode<int>* aux,int level,int pos){

    cout<<" Clave "<<KEY(aux)<<" Pos "<<pos<<endl;
}

int main()
{
    int preorden[5]={13,12,16,15,18};
    int inorden[5]={12,13,15,16,18};
    BinTree<int> prueba;
    BinBusTree<int> pruebaAux;
    int pos;
    BinNode<int> node;
    BinNode<int>* nodeAux;

    node.setKey(10);
    nodeAux=new BinNode<int>(20);
    cout<<" Nodo  "<<node.getKey()<<endl;
    cout<<" Nodo Aux  "<<KEY(nodeAux)<<endl;

    cout<<" "<<endl;
    prueba.buildBinTree(preorden,0,4,inorden,0,4);


    cout<<" "<<endl;
    cout<<" PREORDEN "<<endl;
    pos=prueba.preorden(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN "<<endl;
    pos=prueba.inordenNRec(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN REC"<<endl;
    pos=prueba.inorden(imprime);
    cout<<" "<<endl;

    cout<<" POSTORDEN "<<endl;
    pos=prueba.postorden(imprime);

    pos=prueba.cardinal();
    cout<<" "<<endl;
    cout<<" Cardinalidad del arbol es = "<<pos<<endl;

    cout<<" "<<endl;
    cout<<" Altura del arbol es = "<<prueba.h()<<endl;

cout<<endl<<"rotate L:"<<endl<<endl;
	prueba.rotateLeft();

	
    cout<<" "<<endl;
    cout<<" PREORDEN "<<endl;
    pos=prueba.preorden(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN "<<endl;
    pos=prueba.inordenNRec(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN REC"<<endl;
    pos=prueba.inorden(imprime);
    cout<<" "<<endl;

    cout<<" POSTORDEN "<<endl;
    pos=prueba.postorden(imprime);

    pos=prueba.cardinal();
    cout<<" "<<endl;
    cout<<" Cardinalidad del arbol es = "<<pos<<endl;

    cout<<" "<<endl;
    cout<<" Altura del arbol es = "<<prueba.h()<<endl;

cout<<endl<<"rotate R:"<<endl<<endl;
	prueba.rotateRight();

	
    cout<<" "<<endl;
    cout<<" PREORDEN "<<endl;
    pos=prueba.preorden(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN "<<endl;
    pos=prueba.inordenNRec(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN REC"<<endl;
    pos=prueba.inorden(imprime);
    cout<<" "<<endl;

    cout<<" POSTORDEN "<<endl;
    pos=prueba.postorden(imprime);

    pos=prueba.cardinal();
    cout<<" "<<endl;
    cout<<" Cardinalidad del arbol es = "<<pos<<endl;

    cout<<" "<<endl;
    cout<<" Altura del arbol es = "<<prueba.h()<<endl;

}
