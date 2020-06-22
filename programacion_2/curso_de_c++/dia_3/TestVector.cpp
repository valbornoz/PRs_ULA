#include<iostream>
#include"Vector.h"
using namespace std;

int main()
{
	Vector<int> vector;
	int a=4;
	int b=5;
	for(int i=0;i<10;i++)
	{
		vector.insert(i);
	}
	
	vector.removeLast();
	vector.remove(a);
	vector.remove(b);
	for(int i=0;i<vector.getSize();i++)
	{
		cout<<vector[i]<<endl;
	}

return 0;
}


