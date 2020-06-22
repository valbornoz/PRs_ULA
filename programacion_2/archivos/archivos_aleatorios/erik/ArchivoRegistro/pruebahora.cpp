#include<istream>
#include"hora.h"
using namespace std;

int main()
{
  int n;
  hora horita,horota,po,pi;
  cin>>horita;
  cout<<horita;
  cout<<endl;
  horota=horita;
  cout<<horota;
  cout<<endl;
  po=horita-horota;
  pi=horita+horota;
  cout<<po;
  cout<<endl;
  cout<<pi;
  cout<<endl;
  if(horita==horota)
    cout<<"iguales"<<endl;
  if(pi!=po)
    cout<<"distintos"<<endl;
  n=po.convertir_en_segundos();
  cout<<n<<endl;
  n=pi.convertir_en_segundos();
  cout<<n<<endl;
  return 0;
}
