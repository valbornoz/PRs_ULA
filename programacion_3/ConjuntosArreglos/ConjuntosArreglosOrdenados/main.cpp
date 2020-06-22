#include <iostream>
#include <assert.h>
#include "arregloOrd.h"

using namespace std;

int main()
{

    ArregloOrd<int>  contPrueba;
    int ele;
    int i;
    ArregloOrd<int>  contPrueba2(5);


// test 1
    ele=14;
    assert(contPrueba.searchPos(ele)==contPrueba.getNumEle());
//        cout<< "OK"<<endl;
//    else
//        cout<<"No OK"<<endl;

// test 2
    ele=10;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==0)
        cout<< "2 OK"<<endl;
    else
        cout<<"No OK"<<endl;


// test 3
    ele=26;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==1)
        cout<< "3 OK"<<endl;
    else
        cout<<"No OK"<<endl;

// test 4
    ele=14;
    if  (*contPrueba.searchInPos(contPrueba.searchPos(ele))!=ele)
        cout<< "4 OK"<<endl;
    else
        cout<<"No OK"<<endl;

// test 5
    ele=14;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==1)
        cout<< "5 OK "<<endl;
    else
        cout<<"No OK"<<endl;

// test 6
    ele=26;
    int* ele3;
    ele3=contPrueba.search(ele);
    if (*ele3==ele)
       cout<< "6 OK"<<endl;
    else
        cout<<"No OK"<<endl;


// test 7
    ele=27;
    ele3=contPrueba.search(ele);
    if (ele3==NULL)
       cout<< "7 OK"<<endl;
    else
        cout<<"No OK"<<endl;

    cout<<endl;
    cout<<endl;
    for (i=0;i<contPrueba.getNumEle();i++){
        cout<<"contPrueba  =  "<<*(contPrueba.searchInPos(i))<<endl;
     }
    cout<<endl;

// test 8
    int* ele2;
    ele=26;
    ele2=contPrueba.remove(ele);
    if (*ele2==26)
      cout<< "8 OK "<<endl;
    else
        cout<<"No OK es "<<ele2<<endl;

// test 9
    ele=44;
    ele2=contPrueba.remove(ele);
    if (ele2==NULL)
      cout<< "9 OK "<<endl;
    else
        cout<<"No OK"<<endl;

    cout<<endl;
    cout<<endl;
    for (i=0;i<contPrueba.getNumEle();i++){
        cout<<"contPrueba  =  "<<*(contPrueba.searchInPos(i))<<endl;
     }
    cout<<endl;

// test 10
    i=0;
    int* ele4;
    ele4=contPrueba.searchInPos(i);
    if (*ele4==10)
      cout<< "10 OK"<<endl;
    else
        cout<<"No OK"<<endl;

// test 11
    i=1;
    ele4=contPrueba.searchInPos(i);
    if (*ele4==14)
      cout<< "11 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// test 12
    ele=10;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==0)
        cout<< "12 OK "<<endl;
    else
        cout<<"No OK"<<endl;

// test 13
    ele=18;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==2)
        cout<< "13 OK "<<endl;
    else
        cout<<"No OK"<<endl;

// test 14
    ele=15;
    contPrueba.insert(ele);
    if  (contPrueba.searchPos(ele)==2)
        cout<< "14 OK "<<endl;
    else
        cout<<"No OK"<<endl;

    cout<<endl;
    cout<<endl;
    for (i=0;i<contPrueba.getNumEle();i++){
        cout<<"contPrueba  =  "<<*(contPrueba.searchInPos(i))<<endl;
     }
    cout<<endl;

// test 15
    for (i=0;i<5;i++){
        contPrueba2.insert(i+6);
    }
    if (contPrueba2.searchPos(6)==0)
     cout<< "15 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// test 16
    if (contPrueba2.searchPos(50)==5)
     cout<< "16 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// test 17
    contPrueba2.insert(60);
    if (contPrueba2.searchPos(60)==5)
     cout<< "17 OK"<<endl;
    else
      cout<<"No OK"<<endl;


// test 18
    ArregloOrd<int> arLeft;
    ArregloOrd<int> arRight;
    contPrueba2.splitByPos(3,arLeft,arRight);
    if ((arLeft.getNumEle()==3) &&(arRight.getNumEle()==2))
     cout<< "18 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// esto no es na prueba solo muestras los dos contenedores resultado de la particion

    cout<<endl;
    for (i=0;i<arLeft.getNumEle();i++){
        cout<<"arLeft  =  "<<*(arLeft.searchInPos(i))<<endl;
     }
    cout<<endl;
    cout<<endl;
    for (i=0;i<arRight.getNumEle();i++){
        cout<<"arRight  =  "<<*(arRight.searchInPos(i))<<endl;
     }


// test 19
    for (i=0;i<5;i++){
        contPrueba2.insert(i+15);
    }
    if (contPrueba2.searchPos(15)==0)
     cout<< "19 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// test 20
    ArregloOrd<int> arLeft1;
    ArregloOrd<int> arRight1;
    contPrueba2.splitByKey(17,arLeft1,arRight1);
    if ((arLeft1.getNumEle()==2) &&(arRight1.getNumEle()==3))
     cout<< "20 OK"<<endl;
    else
      cout<<"No OK"<<endl;

// esto no es na prueba solo muestras los dos contenedores resultado de la particion

    cout<<endl;
    for (i=0;i<arLeft1.getNumEle();i++){
        cout<<"arLeft1  =  "<<*(arLeft1.searchInPos(i))<<endl;
     }
    cout<<endl;
    cout<<endl;
    for (i=0;i<arRight1.getNumEle();i++){
        cout<<"arRight1  =  "<<*(arRight1.searchInPos(i))<<endl;
     }


/*cout<<"Saliendo"<<endl;

//test 19
    cout<<endl;
    cout<<endl;
    arLeft.join(arRight);
    if ((arLeft.getNumEle()==5) &&(arRight.getNumEle()==0))
     cout<< "19 OK"<<endl;
    else
      cout<<"No OK"<<endl;
    cout<<endl;



// esto no es na prueba solo muestras los dos contenedores resultado del join

    for (i=0;i < arLeft.getNumEle();i++){
        cout<<"arLeft  =  "<<*(arLeft.searchInPos(i))<<endl;
     }
*/
}

