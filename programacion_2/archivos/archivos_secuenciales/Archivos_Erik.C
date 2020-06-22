#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	ofstream arch;
	arch.open("usuario.txt",ios::app);
	if(!arch)
	{
		cout <<"Error"<<endl;
	}
	else
	{
		arch<<"Erik"<<"#"<<"Velasquez"<<"#"<<"4"<<" "<<"5"<<" "<<"7"<<endl;
		
		
		arch.close();
	}
	
	ifstream buscar;
	buscar.open("usuario.txt");
	if(!buscar)
	{
	}
	else
	{
		string nom;
		string apell;
		//string dato;
		int dato;
		int a1,a2;
		string enter;
		
		while(getline(buscar,nom,'#') and getline(buscar,apell,'#') and buscar>>dato and buscar>>a1 and buscar>>a2 and getline(buscar,enter))//(getline(burcar,dato)))
		{
			//int x = atoi(dato);
			//cout<<nom<<" "<<apell<<" "<<dato<< a1<<a2<<endl;
			if(dato == 1 and a1==2)
			{
				cout<<nom<<" "<<apell<<" "<<dato<< a1<<a2<<endl;
			}
			
		}
		
		buscar.close();
	}
	
	
	
	//modificar
	
	//erik -> pedro;
	
	string modi = "pedro";
	
	ifstream leer;
	leer.open("usuario.txt");
	if(!leer)
	{
	}
	else
	{
		ofstream escri;
		escri.open("aux.txt");
		if(!escri)
		{
		}
		else
		{
			string nom;
			string apell;
			//string dato;
			int dato;
			int a1,a2;
			string enter;
			while(getline(leer,nom,'#') and getline(leer,apell,'#') and leer>>dato and leer>>a1 and leer>>a2 and getline(leer,enter))//(getline(burcar,dato)))
			{
				if(nom != "Erik")
				{
					escri<<nom<<"#"<<apell<<"#"<<dato<<" "<<a1<<" "<<a2<<endl;
				}
				else
				{
					escri<<modi<<"#"<<apell<<"#"<<dato<<" "<<a1<<" "<<a2<<endl;
				}
				
			}
			
			
			escri.close();
		}
		
		
		leer.close();
	}

	ifstream leer1;
	leer1.open("aux.txt");
	if(!leer1)
	{
	}
	else
	{
		ofstream escri;
		escri.open("usuario.txt");
		if(!escri)
		{
		}
		else
		{
			string nom;
			string apell;
			//string dato;
			int dato;
			int a1,a2;
			string enter;
			while(getline(leer1,nom,'#') and getline(leer1,apell,'#') and leer1>>dato and leer1>>a1 and leer1>>a2 and getline(leer1,enter))//(getline(burcar,dato)))
			{
				escri<<nom<<"#"<<apell<<"#"<<dato<<" "<<a1<<" "<<a2<<endl;
			}
			
			
			escri.close();
		}
		
		
		leer1.close();
	}
	//fin modificar
	
	
	
	
	
return 0;
}
