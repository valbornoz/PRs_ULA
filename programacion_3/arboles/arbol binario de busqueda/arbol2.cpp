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
    int pos;
    int preorden[5]={13,12,16,15,18};
    int inorden[5]={12,13,15,16,18};

    BinTree<int> prueba;
    BinNode<int> node;
    BinNode<int>* nodeAux;


    cout<<" "<<endl;
    prueba.buildBinTree(preorden,0,4,inorden,0,4);

    BinBusTree<int> pruebaBus;

	pruebaBus.copy(prueba);

pos=pruebaBus.inorden(imprime);



	return 0;
}
