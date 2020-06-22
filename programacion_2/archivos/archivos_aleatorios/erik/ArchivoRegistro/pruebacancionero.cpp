#include<istream>
#include"cancionero.h"
using namespace std;

int main()
{

  cancionero ca;
  char *p;
  char no[30];
  cin>>ca;
  p=ca.obtener_cantante();
  cout<<p<<endl;

  return 0;
}
