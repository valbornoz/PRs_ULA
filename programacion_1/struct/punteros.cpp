#include <iostream>

using namespace std;

struct punto{
	int* x;
	int* y;
};


int main(){

	punto p1;
	int z=6;

	punto* p2;
	punto* p3;

	p1.x=&z;

	p2=&p1;
	p3=p2;

	cout<<"coordenada x: "<<p1.x<<endl;
	cout<<"valor de z: "<<*(p1.x)<<endl;
	cout<<"p2: "<<p2<<endl;
	cout<<"p3: "<<p3<<endl;

	cout<<"z con p2: "<<*(p2->x)<<endl;


	return 0;
}
