#include <iostream>
#include "binNode.h"
#include "stack.h"
//#include "queve.h"
#include "Queve.h"



using namespace std;

int main(){
/*
	Queve<int> Q;
	int a=4;
	Q.put(4);
	cout<<"get: "<<Q.get()<<endl;
	cout<<"get: "<<Q.get()<<endl;
	Q.put(1);Q.put(3);Q.put(5);Q.put(6);Q.put(7);Q.put(8);Q.put(9);
	cout<<"get: "<<Q.get()<<endl;
	cout<<"Head: "<<Q.Head()<<endl;
	cout<<"Head: "<<Q.Head()<<endl;
	cout<<"get: "<<Q.get()<<endl;
*/
	cout<<endl<<"Queve:"<<endl;
	Queve<int> Q2;
	int a=4;
	Q2.put(4);Q2.put(1);Q2.put(3);
	cout<<"get: "<<Q2.get()<<endl;
	cout<<"get: "<<Q2.get()<<endl;
	Q2.put(5);Q2.put(6);Q2.put(7);Q2.put(8);Q2.put(9);
	cout<<"get: "<<Q2.get()<<endl;
	cout<<"Head: "<<Q2.Head()<<endl;
	cout<<"Head: "<<Q2.Head()<<endl;
	cout<<"get: "<<Q2.get()<<endl;

	return 0;
}
