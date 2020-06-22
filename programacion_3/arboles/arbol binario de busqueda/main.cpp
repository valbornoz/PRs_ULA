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
    int preorden[8]={5,8,4,6,3,9,2,1};
    int inorden[8]={6,4,8,3,5,2,9,1};
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
    prueba.buildBinTree(preorden,0,7,inorden,0,7);


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

    pos=5;
    cout<<" BINARIO DE BUSQUEDA "<<endl;

    nodeAux=pruebaAux.searchABB(pos);
    if (nodeAux!=NULL)
        cout<<"  encontro  "<<KEY(nodeAux)<<endl;
    else
        cout<<" NO  encontro  "<<endl;
    int i=0;
    while (i<8){
        nodeAux=new BinNode<int>(preorden[i]);
        cout<<" Nodo a insertar "<<KEY(nodeAux)<<endl;
        if (pruebaAux.insertABB(nodeAux))
            cout<<"Inserto  "<<KEY(nodeAux)<<endl;
        i++;
    }

    cout<<" "<<endl;
    cout<<" INORDEN REC"<<endl;
    pos=pruebaAux.inorden(imprime);
    cout<<" "<<endl;
    return 0;


}
