/*******************************************************************************
 *      Clase archivo de acceso directo con funcion hash y desborde separado
 *
 *      Prep. Carlos Carmona
 *      cm.carmona@gmail.com
 *      22 de febrero 2007
 *
 *      Version basada en la Clase Archivo Hash del Prof. Rafael Rivas  
 *      de fecha Mayo, 2000
 *
 *******************************************************************************/

#ifndef _ARCHIVO_HASH
#define _ARCHIVO_HASH
#include<iostream>
#include<fstream>
#include<stack>
#include<string>
#include<cassert>
using namespace std;

template <class C> class Archivo_Hash 
{
protected:
  typedef struct item_comp
  {
    short       disp;   // ESTADO DEL REGISTRO 0 OCUPADO, 1 LIBRE
    long        prox;   // PROXIMO REGISTRO EN COLISION, -1 NO HAY PROXIMO
    C           info;   // DATO DEL REGISTRO
    item_comp()
    {
      disp = 1;
      prox = -1; 
    }
  }t_comp;
  long tam_max_p;       //      LONGITUD MAXIMA DEL ARCH PPAL
  long tam_max_d;       //      LONGITUD MAXIMA DEL ARCH DE DESBORDE
  long tam_p;           //      COMPONENTES EN EL ARCH PPAL
  long tam_d;           //      COMPONENTES EN EL ARCH DE DESBORDE
  fstream p;            //      MANEJADOR DEL ARCHIVO PRINCIPAL
  fstream d;            //      MANEJADOR DEL ARCHIVO DE DESBORDE
  string p_nombre;      //      NOMBRE DEL ARCHIVO PRINCIPAL
  string d_nombre;      //      NOMBRE DEL ARCHIVO DE DESBORDE
  virtual long bucket_size()=0;  //LONGITUD DE LA CUBETA (BUFFER)
                                 //EN EL ARCHIVO
  virtual int leer(fstream&, long, t_comp&)= 0;           //LEER COMPONENTE 
  virtual int escribir(fstream&,long,const t_comp&) = 0;  //ESCRIBIR COMPONENTE

private:
  stack<long> disponibles;       //  DEPOSITO DE LOCALIDADES DISPONIBLES EN EL ARCH
                                 //  DE DESBORDE
  int guarda_espacio(long);      //  GUARDA ESPACIOS DISPONIBLES
  long busca_espacio();          //  BUSCA ESPACIO DISPONIBLE
  Archivo_Hash( const Archivo_Hash &);
public:
  Archivo_Hash();
  ~Archivo_Hash() ;
  int crear(char *,char *, int);
  int crear(const string&, const string&,int);
  int abrir(char *,char *);
  int abrir(const string&, const string&);
  int leer_secuencial();
  C*    buscar(C&);
  int agregar( C&);
  int eliminar(C&);
  int modificar(const C&, const C&);
  long get_tam_max() const { return (tam_max_p); };
  long get_tam_max_desb() const { return (tam_max_d); };
  long get_tam_actual() const { return (tam_p); };
  long get_tam_desborde() const { return (tam_d); };
  virtual long hash( C&) = 0;
};

template <class C> Archivo_Hash<C>::Archivo_Hash() 
{
  tam_max_d = tam_d = 0;
  tam_max_p = tam_p = 0;

}

template <class C> Archivo_Hash<C>::~Archivo_Hash() 
{
  if ( p.is_open() )
    p.close();

  if ( d.is_open() )
    d.close();
}


/***********************************************************************
 *      Creacion de los archivos Principal y de desborde
 *      donde:
 *              p_nomb: Nombre del archivo principal
 *              d_desb: Nombre del archivo de desborde
 *              modo  : Modo de apertura de los archivos
 *              t     : Numero de registros en el archivo principal
 ************************************************************************/
template <class C> int Archivo_Hash<C>::crear(char* p_nomb, char* d_nomb, int t)
{
  t_comp c;
  long i;

  if ( t < 0 )
    return 0;

  tam_max_p = t;
  //
  //    El valor de 0.20 debe ser ajustado para optimizar el tama??el archivo del
  //  archivo de desborde
  //
  tam_max_d = (long)(0.20 * t);
  tam_p = tam_d = 0;

  p_nombre = p_nomb;
  d_nombre = d_nomb;


  p.open(p_nomb,ios::out | ios::binary);
  //
  //    INICIALIZAR EL ARCHIVO PRINCIPAL
  //
  for(i = 0; i < tam_max_p; i++)
    escribir(p,i,c);
  p.close();

  d.open(d_nomb,ios::out | ios::binary);

  //
  //    INICIALIZAR EL ARCHIVO DE DESBORDE
  //
  for( i = 0; i < tam_max_d; i++)
  {
    guarda_espacio(i);
    escribir(d,i,c);
  }

  d.close();
  return(1);
}


