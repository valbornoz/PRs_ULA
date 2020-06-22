#include<iostream>
#include<string>
using namespace std;

class materia{

	private:

	string nombrema;
	string nombrepr;
	string apellidopr;
	string aula;
        int nrosec;
        int nroest;

	public:

	
	materia();//CONSTRUCTOR POR OMISION O DEFECTO 
	materia(string, string, string, string, int ns, int ne);//CONSTRUCTOR PARAMETRICO
	void setnombrema(string);
        void setnombrepr(string);
        void setapellidopr(string);
        void setaula(string);
        void setnrosec(int);
        void setnroest(int);
	string getnombrema();
        string getnombrepr();
        string getapellidopr();
        string getaula();
        int getnrosec();
        int getnroest();
	void lectura(string, string, string, string, int ns, int ne);
	void mostrar();
        ~materia();
};

  
