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
    int inorden[5]={19, 20, 21, 22, 1};

    BinTree<int> prueba;
    BinNode<int> node;
    BinNode<int>* nodeAux, *loco, *n4, *n2, *n3;

    BinBusTree<int> pruebaAux;
    BinBusTree<int> pruebaBus;


        loco=new BinNode<int>(preorden[0]);
	nodeAux=new BinNode<int>(preorden[1]);
	n2=new BinNode<int>(preorden[2]);
	n3=new BinNode<int>(preorden[3]);
	n4=new BinNode<int>(preorden[4]);

	RLINK(n2)=n3;
	LLINK(n2)=n4;
	LLINK(loco)=n2;
	RLINK(loco)=nodeAux;
	
        pruebaAux._insertPreABB(loco); 
            cout<<"Inserto  "<<KEY(loco)<<endl;

cout<<"pruebaAux"<<endl;
pos=pruebaAux.inorden(imprime);

        loco=new BinNode<int>(inorden[0]);
	nodeAux=new BinNode<int>(inorden[1]);
	n2=new BinNode<int>(inorden[2]);
	n3=new BinNode<int>(inorden[3]);
	n4=new BinNode<int>(inorden[4]);

	RLINK(n2)=n3;
	LLINK(n2)=n4;
	LLINK(loco)=n2;
	RLINK(loco)=nodeAux;
	
        pruebaBus._insertPreABB(loco); 
            cout<<"Inserto  "<<KEY(loco)<<endl;

cout<<"pruebaBus"<<endl;
pos=pruebaBus.inorden(imprime);


cout<<endl<<"JOIN"<<endl<<endl;

pruebaBus.joinABB(pruebaAux);
		pos=pruebaBus.preorden(imprime);

cout<<endl<<"pureba del DELETEC"<<endl<<endl;

	pruebaBus.deleteABB(n4);

	pos=pruebaBus.preorden(imprime);

	return 0;
}
