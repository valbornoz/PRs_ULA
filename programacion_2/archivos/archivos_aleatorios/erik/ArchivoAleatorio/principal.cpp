#include "carro_hash.h"
using namespace std;

int menu()
{
    int op ;
    cout<<"****************************************************************"<<endl;
    cout<<"*\t\t*1. Ejecutar el Llenado del Archivo aleatorio  *"<<endl;
    cout<<"*\t\t*2. Buscar un carro por placa.                 *"<<endl;
    cout<<"*\t\t*3. Imprimir carros por pantalla.              *"<<endl;
    cout<<"*\t\t*4. Eliminar un carro por placa.               *"<<endl;
    cout<<"*\t\t*5. Salir                                      *"<<endl;
    cout<<"****************************************************************"<<endl;
    do
      {
	cout<<"Opcion: ";
	cin>>op ;
      }
    while(op <1 || op  >6);
    
    return op ;
}

int main()
{
  Archivo_carro ap;
  carro p,w;
  char opcz;
  int opc;
  bool terminar=true;
  string codigo,paux,cedula,nombre,apellido;
  char placa[10];
  int x,y;
  
  cout<<"Crear el archivo (s/n): ";
  cin>>opcz;
  if(opcz== 's' || opcz== 'S')
    ap.crear("carro_ale_p.dat","carro_ale_d.dat",100);
  else
    if(!ap.abrir("carro_ale_p.dat","carro_ale_d.dat"))
      cerr<<"Error abriendo los archivos"<<endl;
    else
      cout<<ap.get_tam_max()<<"\t"<<ap.get_tam_max_desb()<<endl
          <<ap.get_tam_actual()<<"\t"<<ap.get_tam_desborde()<<endl;
  
  do
    {
      opc = menu();
      switch(opc)
	{
	case 1:
	  {
	   
	    fstream escribir;
  
	    //abrimos el archivo de carros para escritura
	    escribir.open("carros_secuencial.dat",ios::in);
	    
	    //validamos que se haya abierto el archivo
	    if(!escribir)
	      {
		cout<<"NO SE PUDO ABRIR EL ARCHIVO DE CARROS SECUENCIAL"<<endl;
	      }
	    else
	      {

		carro tem;
		escribir.read ( reinterpret_cast<char*>(&tem), sizeof( carro ) );
		while(escribir.eof()!=1)
		  {
		    ap.agregar(tem);
		    escribir.read ( reinterpret_cast<char*>(&tem), sizeof( carro ) );
		  }	
		
		//cerramos el archivo
		escribir.close();
      
	      }

	    break;
	  }    
	case 2:
	  {
	    cout<<"\nPlaca:  ";
	    cin>>placa;
	    p.asigna_placa(placa);
	    if(ap.buscar(p))
	      cout<<"\nSe Encontro: "<<p<<endl;
	    else
	      cout<<"\nRegistro no encontrado"<<endl;
	    break;
	  }

	case 3:
	  {
	    cout<<"\nCarros: \n";
	    if(ap.leer_secuencial())
	      cout<<"\nFin de impresion del archivo "<<endl;
	    break;
	  }
	case 4:
	  {
	    cout<<"\nPlaca del  Carro  a eliminar: ";
	    cin>>placa;
	    p.asigna_placa(placa);
	    if(ap.eliminar(p))
	      cout<<"\nSe Elimino Correctamente"<<endl;
	    else
	      cout<<"\nRegistro no encontrado"<<endl;
	    break;
	  }
	case 5:
	  {
	    cout<<"\nadios\n\n ";
	    terminar=false;
	    break;
	  }
	}
    }while(terminar);
  return 0;
}
