#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>


int main(int nParametros, char** vParametros){
   std::ifstream archivoMaestro;
   std::ofstream archivoTemporal;
   std::string lineaActual;
   std::string lineaABorrar;
   // Verificar paramtetros
   if(nParametros != 3 ) {
      std::cerr << "Error en parametros, uso:\n";
      std::cerr << vParametros[0] << "<Archivo Maestro> <Linea a borrar>";
      return(1);
   }

   // Verificar la linea a borrar
   lineaABorrar = vParametros[2];

   if ( lineaABorrar.length() == 0 ){
      std::cerr << "Error linea a borrar estÃ¡ vacÃ­a\n";
      return(2);
   }

   // Abrir archivo maestro (debe existeir anteriormente
   archivoMaestro.open(vParametros[1]);

   if( ! archivoMaestro.good() ){
      std::cerr << "Error al abrir  archivo Maestro\n";
      return(3);
   }

   // Crear archivo temporal
   archivoTemporal.open("archivotemporal.txt");

   if( ! archivoTemporal.good() ){
      std::cerr << "Error al abrir  archivo temporal\n";
      return(4);
   }

   // Copiar todas las lineas del archivo maestro al temporal, exepto la linea a borrar
   //
   while( ! archivoMaestro.eof() ) {
      std::getline(archivoMaestro, lineaActual);
      if (archivoMaestro.fail()){
         break;
      }
      
      if ( lineaActual != lineaABorrar)
         archivoTemporal << lineaActual << std::endl;
   }
   

   // Eliminar vinculos con archivos
   archivoMaestro.close();
   archivoTemporal.close();

   // Una vez cerrados los vinculos:
   remove(vParametros[1]);  // Borrar el archivo maestro
   rename("archivotemporal.txt", vParametros[1]); // Colocar a temporal el nombre del archivo maestro

   return(0);
}

