#include <iostream>

using namespace std;


int busbin(int vec[],int li, int ls,int key){

    int med;

    if (li>ls) return li;
    med=(li+ls)/2;
    if (vec[med]==key) return med;
    if (key < vec[med])
        return busbin(vec,li,med-1,key);
    else
        return busbin(vec,med+1,ls,key);
}

int main()
{

    int ent,pos;
    int prueb[15]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    cout<<" de elvalor a buscar"<<endl;
    cin>>ent;

    pos=busbin(prueb,0,14,ent);
    cout<<"Valor   "<<prueb[pos]<<endl;

    if (prueb[pos]==ent && pos<=14)
        cout<<"Encontrado en  "<<pos<<endl;
    else
        cout<<"No encontrado en  "<<pos<<endl;

    return 0;

}
