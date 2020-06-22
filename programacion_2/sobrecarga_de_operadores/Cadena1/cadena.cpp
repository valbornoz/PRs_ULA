#include <iostream>
#include "cadena.h"

cadena::cadena() {
	tamano = 0;
	c= NULL;
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

cadena::~cadena() {
   if (tamano>0) 
   	delete [] c;
}

int cadena::comparar(char * txt) {
	for(int i=0;i<tamano;i++) {
		if(c[i]!=txt[i])
			return 0;
	}
	if(txt[tamano]!='\0')
		return 0;
	return 1;
}

int cadena::operator==(cadena cad1) {
	int i;

	if (longitud()!=cad1.longitud())
		return 0;

	for(i=0;i<tamano;i++) {
		if(c[i]!=cad1.c[i]) 
			return 0;
	}
	return 1;
}


void cadena::concatenar(char * txt) {
	int n=0,i=0,j=0;
	char *cadNueva;

	while(txt[n]!='\0')
		n++;

   cadNueva = new char[tamano+n+1];
	if (tamano>0) {
		for(i=0;i<tamano;i++) {
			cadNueva[i] = c[i];
		}
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

void cadena::operator+(char * txt) {
	concatenar(txt);
}

int cadena::asignar(char * txt) {
	int n=0,i=0;
	char *cadNueva;

   if (tamano>0)
   	delete [] c;
   	
	while(txt[n]!='\0')
		n++;

	cadNueva = new char[n+1];
	for(i=0;i<=n;i++) {
		cadNueva[i] = txt[i];
	}

	c = cadNueva;
	tamano = n;
}

int cadena::operator=(char * txt) {
	return asignar(txt);
}

void cadena::mostrar() {
	cout << c;
}



int cadena::longitud() {
        cout<<tamano;
	return(tamano);
}


void cadena::invertir() {
   char cAux;

   for(int i=0;i<(tamano/2);i++) {
      cAux = c[i];
      c[i] = c[tamano - i - 1];
      c[tamano - i - 1] = cAux;
   }
}

void cadena::operator!() {
   invertir();     
}

void cadena::mesh(char * txt) {
   int n=0,i=0,j=0,k=0;
	char *cadNueva;

	while(txt[n]!='\0')
		n++;

   cadNueva = new char[tamano+n+1];
   while(1) {
      if(i<tamano) {
         cadNueva[k] = c[i];
         i++;
         k++;
      }
      if(j<n) {
         cadNueva[k] = txt[j];
         j++;
         k++;
      }
      if((i>=tamano)&&(j>=n))
         break;
   }
	cadNueva[k] = '\0';
	if (tamano>0)
	   delete [] c;
	c = cadNueva;
	tamano = k;
}

void cadena::operator*=(char * txt) {
   mesh(txt);     
}
