#include <iostream>
#include "cadena.h"

cadena::cadena() {
	tamano = 0;
	c = NULL;
}

cadena::cadena(int t) {
	c = new char[t+1];
	tamano = t;
}

cadena::cadena(char * txt) {
	int i;

	tamano=0;
	while(txt[tamano]!='\0')
		tamano++;

	c = new char[tamano+1];

	for(i=0;i<tamano;i++)
		c[i] = txt[i];
	c[i] = '\0';
}

void cadena::mostrar() {
	cout << c;
}

cadena::~cadena() {
   if (tamano>0) 
   	delete [] c;
}

int cadena::operator==(char * txt) {
	for(int i=0;i<=tamano;i++) {
		if(c[i]!=txt[i])
			return 0;
	}
	return 1;
}

int cadena::longitud() {
	return(tamano);
}

void cadena::operator=(char * txt) {
	int n=0,i=0;

   if (tamano>0)
   	delete [] c;
   	
	while(txt[n]!='\0')
		n++;

	c = new char[n+1];
	for(i=0;i<=n;i++) {
		c[i] = txt[i];
	}

	tamano = n;
}

void cadena::operator=(char * txt) {
	int n=0,i=0;

   if (tamano>0)
   	delete [] c;
   	
	while(txt[n]!='\0')
		n++;

	c = new char[n+1];
	for(i=0;i<=n;i++) {
		c[i] = txt[i];
	}

	tamano = n;
}

void cadena::operator+(char * txt) {
	int n=0,i=0,j=0;
	char *cadNueva;

	while(txt[n]!='\0')
		n++;

   cadNueva = new char[tamano+n+1];

	for(i=0;i<tamano;i++) {
		cadNueva[i] = c[i];
	}

	for(j=0;j<n;j++) {
		cadNueva[i] = txt[j];
		i++;
	}
	cadNueva[i] = '\0';
	if (tamano>0)
	   delete [] c;
	c = cadNueva;
	tamano = i;
}
   
