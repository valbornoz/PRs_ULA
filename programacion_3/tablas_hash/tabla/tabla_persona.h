#include "tabla_hash.h"
#include "persona.h"
#include <math.h>

 long convierte_ci(const Persona&);

class tabla_persona: public tabla_hash<Persona> {	
public:
	tabla_persona(){};
	tabla_persona( long);
	~tabla_persona(){}
	 long hash(const Persona& p);
	void imprime();
};


tabla_persona::tabla_persona( long n) : tabla_hash<Persona>(n){}


 long tabla_persona::hash(const Persona& p) {
	return ( convierte_ci(p) % tam);
}


 long convierte_ci(const Persona& p) {
	Cadena ci;
	 long res = 0;

	ci = p.get_ci();
	for(int i=0; i < ci.longitud(); i++)
		res += ( long)pow((double)ci.getch(i), (double)2);

	return res;
}
	

void tabla_persona::imprime() {
	for( long i = 0 ; i < tam ; i++) {
		cout << "\n" << i << ":" ;
		v[i].imprime();
	}
}