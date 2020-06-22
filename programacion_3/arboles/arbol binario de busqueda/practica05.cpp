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
    int preorden[9]={6,3,2,1,5,4,10,13,12};
    int inorden[9]={1,2,3,5,4,6,10,12,13};
    BinBusTree<int> prueba, prueba2, prueba3;
    BinNode<int>* nodeAux;

    cout<<" "<<endl;
	prueba2.buildBusTree(preorden,0,8);
	prueba.buildBinTree(preorden,0,8,inorden,0,8);
	prueba3.buildBusTree2(preorden,0,8);

/*	cout<<"bin"<<endl;
	prueba.preorden(imprime);
	cout<<"bus"<<endl;
	prueba2.preorden(imprime);
	cout<<"bus2"<<endl;
	prueba3.preorden(imprime);

	cout<<"bin"<<endl;
	prueba.inorden(imprime);
	cout<<"bus"<<endl;
	prueba2.inorden(imprime);
	cout<<"bus2"<<endl;
	prueba3.inorden(imprime);

	cout<<"bin"<<endl;
	prueba.postorden(imprime);
	cout<<"bus"<<endl;
	prueba2.postorden(imprime);
	cout<<"bus2"<<endl;
	prueba3.postorden(imprime);*/

	prueba3.preorden(imprime);

	nodeAux=new BinNode<int>(2);
	prueba3.insertRoot(nodeAux);

	prueba3.preorden(imprime);
}
