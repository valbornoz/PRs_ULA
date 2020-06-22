#include<iostream>
#include<fstream>
#include<string>
using namespace std;

string  mayuscula(string p)
{

  for(int j=0;j<p.size();j++)
    {

	  p[j]=toupper(p[j]);

    }
  return p;
}



string  sustituir_palabra(string x, string g, string p)
{
  int y;
      while((p.find(x)!=string::npos))
	{
	  y=p.find(x);
	  p.replace(y,x.size(),g);
	}
  return p;
}






int main()
{
  int op=1;
  fstream escribir;
  fstream leer;
  fstream mayus;
  fstream susti;
  fstream tem;  
  do
    {
      system("clear");
      cout<<"MENU"<<endl<<"1. Llenar novela"<<endl<<"2. Cambiar Novela a mayuscula"<<endl<<"3. Sustituir Palabra en la novela"<<endl;
      cout<<"4. Ver Archivos"<<endl<<"5. salir "<<endl<<"Opcion: ";
      cin>>op;
      
      switch(op)
	{
	case 1:
	  {
	    
	    escribir.open("datos.txt", ios::out | ios::app);
	    if(!escribir)
	      {
		cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
	      }
	    else
	      {
		string *prueba;
		string *aux;
		int i=0;
		
		prueba=new string[i+1];
		
		cout<<"Para finalizar la novela introduzca #."<<endl;
		do
		  {		
		    getline(cin,prueba[i]);
		    aux=new string[i+1];
		    for(int j=0;j<=i;j++)
		      {
			aux[j]=prueba[j];
		    
		      }
		    prueba=new string[i+2];
		    for(int h=0;h<=i;h++)
		      {
			prueba[h]=aux[h];
			
		      }
		    delete [] aux;
		    i++;
		  }
		while(prueba[i-1].find('#',0)>prueba[i-1].size() || prueba[i-1].find('#',0)<0);
		
		for(int w=0;w<i-1;w++ )
		  {
		    escribir<<prueba[w]<<endl;
		    
		  }
		escribir.close();
		escribir.open("datos.txt", ios::in);
		if(!escribir)
		  {
		    cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
		  }
		else
		  {
		    tem.open("temporal.txt", ios::out);
		    if(!tem)
		      {
			cout<<"NO SE PUEDE APERTURAR EL ARCHIVO TEMPORAL"<<endl;
		      }
		    else
		      {
			string fras;
			do
			  {
			    getline(escribir,fras);
			    tem<<fras<<endl;
			  }
			while(escribir.eof()!=1);
			
			tem.close();
		      }
		    escribir.close(); 
		  }
		
	      }
	    break;
	  }
	case 2:
	  {
	    tem.open("temporal.txt", ios::in);
	    if(!tem)
	      {
		cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
	      }
	    else
	      {
		mayus.open("mayuscula.txt", ios::out);
		if(!mayus)
		  {
		    cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
		  }
		else
		  {
		    string frase;
		    do
		      {
			getline(tem,frase);
			frase=mayuscula(frase);
			mayus<< frase<<endl;
		      }
		    while(tem.eof()!=1);
		    mayus.close(); 
		  }
		tem.close();
		cout<<"Se cambio Satisfactoriamente"<<endl;
		getchar();
		getchar();
	      }
	    break;
	  }
	case 3:
	  {
	    
	    leer.open("temporal.txt", ios::in);
	    if(!leer)
	      {
		cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
	      }
	    else
	      {
		susti.open("sustituir.txt",ios::out);
		if(!susti)
		  {
		    cout<<"NO SE PUEDE APERTURAR EL ARCHIVO"<<endl;
		  }
		else
		  {
		    string frase,actu,nueva;
		    cout<<endl<<"Introduzca la palabra a sustituir: ";
		    cin>>actu;
		    cout<<endl<<"Introduzca la nueva palabra: ";
		    cin>>nueva;
		    do
		      {
			getline(leer,frase);
			frase=sustituir_palabra(actu,nueva,frase);
			susti<<frase<<endl;
		      }
		    while(leer.eof()!=1);

		    susti.close();
		  }   
		leer.close();
	      }
	    system("rm temporal.txt");
	    system("mv sustituir.txt temporal.txt");
	    break;
	  }
	case 4:
	  {
	    int op1=1;
	    do
	      {
		system("clear");
		cout<<"1. Ver originar"<<endl<<"2. Ver mayusculas"<<endl<<"3. Ver sustituido"<<endl<<"4. Volver al menu anterior"<<endl;
		cout<<"Opccion: ";
		cin>>op1;
		switch(op1)
		  {
		  case 1:
		    {
		      leer.open("datos.txt",ios::in);
		      if(!leer)
			{
			  cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
			}
		      else
			{
			  string p;
			  do
			    {
			      getline(leer,p);
			      cout<<p<<endl;
			    }
			  while(leer.eof()!=1);
			  
			  leer.close();
			}
		      getchar();
		      getchar();
		      break;
		    }
		  case 2:
		    {

		      mayus.open("mayuscula.txt",ios::in);
		      if(!mayus)
			{
			  cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
			}
		      else
			{
			  string p;
			  do
			    {
			      getline(mayus,p);
			      cout<<p<<endl;
			    }
			  while(mayus.eof()!=1);
			  
			  mayus.close();
			}
		      getchar();
		      getchar();
		      break;
		    }
		  case 3:
		    {
		      susti.open("temporal.txt",ios::in);
		      if(!susti)
			{
			  cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
			}
		      else
			{
			  string p;
			  do
			    {
			      getline(susti,p);
			      cout<<p<<endl;
			    }
			  while(susti.eof()!=1);
			  
			  susti.close();
			}
		      getchar();
		      getchar();
		      break;
		    }
		  default:
		    {
		      break;
		    }
		  }

	      }
	    while(op1!=4);
	    break;
	  }
	case 5:
	  {
	    cout<<"GRACIAS POR USAR EL SISTEMA"<<endl;
	    getchar();
	    getchar();
	    
	    break;
	  }
	default:
	  {
	    if(op<1 || op>5)
	      {
		cout<<"OPCION INVALIDA"<<endl;
		getchar();
		getchar();	
	      }
	    break;
	  }
	  
	}
      
    }
  while(op!=5);
  
  return 0;
}
