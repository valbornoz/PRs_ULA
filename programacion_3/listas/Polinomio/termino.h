#ifndef TERMINO_H
#define TERMINO_H

#include <iostream>

using namespace std;

class Termino
{
    protected:

        int coeficiente;
        int exponente;

    public:

        Termino(): coeficiente(0), exponente(0) {}
        Termino(int coef, int exp): coeficiente(coef), exponente(exp) {}
        Termino(Termino& term){
            coeficiente = term.coeficiente;
            exponente = term.exponente;}

        ~Termino() {}

    int getCoeficiente() {return coeficiente;}

	int getExponente(){return exponente;}

 	void setCoeficiente(int coef) {
		coeficiente=coef;
		return;}

	void setExponente(int exp){
		exponente=exp;
		return;}

    void operator +(const Termino& term){
             coeficiente+=term.coeficiente;
             return; }

	void operator *(const Termino& term){
            coeficiente*=term.coeficiente;
	     	exponente+=term.exponente;
            return; }

    /*   ostream&  operator <<(ostream& o,Termino t){
        o<<"TERMINO:         "<<t.coeficiente<<endl;
       // salida<<"   COEFICIENTE:  "<<term.exponente<<endl;
        return o;
    }*/

	Termino& operator =(const Termino& term){
            coeficiente = term.coeficiente;
	     	exponente = term.exponente;
	     	return *this;}

};
#endif // TERMINO_H

