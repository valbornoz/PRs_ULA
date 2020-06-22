#include"archivo_hash.h"
#include"carro.h"
#include<cstdlib>
#include<cassert>
using namespace std;

typedef struct i_buffer
{
  short disp;
  long prox;
  char placa[10];
  char modelo[15];
  char marca[15];
  char color[15]; 

}buffer;

class Archivo_carro:public Archivo_Hash<carro>
{
  public:
    int leer(fstream &,long,t_comp &);
    int escribir(fstream &,long,const t_comp &);
    long hash(carro &a);
    inline long bucket_size();
    Archivo_carro();
    ~Archivo_carro(){}
};
Archivo_carro::Archivo_carro():Archivo_Hash<carro>(){}

int Archivo_carro::leer(fstream &f,long pos_log,t_comp &t)
{
  char placa[10];
  char modelo[15];
  char marca[15];
  char color[15];

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

  strcpy(placa,buf_av.placa);
  strcpy(modelo,buf_av.modelo);
  strcpy(color,buf_av.color);
  strcpy(marca,buf_av.marca);


  t.info.asigna_placa(placa);
  t.info.asigna_modelo(modelo);
  t.info.asigna_color(color);
  t.info.asigna_marca(marca);

  return 1;
}

int Archivo_carro::escribir(fstream &f, long pos_log, const t_comp &t)
{
  buffer buf_av;
  long pos_real,total;

  pos_real=pos_log*bucket_size();
  total=tam_max_p*bucket_size();

  if(pos_real<0||pos_real>total)
    return 0;

  buf_av.prox=t.prox;
  buf_av.disp=t.disp;

  strcpy(buf_av.placa,t.info.placa);
  strcpy(buf_av.modelo,t.info.modelo);
  strcpy(buf_av.marca,t.info.marca);
  strcpy(buf_av.color,t.info.color);
  
  f.seekp(pos_real);
  f.write(reinterpret_cast<char*>(&buf_av),bucket_size());

  if(f.fail())
    return 0;

  return 1;
}

long Archivo_carro::hash( carro &a)
{
  return (( atol(a.obtener_campo_clave())*2)%tam_max_p );
}

inline long Archivo_carro::bucket_size()
{
  return (long)sizeof(buffer);
}
