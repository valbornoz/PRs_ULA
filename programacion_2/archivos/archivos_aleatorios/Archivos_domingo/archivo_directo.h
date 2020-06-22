#include <fstream.h>
#include "string.h"
#include "pila.cc"

template <class T> class archivo_directo {


protected :  
               typedef struct {
                               short disp;
                               long  prox;
                               T     data;
                             }t_comp;
               fstream principal;
               fstream desborde;
               long    max_p;      //longitud maxima del archivo principal
               long    max_d;      //longitud maxima del archivo de desborde
               long    disp_p;     //no disponibles en el archivo principal
               long    disp_d;     //no disponibles en el archivo de desborde
               cadena  nombre_p;   //nombre del archivo principal
               cadena  nombre_d;   //nombre del archivo de desborde
               pila<long> disponibles;   //pila usada para espacios disponibles
    

public:
               archivo_directo();   
              ~archivo_directo();
               int abierto() ;
               int crear(char *, char *, int, long); //nombre_principal, nombre_desborde, modo, tamaño
               int abrir(char *, char *, int);       //nombre_principal, nombre_desborde, modo
               int  buscar(T&);
               int agregar( T&);
               int eliminar(T&);
               int modificar(T&,  T&);
               int guarda_espacio(long);  //guarda espacios disponibles en la zona de desborde
               long busca_espacio();     // busca espacios disponibles en la zona de desborde
               long get_max_principal() { return max_p;  }
               long get_max_desborde()  { return max_d;  }
               long get_disponibles_p() { return (max_p-disp_p); }
               long get_disponibles_d() { return (max_d-disp_d); }
               long get_tam_disp_p()    { return disp_p; }
               long get_tam_disp_d()    { return disp_d; }
     virtual   int leer (fstream &, long,  t_comp&) = 0;
     virtual   int escribir(fstream &, long, t_comp&) = 0;
     virtual   long hash(T &) = 0;
 };             
 


template <class T> archivo_directo<T> :: archivo_directo() {

       max_p = max_d = 0; 
       disp_p = disp_d = 0; 
 }


template <class T> archivo_directo<T> :: ~archivo_directo() {

       if(principal.is_open())
          principal.close();

       if(desborde.is_open())
          desborde.close();

}

template <class T> int archivo_directo<T> :: abierto() {

    if( principal.is_open() && desborde.is_open() )
      return 1;
    else
      return 0;
 }

template <class T> int archivo_directo<T> :: crear(char *princ , char *desb, int modo, long tam) {

 t_comp c;
 long i;

  if(tam < 0) return 0;

  max_p = (long)(tam*1.25);
  max_d = (long)(max_p*0.25);
  nombre_p.set(princ);
  nombre_d.set(desb);
  
  c.disp = 1;
  c.prox = -1;

  principal.open(nombre_p.get_char(), modo);

//inicializando el archivo principal

     for(i=0; i<max_p; i++)
       escribir(principal,i,c);

  principal.close();

 desborde.open(nombre_d.get_char(), modo);
//inicializando el archivo de desborde

      for(i=0; i<max_d ; i++)
       {
        escribir(desborde, i, c);
        guarda_espacio(i);
       }

  desborde.close();

return 1;

}


template <class T> int archivo_directo<T> :: abrir(char *princ, char *desb, int modo) {

  nombre_p.set(princ);
  nombre_d.set(desb);

   principal.open(nombre_p.get_char(), modo);
   t_comp c;
   int x = 1;
   max_p = max_d = disp_p = disp_d = 0;

  while( x ) {
               if ( leer( principal, max_p, c) ) {
                         max_p++;
                if(!c.disp)   disp_p++;
              }

           else x = 0;
     } //fin de repita 

   principal.close();

   desborde.open(nombre_d.get_char(), modo);

   x = 1;

    while( x ) {
                 if( leer(desborde, max_d, c) ) {
                           max_d++;
                     if( c.disp )
                              guarda_espacio(max_d - 1 ) ;
                     else
                        disp_d++;
                  }
                 else x = 0;
              }// fin de repita
   desborde.close();

   return 1;
 }

   
template <class T> int archivo_directo<T> :: buscar( T& dato) {

 principal.open(nombre_p.get_char(), ios::in | ios::binary );  

  long pos = hash(dato);

  t_comp c;

  leer( principal, pos , c);
 
   if(!c.disp)
              { // si 1
                if ( c.data == dato ) { // si 2
                                       dato = c.data;
                                       principal.close();
                                       return (1 );
                                      }
                 else {
                        if( c.prox != -1 ) { // si 3
                                             desborde.open(nombre_d.get_char() , ios::in | ios::binary );
                                             int n = 1;
                                             while ( n ) {
                                                           leer(desborde, c.prox, c );
                                                            if( c.disp == -1 ) n = 0;
                                                            
                                                            if( c.data == dato )
                                                              {
                                                                 dato = c.data;
                                                                 desborde.close();
                                                                 principal.close();
                                                                 return (1);
                                                              }
                                                         } // fin de repita
                                              desborde.close();
                                            } // fin si 3
                      }//fin si 2 
               }//fin si 1
     principal.close();
     return (0);
 }//fin de metodo


