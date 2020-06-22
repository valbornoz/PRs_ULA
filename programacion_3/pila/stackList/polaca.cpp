#include <iostream>
#include "sList.h"
#include "stacklist.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

bool isDigito(string& cad){

   string digito="1234567890";
   //cout<<"Cadena isDigito= "<<cad<<endl;
   if (digito.find(cad,0)==string::npos) return false;
   else return true;

}

bool precedencia(char* ent,string pil){

     bool result=true;

     switch (*ent){
       case '+': if ((pil=="+") || (pil=="-"))
                    result=true;
                 else
                    result = false;
                  break;
       case '-': if ((pil=="+") || (pil=="-"))
                    result=true;
                 else
                    result = false;
                  break;
        case '*': if ((pil=="+") || (pil=="-") || (pil=="*") || (pil=="/"))
                    result=true;
                  break;
        case '/': if ((pil=="+") || (pil=="-") || (pil=="*") || (pil=="/"))
                    result=true;
                  break;
     }
    return result;
}

bool precedenciaMayorIgual(char* ent,string pil){

     bool result=true;

     switch (*ent){
       case '+': if ((pil=="+") || (pil=="-") || (pil=="*") || (pil=="/"))
                    result=true;
                  break;
       case '-': if ((pil=="+") || (pil=="-") || (pil=="*") || (pil=="/"))
                    result=true;
                  break;
        case '*': if ((pil=="*") || (pil=="/"))
                    result=true;
                  break;
        case '/': if ((pil=="*") || (pil=="/"))
                    result=true;
                  break;
     }
    return result;
}

int evalua(string cadena){
    char* auxCad;
    string aux;
    int res1,res2;
    Stack<int> pila;
    int valor=0;

    while (cadena.length()>=1){
        aux=cadena.substr(0,1);
        cout<<"Cadena  = "<<cadena<<endl;
        cout<<"Cadena  aux = "<<aux<<endl;
        if (isDigito(aux)){
            auxCad=&aux[0];
            valor=atoi(auxCad);
            pila.push(valor);
        }
        else{
            auxCad=&aux[0];
            res1=pila.pop();
            res2=pila.pop();
            cout<<"Evaluando "<<res1<<" y "<<res2<<endl;
            switch (*auxCad){
                case '+': valor=res2+res1;
                          pila.push(valor);
                          break;
                case '-': valor=res2-res1;
                          pila.push(valor);
                          break;
                case '*': valor=res2*res1;
                          pila.push(valor);
                          break;
                case '/': valor=res2/res1;
                          pila.push(valor);
                          break;
            }
            cout<<" valor acumulado es  "<<valor<<endl;
        }
        cadena=cadena.substr(1,cadena.length());
    }
    return valor;
}

int main(int argc, char* argv[]){

    string cadena;
    char* auxCad;
    string aux,salida;
    Stack<string> pila;
    int result;

    if (argc>1)
        cadena=argv[1];
    salida="";
    while (cadena.length()>=1){
        aux=cadena.substr(0,1);
        //cout<<"Cadena  = "<<cadena<<endl;
        //cout<<"Cadena  aux = "<<aux<<endl;
        if (isDigito(aux))
            salida=salida+aux;
        else{
            //cout<<"No es digito   Pila ESTA "<<pila.isEmpty()<<endl;
            if (pila.isEmpty())
                //cout<<"Pila vacia"<<endl;
                pila.push(aux);
            else{
                auxCad=&aux[0];
                if (precedencia(auxCad,pila.top()))
                     pila.push(aux);
                else{
                    while (!pila.isEmpty() && precedenciaMayorIgual(auxCad,pila.top()))
                        salida=salida+pila.pop();
                    pila.push(aux);
                }
            }
        }
        cadena=cadena.substr(1,cadena.length());
        cout<<"Salida  = "<<salida<<endl;
    }
    while (!pila.isEmpty())
            salida=salida+pila.pop();

    cout<<"Salida  = "<<salida<<endl;
    result=evalua(salida);

    cout<<"El resultado de la expresion es "<<result<<endl;


    return 0;

}
