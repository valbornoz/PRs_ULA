/*******************************************************************************
 *      CLASE Visa_hash.h
 *
 *      Prep. Carlos Carmona
 *      cm.carmona@gmail.com
 *      22 de febrero 2007
 *
 *******************************************************************************/

#include"archivo_hash.h"
#include"Visa.h"
#include<cstdlib>
#include<cassert>
using namespace std;

typedef struct i_buffer
{
  short disp;
  long prox;
  char nombre[50];
  char apellido[50];
  char cedula[15];
}buffer;

class Archivo_Visa:public Archivo_Hash<Visa>
{
  public:
    int leer(fstream &,long,t_comp &);
    int escribir(fstream &,long,const t_comp &);
    long hash(const Visa &a);
    inline long bucket_size();
    Archivo_Visa();
    ~Archivo_Visa(){}
};
Archivo_Visa::Archivo_Visa():Archivo_Hash<Visa>(){}

int Archivo_Visa::leer(fstream &f,long pos_log,t_comp &t)
{
  string nombre,apellido,cedula; 

  buffer buf_av;
  long pos_real,total;

  pos_real=pos_log*bucket_size();
  total=tam_max_p*bucket_size();

  if(pos_real<0||pos_real>total)
    return 0;
  f.seekg(pos_real);
  f.read(reinterpret_cast<char*>(&buf_av),bucket_size());
  if(f.fail())
    return 0;

  t.prox=buf_av.prox;
  t.disp=buf_av.disp;

  nombre=buf_av.nombre;
  apellido=buf_av.apellido;   
  cedula=buf_av.cedula;

  t.info.asigna_nombre(nombre);
  t.info.asigna_apellido(apellido);
  t.info.asigna_cedula(cedula);

  return 1;
}

int Archivo_Visa::escribir(fstream &f, long pos_log, const t_comp &t)
{
  buffer buf_av;
  long pos_real,total;

  pos_real=pos_log*bucket_size();
  total=tam_max_p*bucket_size();

  if(pos_real<0||pos_real>total)
    return 0;

  buf_av.prox=t.prox;
  buf_av.disp=t.disp;

  strcpy(buf_av.nombre,t.info.ver_nombre().c_str());
  strcpy(buf_av.apellido,t.info.ver_apellido().c_str());
  strcpy(buf_av.cedula,t.info.ver_cedula().c_str());
  
  f.seekp(pos_real);
  f.write(reinterpret_cast<char*>(&buf_av),bucket_size());

  if(f.fail())
    return 0;

  return 1;
}

long Archivo_Visa::hash(const Visa &a)
{
  return ( atol(a.campo_clave().c_str())%tam_max_p );
}

inline long Archivo_Visa::bucket_size()
{
  return (long)sizeof(buffer);
}
