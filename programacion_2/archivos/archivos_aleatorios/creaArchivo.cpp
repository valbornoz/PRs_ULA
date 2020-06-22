/**
 @file crearArchivo.cpp
 @brief Programa que crea un archivo no-texto de números enteros.

  Este programa es Software Libre; Usted puede redistribuirlo y/o modificarlo
  bajo los terminos de la GNU Licencia Publica General (GPL) tal y como ha sido
  publicada por la Free Software Foundation o bien la version 2 de la Licencia,
  o (a su opcion) cualquier version posterior.

  Este programa se distribuye con la esperanza de que sea util, pero SIN NINGUNA
  GARANTIA, tampoco las implicitas garantias de MERCANTILIDAD o ADECUACION A UN
  PROPOSITO PARTICULAR. Consulte la GNU General Public License (GPL) para mas
  detalles. Usted debe recibir una copia de la GNU General Public License (GPL)
  junto con este programa; si no, escriba a la Free Software Foundation Inc.
  51 Franklin Street, 5Âº Piso, Boston, MA 02110-1301, USA.

 @author: R. Rivas
 rafael@ula.ve
 @date: Febrero 2011
*/
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h> // Requerido por srand y rand

#define DEBUG

int main() {
   unsigned int tam;
   unsigned int rango;
   int n;
   int i;

   // Creación del manejador
   std::ofstream archivo;

   // Enlace del manejador con el archivo
   archivo.open("./datos.dat", std::ios::binary);

   // Prueba del enlace
   if ( !archivo.good() ) {
      std::cerr << "Error en la creación del archivo\n";
      return(1);
   }

   std::cout << "Numeros  a crear: ";
   std::cin >> tam;

   if ( ! tam  ) {
      archivo.close();
      return(0);
   }

   std::cout << "Valor maximo: ";
   std::cin >> rango;
   if ( rango < 2 ) {
      std::cerr << "Error: El rango debe ser mayor de 1" << std::endl;
      return(2);
   }


   // Iniciar generador de numeros aleatorios
   srand((unsigned)time( NULL ));

   for(i = 0; i < tam; i++) {
      // Generar numero entre 1 y rango 
      n =  (int)(((float)rand()/(float)RAND_MAX)*rango+ 1);
      // Colocar datos en el archivo tipo texto
      archivo.write((char *) &n, sizeof(int));
#ifdef DEBUG
      std::cout << n << std::endl;
#endif
   }

   //Desvincular el manejador con el archivo
   archivo.close();

}
