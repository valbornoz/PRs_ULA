//Clase polinomio Realizada por Erik Velasquez
#include<iostream>
using namespace std;

//declaracion de estructuras internas de la clase

//estructura Cadena que contiene los atributos de un factor del polinomio y
//es recursiva para poder referenciarse a si misma.
struct cadena
{	
	//exponente
	int exp;
	//coeficiente
	float coef;
	//llamada asi mismo
	struct cadena *nex;
};

//instanciamos la estructura en forma universal para toda la clase
typedef struct cadena *po;


//clase polinomio
class polinomio
{
	//atributos privados internos propios del polinomio
	private:
		po inicio;//puntero al primer termino del polinomio
		po fin;//puntero al ultimo termino del polinomio

	//miembros metodos de la clase
	public:
		void crearpolinomio();
		void crearcadena(float,int);//crea un termino del polinomio
		polinomio multiplicar_constante(float);//multiplica una constante por el polinomio y devuelve el polinomio resultante
		void imprimir_polinomio();//imprime por pantalla el polinomio.
		friend ostream & operator << (ostream &, polinomio); //sobreescritura del operador de salida
		polinomio devolver_suma(polinomio, polinomio);
		friend polinomio operator +(polinomio,polinomio);//sobrecarga del operador de suma
		~polinomio(){};


};//end clase polinomio


void polinomio::crearpolinomio()
{
	//declaracion de variable sinternas
	float coe;
	int ex, n, i;
	//inicializamos en nulo el fin del polinomio
	fin = NULL;
	do
	{
		cout<<"Ingrese el numero de terminos del polinomio: ";
		cin>>n;
	}
	while(n<=0);
	//para cada termino creamos su cadena
	for(i=0;i<n;i++)
	{
		cout<<"Ingrese Coeficiente: ";
		cin>>coe;
		cout<<"Ingrese Exponente: ";
		cin>>ex;
		//llamamos al metodo que crea la cadena de cada termino
		crearcadena(coe,ex);
	}

}//fin crearpolinomio


 void polinomio::crearcadena(float coef,int exp)
{
	po x; //nuevo termino;
	x = new cadena; // asignacion memoria dinamica
	//almacenar datos
	x->coef = coef;
	x->exp = exp;
	x->nex = NULL;
	//comparamos el final de cadena
	if (fin == NULL)
	{
		//al inicio le asignamos el termino
		inicio = x;
	}
	else
	{
		//al atributo recursivo le asignamos el termino
		fin->nex = x;
	}
	//el final le asignamos el termino
	fin = x;

}//fin crearcadena

void polinomio::imprimir_polinomio()
{
	//declaracion de variables internas
	po poli;
	//inicializo poli con los datos del primer termino
	poli = inicio;
	cout<<"\nP(x) = ";
	//mientras no consigamos el termino sin nada
	while(poli != NULL)
	{
		//evaluamos para imprimir el ultimo termino
		if(poli -> exp == 0)
		{
			cout<< poli->coef;
		}
		else
		{
			cout<<poli->coef<<"x^"<<poli->exp<<" + ";
		}
		//le damos a poli el termino que le sigue en la cadena
		poli = poli->nex;
	}
	cout<<endl;
}//fin imprimir_polinomio


polinomio polinomio::devolver_suma(polinomio a, polinomio b)
{
	//declaracion de variables internas
	float c;
	po p,q;
	p=a.inicio;
	q=b.inicio;
	fin=NULL;
	while(p != NULL && q != NULL)
	{
		if(p->exp == q->exp)
		{
			c=p->coef + q->coef;
			if(c!=0)
			{
				crearcadena(c,p->exp);
			}
			p=p->nex;
			q=q->nex;
		}
		else
		{
			if(p->exp>q->exp)
			{
				crearcadena(p->coef,p->exp);
				p=p->nex;
			}
			else
			{
				crearcadena(q->coef,q->exp);
				q=q->nex;
			}
		}
	}
	while( p != NULL)
	{
		crearcadena(p->coef, p->exp);
		p = p->nex;
	}
	while( q != NULL)
	{
		crearcadena(q->coef, q->exp);
		q = q->nex;
	}	
return *this;
}//fin


ostream & operator << (ostream &, polinomio a)
{
	a.imprimir_polinomio();

}//sobrecarga del <<


polinomio operator +(polinomio a,polinomio b)
{
	a.devolver_suma(a,b);
	return a;

}//sobrecarga del operador +


