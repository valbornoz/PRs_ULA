#include<iostream>
#include<string>

using namespace std;
int main()
{
  int *x;
  int *aux;
  int op=0;
  int con=0;
  do
    {
      if(con==0)
	{
	  con++;
	  x=new int [con];
	  cin>>x[con-1];
	}
      else
	{
	  
	  aux=new int[con];
	  for(int i=0;i<con;i++)
	    {
	      aux[i]=x[i];
	    }
	  con++;
	  delete[] x;
	  x=new int[con];
	  for(int j=0;j<con-1;j++)
	    {
	      x[j]=aux[j];
	    }
	  
	  delete[] aux;
	  cin>>x[con];
	}
      
      cout<<"opcion"<<endl;
      cin>>op;
    }
  while(op==1);
  for(int h=0;h<con;h++)
    cout<<x[h]<<endl;
  
  delete[]x;
  return 0;
}
