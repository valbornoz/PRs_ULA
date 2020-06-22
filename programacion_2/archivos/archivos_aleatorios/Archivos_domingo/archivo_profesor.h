#include "expediente.h"
#include "archivo_directo.h"
#include <math.h>
#include <stdio.h>

  typedef struct date {
                        char causa[9];
                        int dia;
                        int mes;
                        int a_o;
			};

class archivo_profesor : public archivo_directo < expediente > {

  typedef struct {
                   int  numero;
                   short disp;
                   long prox;
                   char cedula[10];
                   char estado[8];
                   short hijos;
                   date ingreso;
                   date acenso[4];
                   date becas;
                 } t_profesor;

  public :
           archivo_profesor(){}; 
           ~archivo_profesor(){};
           int escribir(fstream &fout, long pos, t_comp& c);
           int leer(fstream &, long , t_comp&);
           long hash(expediente&);
 };


long archivo_profesor :: hash(expediente& e) {

   long res = 0;
   double cedula = atof(e.get_cedula());
   double A = ( sqrt(5) - 1 )/2;
   double funcion = floor( (double)( max_p * (cedula*A - floor(cedula*A))));
   return ((long)funcion);
 }



int archivo_profesor :: escribir( fstream &fout, long pos,  t_comp &c) {

      long pos_real;
      int i; 
      t_profesor profe;
      fecha ingreso,acenso[4],becas;
      
       ingreso = c.data.get_ingreso();
       becas   = c.data.get_becas();

       for(i=0; i<4; i++)
        acenso[i] = c.data.get_acenso(i);
     
      profe.numero = c.data.get_numero();
      sprintf( profe.cedula, "%s", c.data.get_cedula());
      sprintf( profe.estado, "%s", c.data.get_estado());
      profe.hijos = c.data.get_hijos();

      sprintf(profe.ingreso.causa, "%s", ingreso.get_causa() ); 
      profe.ingreso.dia = ingreso.get_dia();
      profe.ingreso.mes = ingreso.get_mes();
      profe.ingreso.a_o = ingreso.get_ano();

      sprintf(profe.becas.causa, "%s", becas.get_causa());      
      profe.becas.dia = becas.get_dia();
      profe.becas.mes = becas.get_mes();
      profe.becas.a_o = becas.get_ano();

      for (i=0; i<4; i++)
       {
        sprintf(profe.acenso[i].causa, "%s", acenso[i].get_causa() );
        profe.acenso[i].dia = acenso[i].get_dia();
        profe.acenso[i].mes = acenso[i].get_mes();
        profe.acenso[i].a_o = acenso[i].get_ano();
       }

      profe.disp = c.disp;
      profe.prox = c.prox;

     pos_real = pos * sizeof( t_profesor );
     fout.seekp(pos_real);
     fout.write((char *)&profe,sizeof( t_profesor ) );
     return 1;
 }


int archivo_profesor :: leer(fstream &fin, long pos, t_comp &c) {

   long pos_real;
   
   t_profesor profe;
  
   pos_real = pos*sizeof( t_profesor ); 
   
   fin.seekg(pos_real);
   
   if(fin.eof()) return 0;

   fin.read((char *)&profe,sizeof(t_profesor));
   if(fin.fail()) return 0;

   fecha acenso[4],becas,ingreso; 

   becas.ingresar_causa(profe.becas.causa);
   becas.agregar_fecha(profe.becas.dia, profe.becas.mes, profe.becas.a_o);

   ingreso.ingresar_causa(profe.ingreso.causa);
   ingreso.agregar_fecha(profe.ingreso.dia, profe.ingreso.mes, profe.ingreso.a_o);

   for(int i=0; i<4; i++)
  {
    acenso[i].ingresar_causa(profe.acenso[i].causa);
    acenso[i].agregar_fecha(profe.acenso[i].dia, profe.acenso[i].mes, profe.acenso[i].a_o);
  } 

  c.disp = profe.disp;
  c.prox = profe.prox;

  c.data.ingreso_datos(profe.numero, profe.cedula, profe.estado, profe.hijos, ingreso,becas,acenso[0],acenso[1],acenso[2],acenso[3]); 

  return 1;
}
