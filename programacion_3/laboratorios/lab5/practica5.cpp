#include <iostream>
#include "binNode.h"
#include "binTree.h"
#include "binBusTree.h"


using namespace std;

void imprime(BinNode<int>* aux,int level,int pos){

    cout<<" Clave "<<KEY(aux)<<" Pos "<<pos<<endl;
}

void imprimeRango(BinNode<int>* aux, int min, int pos, int max){

	if(KEY(aux)>=min and KEY(aux)<=max)
    cout<<" Clave "<<KEY(aux)<<" Pos "<<pos<<endl;
}


int main()
{

    int preorden[29]={25,24,14,12,8,7,2,1,3,6,5,16,21,18,23,26,48,30,27,28,31,32,37,39,46,47,78,50,51};

    BinBusTree<int> pruebaBus;
	BinNode<int>* aux;
	int pos;


	pruebaBus.buildBusTree2(preorden,0,28);	// este metodo se encuentra  en binBusTree.h linea 190

	cout<<"funcionaria el builBusTree?"<<endl<<endl;

	pruebaBus.preorden(imprime);

	cout<<"valores del arbol entre 25 y 45"<<endl;

	pruebaBus.preordenRango(25,45,imprimeRango); // este metodo se encuentra en binTree.h linea 159

	cout<<endl<<"funcionara el findInPos?"<<endl;

	pos=(pruebaBus.cardinal())/2;
	aux=pruebaBus.findInPos(pos);	// este metodo se encuentra en binTree.h 178
	
	cout<<"este es el elemento en pos=(cardinalidad/2): "<<KEY(aux)<<endl;
	cout<<"pos: "<<pos<<endl;

	cout<<endl<<"colocar el elemento "<<KEY(aux)<<" en la raiz del arbol"<<endl;
	pruebaBus.insertRoot(aux);	// este metodo se encuentra en binBusTree.h linea 244
	pruebaBus.preorden(imprime);


	return 0;
}
