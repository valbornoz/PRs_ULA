#include <iostream>

using namespace std;

void shellSort(int* a,int li, int ls){

     int h,i,j,n;
     int aux;

     h=1;
     n=ls-li+1;
     while (h<n)
        h=h*3+1;

     while(h/3>=1){
        h=h/3;
        cout<<"la distancia h es  "<<h<<endl;
        cout<<endl;
        for (i=h;i<n;i++){  //  inicio del  insert sort con distancia h
          aux=a[i];
          j=i;
          while((j>=h) && (a[j-h]>aux)){
                a[j]=a[j-h];
                j-=h;
          }
          a[j]=aux;
         }  // fin del insert sort
     };
   return;
};

void insertSort(int* a,int li, int ls){

    int i,j,aux,n;

    n=ls-li+1;
    for (i=1;i<n;i++){  //  inicio del  insert sort
          aux=a[i];
          j=i;
          while((j>=0) && (a[j-1]>aux)){
                a[j]=a[j-1];
                j--;
          }
          if (j>=0)
             a[j]=aux;
          else
             a[0]=aux;
    }  // fin del insert sort
   return;
};

void swap(int* a,int i, int j){

   int aux;

   aux=a[i];
   a[i]=a[j];
   a[j]=aux;
   return;
}

void selectSort(int* a,int li, int ls){

    int i,j,min,n;

    n=ls-li+1;

    for (i=0;i<n-1;i++){
          min=i;
          for (j=i+1;j<n;j++){
             if (a[min]>a[j])
                 min=j;
          }
          if (i!=min)
            swap(a,i,min);
    }
   return;
};


void merge(int* a,int li, int ls,int med){

    int b[ls-li+1];
    int i,j,n,k;

    k=0;
    n=ls-li+1;
    for (i=li;i<=med;i++){
        b[k]=a[i];
        k++;
    }
    for (i=ls;i>med;i--){
       b[k]=a[i];
       k++;
    }

    /*  cout<<"MEZCLANDO"<<endl;
    for (k=0;k<n;k++)
        cout<<"Vector B[ "<<k<<" ] =  "<<b[k]<<endl;
    cout<<endl;
    */
    for(i=0,j=n-1,k=li; k<=ls; k++){
        if (b[i]<b[j]){
            a[k]=b[i];
            i++;
        }
        else{
            a[k]=b[j];
            j--;
        }
     }
    return;
};

void mergeSort(int* a,int li, int ls){

    if (li==ls) return;

    int medio;

    medio=(li+ls)/2;

    mergeSort(a,li,medio);
    mergeSort(a,medio+1,ls);
    merge(a,li,ls,medio);

    return;
};


int main(){
   int a[15]={4,5,1,3,15,12,11,76,34,72,17,13,99,85,63};
   int i;

    /* for (i=0;i<15; i++)
       cout<<"Vector A[ "<<i<<" ] =  "<<a[i]<<endl; */

    cout<<endl;
    cout<<"ORDENAMIENTO SHELLSORT"<<endl;
    cout<<endl;

    shellSort(a,0,14);
    for (i=0;i<15; i++)
       cout<<"Vector A[ "<<i<<" ] =  "<<a[i]<<endl;

    int b[15]={4,5,1,3,15,12,11,76,34,72,17,13,99,85,63};


    cout<<endl;
    cout<<"ORDENAMIENTO INSERTSORT"<<endl;
    cout<<endl;
    insertSort(b,0,14);
    for (i=0;i<15; i++)
       cout<<"Vector B[ "<<i<<" ] =  "<<b[i]<<endl;

    int c[15]={4,5,1,3,15,12,11,76,34,72,17,13,99,85,63};
    cout<<endl;
    cout<<"ORDENAMIENTO SELECTSORT"<<endl;
    cout<<endl;
    selectSort(c,0,14);
    for (i=0;i<15; i++)
        cout<<"Vector c[ "<<i<<" ] =  "<<c[i]<<endl;

    int d[15]={4,5,1,3,15,12,11,76,34,72,17,13,99,85,63};
    cout<<endl;
    cout<<"ORDENAMIENTO MERGESORT"<<endl;
    cout<<endl;
    mergeSort(d,0,14);
    for (i=0;i<15; i++)
        cout<<"Vector d[ "<<i<<" ] =  "<<d[i]<<endl;

    return 0;
}
