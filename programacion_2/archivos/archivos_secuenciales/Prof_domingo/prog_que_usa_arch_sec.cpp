// Ejemplo que muestra el uso de un archivo secuencial.

#include<iostream.h>
#include<string.h>
#include"datos_basicos.h"
#include"archivo_secuencial_parametrico.h"
void main (){
	persona q,p;
	archivo_sec <persona> datos_personales;
	datos_personales.crear("curso_pdii.dat");
	cout << "\n" << "Entrada de dato por re-escritura del operador cin" << "\n";
	cin >> q;
	datos_personales.escribir(q);
	datos_personales.cerrar();
    	// Declaración de un archivo secuencial de enteros
	archivo_sec <int> datos_enteros;
	p.asigna_nombre("Carlos");
	if (p < q)
		cout << "si es menor";
	
}