template <class C> int Archivo_Hash<C>::crear(const string& p_nomb, const string& d_nomb, int t) 
{
  return (crear( p_nomb.c_str(), d_nomb.c_str(), t));
}

/***************************************************************************
 *      Rutina para actualizar en memoria principal la informacion de un archivo
 *   de acceso directo con area de desborde, donde:
 *              p_nomb: nombre del archivo principal
 *              d_nomb: nombre del archivo de desborde
 ****************************************************************************/
template <class C> int Archivo_Hash<C>::abrir(char* p_nomb, char* d_nomb) 
{
  t_comp c;
  p_nombre = p_nomb;
  d_nombre = d_nomb;
  tam_max_p = tam_p = tam_max_d = tam_d = 0;
  p.open(p_nombre.c_str(),ios::in|ios::binary|ios::ate);
  if(!p)
    return 0;
  long size=p.tellg();
  p.seekg(0,ios::beg);
  tam_max_p=size/bucket_size();
  for(int i=0;i<tam_max_p;i++)
  {
    leer(p,i,c);
    if ( ! c.disp )
      tam_p++;
  }
  p.close();

  d.open(d_nombre.c_str(), ios::in | ios::binary | ios::ate);
  if(!d)
    return 0;
  size=d.tellg();
        d.seekg(0,ios::beg);
        tam_max_d=size/bucket_size();

        for(int i=0;i<tam_max_d;i++)
        {
          leer(d,i,c);
          if( c.disp )
            guarda_espacio(i);
          else
            tam_d++;
        }
        d.close();
        return(1);
}

template <class C> int Archivo_Hash<C>::abrir(const string& p_nomb, const string& d_nomb) 
{
  return( abrir(p_nomb.c_str(),d_nomb.c_str()));
}

//----------------leer secuencialemnte el archivo----------------------------
/****************************************************************************
 *      Rutina para leer secuencialmente todos los registros del archivo
 *      e imprimirlos por pantalla especificando
 *      en que archivo esta:
 *              en princ
 *              en desb
 ****************************************************************************/
template <class C> int Archivo_Hash<C>::leer_secuencial() 
{
  fstream file;
  file.open("file.txt",ios::out);
  
  t_comp c;
  p.open(p_nombre.c_str(),ios::in|ios::binary|ios::ate);
  if(p)
  {
    d.open(d_nombre.c_str(), ios::in | ios::binary | ios::ate);
    if(d)
    {
      int sw;
      p.seekg(0,ios::beg);
      for(int i=0;i<tam_max_p;i++)
      {
        leer(p,i,c);
        if ( ! c.disp )
        {
          cout<<c.info;
          cout<<"en princ\n";
          file<<c.info<<endl;
        }
        if ( c.prox != -1 )
        {
          sw = 1;
          while ( sw ) 
          {
            leer(d, c.prox, c);
            cout<<c.info;
            cout<<"en desb\n";
            file<<c.info<<endl;
            if ( c.prox == -1)
              sw = 0;
          }
        }
      }
      file.close();
      d.close();
      p.close();
      return 1;
    }
    else
    {
      p.close();
      return 0;
    }
  }
  else
    return 0;
}

template <class C> C* Archivo_Hash<C>::buscar(C& dato)
{
  p.open(p_nombre.c_str(), ios::in | ios::binary );
  long pos = hash(dato);
  assert(( pos >= 0 ) && ( pos < tam_max_p));

  t_comp c;

  leer(p,pos,c);
  if ( ! c.disp )
  {
    if ( c.info == dato )
    {
      dato = c.info;
      p.close();
      return ( &dato );
    } 
    else 
    {
      if ( c.prox != -1 )
      {
        d.open(d_nombre.c_str(), ios::in | ios::binary);
        int sw = 1;
        while ( sw ) 
        {
          leer(d, c.prox, c);
          if ( c.prox == -1)
            sw = 0;
          if ( c.info == dato )
          {
            dato = c.info;
            d.close();
            p.close();
            return( &dato );
          }
        }
        d.close();
      }
    }
  }
  p.close();
  return ((C *)0);
}