template <class T> int archivo_directo<T> :: agregar(  T &reg) {
                                   
     principal.open(nombre_p.get_char(), ios::in | ios::out | ios::binary);

      long pos = hash(reg);

      t_comp c1, c2;
      c1.data = reg;
      c1.disp = 0;
      c1.prox = -1;
  
    leer(principal, pos, c2);

     if (c2.disp) {
                escribir(principal, pos, c1);
                principal.close();
                disp_p ++;
                return 1;
        }
      else {
            desborde.open(nombre_d.get_char(), ios::in | ios::out | ios::binary);
               if (c2.prox == -1 )
                {
                  c2.prox = busca_espacio();
                  if (c2.prox == -1 )
                    {
                       principal.close();
                       desborde.close();
                       return 0;
                     }
                   escribir(desborde, pos, c2);
                   principal.close();
                }
                else {
                      long ant = c2.prox;
                     
                       while( c2.prox != -1 ) {
                                                ant = c2.prox;
                                                leer( desborde, c2.prox, c2);
                                              }
                             c2.prox = busca_espacio();
                             if(c2.prox == -1)
                              {
                                desborde.close();    
                                return 0;
                              }
                              escribir(desborde, ant, c2);
                       }
                
                     disp_d++;
                     escribir(desborde, c2.prox, c1);
                     desborde.close();
            }

        return 1;
}


template <class T> int archivo_directo<T> :: eliminar( T& reg) {

principal.open(nombre_p.get_char() , ios::in | ios::out | ios::binary);

  long pos = hash ( reg );
  t_comp c1,c2;

  // si no se encuentra en los archivos
   leer(principal, pos, c1);
    if( c1.disp )
      {
        principal.close();
        return 0;
      }

  // si esta en el archivo principal

 if(c1.data == reg) {
         if(c1.prox == -1){
            c1.disp = 1;
            escribir(principal, pos, c1);
            principal.close();
            disp_d --;
            return 1;
         }
    else {
            desborde.open(nombre_d.get_char(), ios::in | ios::out | ios::binary);
        
              leer(desborde,c1.prox,c2);
              escribir(principal, pos, c2);
              c2.disp = 1;
              c2.prox = -1;
              escribir(desborde, c1.prox, c2);
              disp_d--;
              guarda_espacio(c1.prox);
              principal.close();
              desborde.close();
              return 1;
         }

 //si esta en la zona de desborde

  }else {

          desborde.open(nombre_d.get_char(), ios::in | ios::out  | ios ::binary);

           int princ = 1, found = 0; // princ evalua si el primer contacto  es el dato a buscar en el archivo de desborde

              long ant = pos, actual = c1.prox;

              int sw =1;
                
              while( sw && !found ) {
                                      ant = actual;
                                      actual = c1.prox;
                                      leer(desborde, c1.prox, c1);
                                      if(c1.prox == -1)
                                         sw = 0;
                                      if(c1.data == reg)
                                           found = 1;
                                      else
                                           princ = 0;
                                   }

  //componenete no encontrada

      if (!found)
                  {
                     principal.close();
                     desborde.close();
                     return 0;
                  }
 //Los metodos a continuacion se deben a que el dato se encontro 

 //actualizar el archivo principal 

        if ( princ )
            {
                leer(principal, pos, c2);
                c2.prox = c1.prox;
                escribir(principal, pos, c2);
            }
//actualizar el archivo de desborde

        else {
               leer(desborde, ant, c2);
               c2.prox = c1.prox;
               escribir(desborde, ant, c2);
          }

   c1.disp = 1;
   c1.prox = -1;
   escribir(desborde, actual, c1);
   guarda_espacio(actual);
   disp_d--;
   desborde.close();
  }

  principal.close();
  return 1;
 }



template <class T> int archivo_directo<T> :: modificar(T& dat1, T &dat2) {

   if( eliminar(dat1) )
       agregar(dat2);
   return 0;
}


template <class T> int archivo_directo<T> :: guarda_espacio( long d) {
  return(disponibles.asigna(d)); }


template <class T> long archivo_directo<T> :: busca_espacio() {

  long res;

  if( disponibles.saca_elem(res) )
      return res;
 else
      return ( (long)(-1));
}
