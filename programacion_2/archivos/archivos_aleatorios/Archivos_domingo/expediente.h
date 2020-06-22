#include <ctype.h>
#include "archivo_secuencial.h"
#include "fecha.h"
int s = 0;


int  obtener_numero(int numero) {
archivo_sec<int> a("numero_expediente.dat");
a.crear();
if(numero == 0)
   {
       if(!a.fin())   s=1;
     else{
         numero++;
         a.insertar(numero);
         s=1;
         a.cerrar();
         return 1;
         }
     a.cerrar();
   }

if(s==1) {

  a.abrir(ios::in);

 while(!a.fin())
    a.leer(numero);

a.cerrar();
  numero = numero + 1;
  a.insertar(numero);
  a.cerrar();
}
  return numero;

 }
























class expediente {

protected:
                     int numero;
                     char cedula[10],estado[8];
                     short hijos;
                     fecha ingreso, becas,acenso[4];
public:
              expediente();
             ~expediente() {};
              void asigna_datos(); 
              void ingreso_datos(int, char *,char *, short , fecha &, fecha &, fecha&, fecha &, fecha&, fecha &);
              void ingresar_cedula(char *ci) { strcpy(cedula, ci); }
              char *get_estado() { return estado; }
              short get_hijos()  {return hijos; }
              int get_numero() { return numero; }
              char *get_cedula() { return cedula; }
              void agregar_hijos();
              void agregar_estado();
              void agregar_ingreso();
              void agregar_becas();
              fecha& get_ingreso() { return ingreso; }
              fecha& get_becas() { return becas; }
              fecha& get_acenso(int i) { return acenso[i]; }
              friend expediente &operator>>(istream &is, expediente &e); 
              friend ostream &operator<<(ostream &os, const expediente &e);
              void imprimir();
              void asigna_cedula();
              int operator == (const expediente &e);
              expediente& operator = (const expediente &e);
              int operator > (const expediente &e); 
              int operator < (const expediente &e);
 };


expediente :: expediente ()  {

    char *x="  ";
    strcpy(cedula,x); 
    strcpy(estado,x);
    hijos = 0;
    numero = 0;
 }



void expediente :: agregar_estado() {

 cout<<"El estado en que se encuentra es ( activo ):(a) o ( jubilado ):(j) ?"<<endl
         <<"Elija una opcion: ";
     char c;
     cin.get();
     c=cin.get();
     if(c=='a') strcpy(estado,"activo");
     if(c=='b') strcpy(estado,"jubilado");
}




void expediente :: agregar_hijos() {
  char aux[10];     
    
     cout<<"Cantidad de hijos: ";
     cin>>aux;
     hijos = (short)atoi(aux);
}

void expediente :: agregar_ingreso() {
char a;
int i;
     ingreso.ingreso();         
        a = 'a';
         for(i=0 ; i<4; i++)
          {
           acenso[i].acenso(a,ingreso);
           a = a + 1;
        }
}

void expediente :: agregar_becas() {

     becas.becas();
}



void expediente :: ingreso_datos(int num, char *ci, char *state, short h, fecha& ing, fecha& bec, fecha& ac1, fecha &ac2,fecha &ac3,fecha &ac4) { 
        numero = num;
        strcpy(cedula,ci);
        strcpy(estado, state);
        hijos = h;
        ingreso = ing;
        becas = bec;
        acenso[0] = ac1;
        acenso[1] = ac2;
        acenso[2] = ac3;
        acenso[3] = ac4;
   }


void expediente :: asigna_datos()  {

     asigna_cedula();
     agregar_estado();
     agregar_hijos();
     agregar_ingreso();
     agregar_becas();
     
     numero = obtener_numero(numero);
}









void expediente :: asigna_cedula() {
int x ;

do{
   x = 0;
   cout<<"Ingrese la cedula: V/E  ";
   cin>>cedula;

   for (int i = 0 ;!x && cedula[i] != '\0' ; i++)
     if(!isdigit(cedula[i])) { x = 1; cerr<<"\aERROR cedula mal ingresada... Intente de nuevo"<<endl; }

  }while(x!=0);
  

}

int expediente :: operator == (const expediente &e) {

     return( strcmp(cedula,e.cedula)==0 ); }

int expediente :: operator > (const expediente &e) {
   
    return( strcmp(cedula,e.cedula) > 0 ); }

int expediente :: operator < (const expediente &e) {

    return( strcmp(cedula,e.cedula) < 0 ); }

expediente &expediente :: operator = (const expediente &e) {

     strcpy(cedula,e.cedula);
     strcpy(estado,e.estado);
     hijos = e.hijos;
     ingreso = e.ingreso; 
     acenso = e.acenso;
     becas = e.becas;
     numero = e.numero;
     return (*this);
 }


ostream& operator << (ostream &os, const expediente &e) {

       os<<e.numero<<' '<<e.cedula<<' '<<e.estado<<' '<<e.hijos<<' '<<e.ingreso<<' ';
       for(int i=0; i<4; i++)
         os<<e.acenso[i]<<' ';
         os<<e.becas<<endl;
     
       return (os);
 }








expediente &operator >> (istream &is, expediente &e) {

  int count = 1;
  char c = ' ';

 while(c == ' ')
   {
     if(count == 1 )  is>>e.numero;
     if(count == 2 )  is>>e.cedula;
     if(count == 3 )  is>>e.estado;
     if(count == 4 )  is>>e.hijos;
     if(count == 5 )  is>>e.ingreso;
     if(count == 6 )  
      {
        for (int i=0; i<4; i++)
         is>>e.acenso[i];
      }
     if(count = 7 )  is>>e.becas;

     count ++;
    c = (char)is.get();
  }

   return (e); 
}
     
void expediente :: imprimir() {
  cout<<"Numero de expediente: "<<numero<<endl; 
  cout<<"Cedula V/E : "<<cedula<<"\t  \t"<<"Estado: "<<estado<<endl;
  cout<<"Cantidad de hijos: "<<hijos<<"\t  "<<"Fecha de Ingreso: "<<ingreso.get_dia()<<'/'<<ingreso.get_mes()<<'/'<<ingreso.get_ano()<<endl;
  cout<<"Posibles fecha de ascenso: "<<endl;
  for(int i = 0; i < 4 ; i++)
   cout<<acenso[i]<<endl;
  cout<<"A_o de becas: "<<becas.get_ano()<<endl;

}

