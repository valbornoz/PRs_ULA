#include <iostream>
#include "binNode.h"
#include "binTree.h"


using namespace std;

void imprime(BinNode<int>* aux,int level,int pos){

    cout<<" Clave "<<KEY(aux)<<" Pos "<<pos<<endl;
}

void SinPares(BinNode<int>* aux,int level,int pos){

	if(KEY(aux)%2 != 0)
    cout<<" Clave "<<KEY(aux)<<" Pos "<<pos<<endl;
}


int main()
{

    int postorden[13]={10, 11,  9, 12, 13, 8, 15, 18, 17, 19, 16, 14, 5};
    int inorden[13]={9, 10, 11,  8, 12, 13, 5, 14, 15, 16, 17, 18, 19 };
    BinTree<int> prueba;
    int pos;

    cout<<" "<<endl;
    prueba.buildPosTree(postorden,0,12,inorden,0,12);


    cout<<" "<<endl;
    cout<<" PREORDEN "<<endl;
    pos=prueba.preorden(imprime);

    cout<<" "<<endl;
    cout<<" INORDEN "<<endl;
    pos=prueba.inordenNRec(imprime);

    cout<<" "<<endl;
    cout<<" POSTORDEN "<<endl;
    pos=prueba.postorden(imprime);

// sin pares
    cout<<endl<<"ahora sin numeros pares"<<endl;
    cout<<" "<<endl;
    cout<<" PREORDEN "<<endl;
    pos=prueba.preorden(SinPares);

    cout<<" "<<endl;
    cout<<" INORDEN "<<endl;
    pos=prueba.inordenNRec(SinPares);

    cout<<" "<<endl;
    cout<<" POSTORDEN "<<endl;
    pos=prueba.postorden(SinPares);


    return 0;


}
