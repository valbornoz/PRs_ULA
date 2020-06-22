#include <iostream>
#include "Dnode.h"
#include "Dlist.h"

using namespace std;

int main()
{


    Dlist<int> laux;
    Dlist<int> left;
    Dlist<int> right;
    Dnode<int>* nodPrueba;
    Dnode<int>* nodPrueba2;
    Dnode<int>* nod;
    int i;


    //test 0
    if (laux.isEmpty())
        cout << " 0 OK "<<endl;
    else
        cout << " 0 NO OK "<<endl;

    //test 1
    nodPrueba=new Dnode<int>(1);
    laux.insert(nodPrueba);
    if (nodPrueba==laux.getFirst())
        cout << " 1 OK "<<endl;
    else
        cout << " 1 NO OK "<<endl;

     //test 2
    nodPrueba2=new Dnode<int>(6);
    laux.append(nodPrueba2);
    if(nodPrueba2==laux.getLast())
        cout << " 2 OK "<<endl;
    else
        cout << " 2 NO OK "<<endl;

     //test 3
    nodPrueba2=new Dnode<int>(2);
    laux.getFirst()->insert(nodPrueba2);
    if (nodPrueba2==laux.getFirst()->getNext())
        cout << " 3 OK "<<endl;
    else
        cout << " 3 NO OK "<<endl;

     //test 4
    nodPrueba2=new Dnode<int>(5);
    laux.getLast()->append(nodPrueba2);
    if (nodPrueba2==laux.getLast()->getPrev())
        cout << " 4 OK "<<endl;
    else
        cout << " 4 NO OK "<<endl;nod=laux.getFirst();

    //test 5
    nodPrueba2=new Dnode<int>(3);
    laux.getFirst()->getNext()->insert(nodPrueba2);;
    if (nodPrueba2==laux.getFirst()->getNext()->getNext())
        cout << " 5 OK "<<endl;
    else
        cout << " 5 NO OK "<<endl;

    //test 6
    nodPrueba2=new Dnode<int>(4);
    laux.getLast()->getPrev()->append(nodPrueba2);;
    if (nodPrueba2==laux.getLast()->getPrev()->getPrev())
        cout << " 6 OK "<<endl;
    else
        cout << " 6 NO OK "<<endl;

    nod=laux.getFirst();
    while (nod->getNext() != laux.getFirst()){
        cout << " imprimiendo " <<nod->getData()<<endl;
        nod=nod->getNext();
    }

    //test 7
    nod=laux.getFirst();
    nodPrueba=laux.removeFirst();
    if (nod==nodPrueba)
       cout << " 7 OK "<<endl;
    else
       cout << " 7 NO OK "<<endl;

    //test 8
    nod=laux.getLast();
    nodPrueba=laux.removeLast();
    if (nod==nodPrueba)
       cout << " 8 OK "<<endl;
    else
       cout << " 8 NO OK "<<endl;

    //test 9
    nod=laux.getFirst()->getNext();
    nodPrueba=laux.getFirst()->removeNext();
    if (nod==nodPrueba)
       cout << " 9 OK "<<endl;
    else
       cout << " 9 NO OK "<<endl;

    //test 10
    nod=laux.getLast()->getPrev();
    nodPrueba=laux.getLast()->removePrev();
    if (nod==nodPrueba)
       cout << " 10 OK "<<endl;
    else
       cout << " 10 NO OK "<<endl;

    nod=laux.getFirst();
    while (nod->getNext() != laux.getFirst()){
        cout << " imprimiendo " <<nod->getData()<<endl;
        nod=nod->getNext();
    }

    for (i=10;i>0;i--){
        nodPrueba2=new Dnode<int>(i);
        left.insert(nodPrueba2);
        if (i==5)
            nodPrueba = nodPrueba2;
    }

    cout<<endl;
    cout<<endl;
    nod=left.getFirst();
    while (nod->getNext() != left.getFirst()){
        cout << " imprimiendo left " <<nod->getData()<<endl;
        nod=nod->getNext();

    }

    cout<<endl;
    cout<<endl;
    cout<<"IZQUIERDO hasta "<<nodPrueba->getData()<<endl;
    left.split(nodPrueba,right);
    nod=left.getFirst();
    while (nod->getNext() != left.getFirst()){
        cout << " imprimiendo left " <<nod->getData()<<endl;
        nod=nod->getNext();

    }
    cout<<endl;
    cout<<endl;
    cout<<"DERECHO "<<endl;
    cout<<endl;
    nod=right.getFirst();
    while (nod->getNext() != right.getFirst()){
        cout << " imprimiendo right " <<nod->getData()<<endl;
        nod=nod->getNext();

    }

    // COMO CONVERTIRLO EN UN TEST??
    return 0;
}
