#include "iostream"

using namespace std;

int main(){

	char nombre[20],s;
	int i=0;

	cout << "escriba su nombre: " << endl;
	cin >> nombre;

	while(s!='\0'){
		s=nombre[i];
		i++;
	}

	cout<<"su nombre tiene "<<i-1<<" letras"<<endl;

		return 0;
}
