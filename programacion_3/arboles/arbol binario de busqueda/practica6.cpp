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

	int preorden[24]={30,23,11,5,8,6,9,15,12,17,16,29,24,28,25,49,33,44,40,47,55,50,53,68}; 
	BinBusTree<int> pruebaBus;
	BinBusTree<int> arbolIzquierdo, arbolDerecho;


	pruebaBus.buildBusTree(preorden,0,23);
	pruebaBus.preorden(imprime);

	pruebaBus.splitKey(26, arbolIzquierdo, arbolDerecho);

	arbolIzquierdo.preorden(imprime);
	arbolDerecho.preorden(imprime);

	return 0;
}
