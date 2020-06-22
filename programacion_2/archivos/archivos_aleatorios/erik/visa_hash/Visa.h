/*******************************************************************************
 *      CLASE Visa.h
 *
 *      Prep. Carlos Carmona
 *      cm.carmona@gmail.com
 *      22 de febrero 2007
 *
 *******************************************************************************/

#ifndef _VISA
#define _VISA

class Visa
{
  protected:
  	string nombre;
  	string apellido;
    string cedula;
  public:
    Visa();
    Visa(const Visa&);
    ~Visa(){};
    string campo_clave()const{return this->cedula;};
    void asigna_nombre(const string& nombre){this->nombre=nombre;};
    void asigna_apellido(const string& apellido){this->apellido=apellido;};
    void asigna_cedula(const string& cedula) {this->cedula=cedula;};
    string ver_nombre()const{return this->nombre;};
    string ver_apellido()const{return this->apellido;};
    string ver_cedula()const{return this->cedula;};
    friend ostream& operator<<(ostream&, const Visa&);
    Visa& operator=(const Visa&);
    int operator==(const Visa& );
};

int Visa::operator==(const Visa& a) 
{
  return(this->cedula==a.cedula);
}

Visa::Visa()
{
  cedula="0000";
}

Visa::Visa(const Visa& c)
{
  this->cedula=c.cedula;
  this->nombre= c.nombre;
  this->apellido=c.apellido;
}


Visa& Visa::operator=(const Visa& c)
{
  this->cedula=c.cedula;
  this->nombre= c.nombre;
  this->apellido=c.apellido;
}

ostream& operator<<(ostream& s,const Visa& p)
{
  s<<p.nombre<<":"<<p.apellido<<":"<<p.cedula<<endl;
  return s;
}

#endif