template <class C> int Archivo_Hash<C>::agregar(C& dato)
{
  p.open(p_nombre.c_str(), ios::in | ios::out | ios::binary);

  long pos = hash(dato);
  assert (( pos >= 0 ) && ( pos < tam_max_p));

  t_comp c1, c2;
  c1.info = dato;
  c1.disp = 0;
  c1.prox = -1;

  leer(p,pos,c2);

  if ( c2.disp ) 
  {
    escribir(p,pos,c1);
    p.close();
    tam_p++;
    return (1);
  } 
  else 
  {
    d.open(d_nombre.c_str(), ios::in | ios::out | ios::binary);
    int ant  = c1.prox = c2.prox;
    c2.prox = busca_espacio();
    if ( c2.prox == -1 )
    {
      p.close();
      d.close();
      return(0);
    }
    escribir(p,pos,c2);
    p.close();
    tam_d++;
    escribir(d,c2.prox,c1);
    d.close();
  }
  return (1);
}

template <class C> int Archivo_Hash<C>::eliminar(C& dato)
{
  p.open(p_nombre.c_str(), ios::in | ios::out |ios::binary );

  long pos = hash(dato);
  assert(( pos >= 0 ) && ( pos < tam_max_p));

  t_comp c1, c2;
  //
  //Primer caso:        NO ESTA EN LOS ARCHIVOS
  //
  leer(p,pos,c1);
  if ( c1.disp )
  {
    p.close();
    return(0);
  }
  //
  //Segundo caso:  ESTA EN EL PRINCIPAL
  //
  if ( c1.info == dato )
  {
    if ( c1.prox == -1 ) 
    {
      c1.disp = 1;
      escribir(p,pos,c1);
      p.close();
      tam_p--;
      return(1);
    } 
    else 
    {
      d.open(d_nombre.c_str(), ios::in | ios::out | ios::binary );

      leer(d,c1.prox,c2);
      escribir(p,pos,c2);
      c2.disp = 1;
      c2.prox = -1;
      escribir(d,c1.prox,c2);
      tam_d--;
      guarda_espacio(c1.prox);
      p.close();
      d.close();
      return (1);
    }
    //
    //POSIBLEMENTE ESTA EN EL DESBORDE
    //
  } 
  else 
  {
    d.open(d_nombre.c_str(), ios::in | ios::out | ios::binary );
    int principal = 1, encontro = 0;
    long ant = pos, actual = c1.prox;
    int sw = c1.prox != -1;
    while ( sw && !encontro )
    {
      ant = actual;
      actual = c1.prox;
      leer(d, c1.prox, c1);
      if ( c1.prox == -1 )
        sw = 0;
      if ( c1.info == dato )
        encontro = 1;
      else
        principal = 0; //si es el primer elemento revisado hay que modificar el prox en el principal *  **
    }
    //
    //Tercer caso:  COMPONENTE NO EXISTE
    //
    if ( ! encontro )
    {
      p.close();
      d.close();
      return 0;
    }
    //
    //Cuarto caso: ESTA EN EL ARCHIVO DE DESBORDE
    //
    //Caso fortuito 4.1 * :  ACTUALIZAR EL ARCHIVO PRINCIPAL
    //
    if ( principal ) 
    {
      leer(p,pos,c2);
      c2.prox = c1.prox;
      escribir(p, pos,c2);
    } 
    else 
    {
      //
      //Caso fortuito 4.2 ** : ACTUALIZAR EL ARCHIVO DE DESBORDE
      //
      leer(d,ant,c2);
      c2.prox = c1.prox;
      escribir(d,ant,c2);
    }
    c1.disp = 1;
    c1.prox = -1;
    escribir(d,actual,c1);
    tam_d--;
    guarda_espacio(actual);
    d.close();
  }
  p.close();
  return(1);
}

template <class C> int Archivo_Hash<C>::modificar(const C& dato1, const C& dato2)
{
  if( eliminar(dato1) )
    return agregar(dato2);
  return(0);
}

template <class C> int Archivo_Hash<C>::guarda_espacio(long d) 
{
  disponibles.push(d);
  return 1;
}

template <class C> long Archivo_Hash<C>::busca_espacio() 
{
  long res;
  if ( disponibles.empty() ) 
  {
    cerr << "Error no hay mas espacio";
    return ( long (-1));
  }
  res = disponibles.top() ;
  disponibles.pop();
  return(res);
}
#endif
