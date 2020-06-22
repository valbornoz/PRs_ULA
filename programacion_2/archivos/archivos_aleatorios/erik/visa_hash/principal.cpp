/*******************************************************************************
 *      Programa principal para probar la clase Visa_hash.h
 *
 *      Prep. Carlos Carmona
 *      cm.carmona@gmail.com
 *      22 de febrero 2007
 *
 *******************************************************************************/

#include "Visa_hash.h"
using namespace std;

char menu()
{
    char opc;
    cout<<"****************************************************************"<<endl;
    cout<<"*\t\t*1. Insertar una visa por cedula.              *"<<endl;
    cout<<"*\t\t*2. Buscar una visa por cedula.                *"<<endl;
    cout<<"*\t\t*3. Modificar una visa.                        *"<<endl;
    cout<<"*\t\t*4. Imprimir visas por pantalla.               *"<<endl;
    cout<<"*\t\t*5. Eliminar una visa por cedula.              *"<<endl;
    cout<<"*\t\t*6. Salir                                      *"<<endl;
    cout<<"****************************************************************"<<endl;
    cout<<"Opcion: ";
    cin>>opc;
    return opc;
}

int main()
{
  Archivo_Visa ap;
  Visa p,w;
  char opc;
  string codigo,paux,cedula,nombre,apellido;
  int x,y;
  
  cout<<"Crear el archivo (s/n): ";
  cin>>opc;
  if(opc == 's' || opc == 'S')
    ap.crear("visa_p.dat","visa_d.dat",500);
  else
    if(!ap.abrir("visa_p.dat","visa_d.dat"))
      cerr<<"Error abriendo los archivos"<<endl;
    else
      cout<<ap.get_tam_max()<<"\t"<<ap.get_tam_max_desb()<<endl
          <<ap.get_tam_actual()<<"\t"<<ap.get_tam_desborde()<<endl;

  do
  {
    opc = menu();
    switch(opc)
    {
    case '1':
    	cout<<"Nombre: ";
    	cin>>nombre;
    	cout<<"Apellido: ";
    	cin>>apellido;
    	cout<<"Cedula: ";
    	cin>>cedula;    	
      p.asigna_nombre(nombre);
      p.asigna_apellido(apellido);
      p.asigna_cedula(cedula);
      if(p.ver_cedula().size()==0)
      	cout<<"No debe dejar el campo cedula en blanco!!!\n";
      else
        if(ap.agregar(p))
          cout<<"Se ha insertado exitosamente el registro\n";
        else
          cout<<"Disculpe, no se pudo insertar el registro!!!\n";
      break;    
    case '2':
      cout<<"\nCedula: ";
      cin>>cedula;
      p.asigna_cedula(cedula);
      if(ap.buscar(p))
        cout<<"\nSe Encontro: "<<p<<endl;
      else
        cout<<"\nRegistro no encontrado"<<endl;
      break;
    case '3':
      cout<<"\nCedula: ";
      cin>>codigo;
      p.asigna_cedula(codigo);
      if(ap.buscar(p))
      {
        cout<<"\nSe Encontro: "<<p<<endl;
        cout<<"\nIntroduzca el nuevo nombre para la visa: "<<endl;
        cin>>paux;
        w=p;
        w.asigna_nombre(paux);
        if(ap.modificar(p,w))
          cout<<"\nSe actualizaron los datos de: "<<w<<endl;
      }
      else
        cout<<"\nRegistro no encontrado"<<endl;
      break;
    case '4':
      cout<<"\nVisas: \n";
      if(ap.leer_secuencial())
        cout<<"\nFin de impresion del archivo "<<endl;
      break;
    case '5':
      cout<<"\nCedula de la Visa a eliminar: ";
      cin>>cedula;
      p.asigna_cedula(cedula);
      if(ap.eliminar(p))
        cout<<"\nSe Elimino Correctamente"<<endl;
      else
        cout<<"\nRegistro no encontrado"<<endl;
      break;
    case '6':
      cout<<"\nadios\n\n ";
      opc='6';
      break;
    }
  }while(opc!='6');
  return 0;
}
