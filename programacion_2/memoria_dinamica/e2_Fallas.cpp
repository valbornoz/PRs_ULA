#include <iostream>
using namespace std;

struct strFecha {
   int d,m,a;
};

struct strFalla {
   char ubicacion[40];
   int tipo;
   struct strFecha fecha;
};

int ft2(int n,struct strFalla *v){
   int i,nF=0;
   for(i=0;i<n;i++) {
      if((v[i].tipo==2)&&(v[i].fecha.m==1)&&(v[i].fecha.a==2012))
         nF++;
   }
   return nF;
}

int main() {
   int n,i;
   struct strFalla *vF;
   
   cout << "Cuantas fallas desea registrar? ";
   cin >> n;
   
   vF = new struct strFalla[n];
   
   for(i=0;i<n;i++) {
      cout << "**************************************" << endl;
      cout << "Falla " << i+1 << ": " << endl;
      cout << "Ubicación: ";
      cin >> vF[i].ubicacion;
      cout << "Tipo: ";
      cin >> vF[i].tipo;
      cout << "Fecha: ";
      cin >> vF[i].fecha.d >> vF[i].fecha.m >> vF[i].fecha.a;
      cout << endl << endl;
   }
   
   cout << "Se produjeron " << ft2(n,vF) << " fallas tipo 2 ";
   cout << " en enero de 2012." << endl;
   
   delete [] vF;
}
