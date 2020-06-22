#include<iostream>
#include<string>
using namespace std;

string * mayuscula(string *p,int x)
{
  string *m;
  m=new string[x];
  for(int j=0;j<x;j++)
    {
      m[j]=p[j];
      for(int c=0;c<m[j].size();c++)
	{
	  m[j][c]=toupper(m[j][c]);
	}

    }
  return m;

}


string * sustituir_palabra(string x, string g, string *p, int xxx)
{
  int y;
  string tem;
  string *aux; 
  aux=new string[xxx];
  for(int i=0;i<xxx-1;i++)
    {

      tem=p[i];
      do
	{
	  
	  y=tem.find(x);
	  tem.replace(y,x.size(),g);
	}
      while((tem.find(x)!=string::npos));

      aux[i]=tem;
      
    }
  
  
  return aux;
  
}


int main()
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



  
  for(int h=0;h<i-1;h++)
    {
      cout<<prueba[h]<<endl;
    }

  string *h;
  h=mayuscula(prueba,i);


  string *hi;
  string can,ne;
  cin>>can;
  cin>>ne;
  hi=sustituir_palabra(can,ne,prueba,i);
  
  for(int k=0;k<i-1;k++)
    {
      cout<<hi[k]<<endl;
    }







  return 0;
}
