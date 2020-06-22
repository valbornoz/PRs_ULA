/**
 @file buscaDato.cpp
 @brief Programa de prueba del método std::istream::seekg. El programa busca 
 el i-esimo elemnto en un archivo no texto de números enteros.
 
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

#define DEBUG

int main() {
   int nBytes, nDatos, n, dato;
   std::ifstream archivo;    // Creación del manejador


   // Enlace del manejador con el archivo
   archivo.open("./datos.dat", std::ios::binary);

   // Prueba del enlace
   if ( !archivo.good() ) {
      std::cerr << "Error al abrir el archivo\n";
      return(1);
   }


   // Leer la cantidad de numeros en el archivo
   archivo.seekg (0, std::ios_base::end);
   nBytes =archivo.tellg();
   nDatos = nBytes/sizeof(int);

   std::cout << "El archivo tiene " << nDatos << " datos\n";

   while(true) {
      std::cout << "Introduzca el número del dato que quiere ver  (para salir de un número negativo): ";
      std::cin >> n;
      if ( n < 0 ) 
         break;
      if (n >= nDatos)
         std::cerr << "El numero debe ser menor que " << nDatos << "\n";
      else {
         archivo.clear();
         archivo.seekg( n * sizeof(int), std::ios_base::beg);
         if ( archivo.fail() ){
            std::cerr << "Error en el seekg\n";
         } else {
            archivo.read((char *)&dato, sizeof(int));
            std::cout << "El numero en la posición " << n << " es " << dato <<"\n";
         }
      }
   }
   //Desvincular el manejador con el archivo
   archivo.close();

   return(0);
}

