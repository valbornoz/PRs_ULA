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
    int preorden[13]={5,8,9,11,10,13,12,14,16,15,19,17,18};
    int inorden[13]={9,10,11,8,12,13,5,14,15,16,17,18,19};
//    int preorden[6]={18,13,11,12,15,20};
//    int inorden[6]={11,12,13,15,18,20};
    int preorden2[6]={13,11,18,20,12,15};
    int inorden2[6]={18,20,11,12,13,15};

    BinBusTree<int> prueba, prueba1;
    BinNode<int> node;
    BinNode<int>* nodeAux;


    cout<<" "<<endl;
//    prueba.buildBinTree(preorden,0,12,inorden,0,12);
	prueba.buildBusTree(preorden,0,12);
    prueba1.buildBinTree(preorden2,0,5,inorden2,0,5);

	if(prueba.similitud(prueba1)) cout<<"los arboles son similares ";
	else
	cout<<"los arboles no son similares ";

	if(prueba.equivalencia(prueba1)) cout<<"y son equivalentes"<<endl;
	else
	cout<<"y no son equivalentes"<<endl<<endl;

	prueba.level();

	prueba.splitKey(11);

	return 0;
}


