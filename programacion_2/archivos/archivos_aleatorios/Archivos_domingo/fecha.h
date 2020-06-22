#include <time.h>
#include <stdlib.h>
#include <math.h>

  int dias_del_mes (int mes, int ano) {

          switch(mes) {

                       case 1: return 31;
                       
                       case 2:  
                               double decimal,entero,res;
                               res = (double)ano/4 ;
                               decimal = modf(res,&entero);
                               if (decimal == 0) return 29;
                               else return 28;
                       
                       case 3: return 31;
                       case 4: return 30;
                       case 5: return 31;
                       case 6: return 30;
                       case 7: return 31;
                       case 8: return 31;
                       case 9: return 30;
                       case 10: return 31;
                       case 11: return 30;
                       case 12: return 31;
                     }
    }


class fecha {
              
               char causa[9];
               int dia,mes,a_o;
public:

        fecha();
       ~fecha(){};
        int ingreso();
        int get_dia() { return dia; }
        int get_mes() { return mes; }
        int get_ano() { return a_o; }
        char * get_causa() { return causa; }
        int acenso(char, fecha&);
        void becas();
        int ingresar_fecha();
        void agregar_fecha(int &, int &, int &);
        void ingresar_causa(char *nombre) { strcpy(causa,nombre); }
        void print_time_actual();        
        char *get_time_actual();
        void fecha_aleatoria(int &,int &,int &);
        fecha& operator = (const fecha& f); 
   friend fecha& operator >> (istream &is, fecha &f);
   friend ostream &operator <<(ostream &os, const fecha &f);
};


fecha :: fecha() {
                   strcpy(causa,"  ");
                   dia = mes = a_o = 0;
                 }


void fecha :: agregar_fecha(int &d, int &m, int &a) {
       
          dia = d;
          mes = m;
          a_o = a;
 }


int fecha :: ingresar_fecha() {

char c[5];
int n;

do{
 
 do{
  do{
   cout<<"\t\tIngrese el dia: "; 
   cin>>c;
   }while(!isdigit(c[0]) && !isdigit(c[1]) );
     dia = atoi(c);
  }while(dia<=0 || dia>31);

do{ 
 do {
      cout<<"\t\tIngrese el numero del mes: ";
      cin>>c; 
    }while(!isdigit(c[0]) && !isdigit(c[1]));
 mes = atoi(c);
 }while(mes<=0 || mes > 12);

do{
  do{
      cout<<"\t\tIngrese el año: 1.9";
      cin>>c;
    }while(!isdigit(c[0]) && !isdigit(c[1]) );
 a_o = 1900 + atoi(c);
  }while(a_o<1920  || a_o >1999); 

  n = dias_del_mes(mes,a_o);
   if(dia > n ) cout<<"ERROR fecha mal ingresada.....\a"<<endl<<endl;
}while( dia > n );

return 1;

}


 int fecha :: ingreso() {

   cout<<"\tFecha de Ingreso"<<endl;
                          strcpy(causa, "Ingreso");

   ingresar_fecha();
   return 1;

}                      


int fecha :: acenso(char c, fecha& ingreso) {

     // Fechas de acenso
     int day,month,year;
     day = month = year = 0;

     day = ingreso.get_dia();
     month = ingreso.get_mes();

  switch(c) {
               case 'a':
                         // Asistente
                         
                           ingresar_causa("Asistente"); 
                         
                           year = 4 + ingreso.get_ano();
                           agregar_fecha(day,month,year);
                           return 1;
                 
               case 'b': 
                         // Agregado
                            
                           ingresar_causa("Agregado");
                           year = 8 + ingreso.get_ano();
                           agregar_fecha(day,month,year);
                          
                           return 1;
               
               case 'c':
                         // Asociado
                         
                           ingresar_causa("Asociado");
                           year = 12 + ingreso.get_ano();
                           agregar_fecha(day,month,year);
                           return 1;
            
               case 'd':
                         // Titular  
                          
                            ingresar_causa("Titular");
                            year = 16 + ingreso.get_ano();
                            agregar_fecha(day,month,year);
                           return 1;
 
              default: 
                        break;
          } 
}

void fecha :: becas() {
int d=0, m=0;
      cout<<"Fecha de becas: "<<endl;
   
      ingresar_causa("Becas");
      cout<<"Ingrese el numero de años de beca que ha tenido: ";
      int beca;
      cin>>beca;
      agregar_fecha(d,m,beca);
  }



char *fecha :: get_time_actual() {

     time_t t;
 
     time(&t);
     return (ctime(&t));
  }

void fecha :: print_time_actual() {

     time_t t;
     time(&t);
    cout<<ctime(&t)<<endl;
 }


fecha& fecha :: operator = (const  fecha &f) {

      strcpy(causa,f.causa);
      dia = f.dia;
      mes = f.mes;
      a_o = f.a_o;

    return (*this);
 }


ostream &operator << (ostream &os, const fecha &f) {

    os<<f.causa<<' '<<f.dia<<'/'<<f.mes<<'/'<<f.a_o;

    return os;

 }


fecha& operator >> (istream &is, fecha &f) {

   char c=' ';
   int i=1;

while(c == ' ') {
                  if(i==1) is>>f.causa;
                  if(i==2) is>>f.dia;
                  if(i==3) is>>f.mes;
                  if(i==4) is>>f.a_o;
               
                  c=(char)is.get();
                  i++;
                }

return (f); 
 }


void fecha :: fecha_aleatoria(int &d, int &m, int &a) { 

  srand(time(NULL));
  d = 1 + 1 + rand() % 28;
  m = 1 + rand() % 12;
  int t ;
  t = 1 + rand()%2;
  if (t == 1)
  a = 1900 + ( 10 + rand() % 99 ); 

  else  a = 2000 + ( 1 + rand() % 20);
 }
