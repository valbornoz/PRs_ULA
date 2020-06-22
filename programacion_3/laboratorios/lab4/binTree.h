#ifndef BINTRESS_H_INCLUDED
#define BINTRESS_H_INCLUDED
#include <iostream>
#include "binNode.h"
#include "stack.h"



using namespace std;


template <class T>
class BinTree{

    protected:

        BinNode<T>* root;

    public:

        BinTree():root(0){}
        ~BinTree(){
            if (root!=0){
                _eraseTree(root);
            }
        }

//los metodos que hice//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void buildPosTree(T postorden[], int lip, int lsp,T inorden[], int lii, int lsi){
            if (root==0){
                root = _buildPosTree(postorden,lip,lsp,inorden,lii,lsi);
                cout<<" root "<<KEY(root)<<endl;
            }
            return;
}


BinNode<T>* _buildPosTree(T postorden[], int lip, int lsp,    T inorden[], int lii, int lsi){

        BinNode<T>* aux;
        int pos;

        if (lip>lsp) return NULL;
        aux=new BinNode<T>(postorden[lsp]);

        if (lip == lsp) return aux;
        if (aux!= 0){
            pos=findRoot(postorden[lsp],inorden,lii,lsi);
            if (pos >= 0){
                RLINK(aux)=_buildPosTree(postorden,lip+pos,lsp-1,inorden,lii+pos+1,lsi);
                LLINK(aux)=_buildPosTree(postorden,lip,lip+pos-1,inorden,lii,lii+(pos-1));
            }
        }
         //cout<<"root "<<KEY(aux)<<endl;
        return aux;
    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


        void buildBinTree(T preorden[], int lip, int lsp,T inorden[], int lii, int lsi){
            if (root==0){
                root = _buildTree(preorden,lip,lsp,inorden,lii,lsi);
                cout<<" root "<<KEY(root)<<endl;
            }
            return;
        }

     int preorden(void (*visitFct)(BinNode<T>*,int ,int )){

        int level=0;
        int position=0;
        if (root!=0)
            _preordenRec(root,level,position,visitFct);
        cout<<" "<<endl;
        return 1;
    }

    int inorden(void (*visitFct)(BinNode<T>*,int ,int )){

        int level=0;
        int position=0;
        if (root!=0)
            _inordenRec(root,level,position,visitFct);
        cout<<" "<<endl;
        return 1;
    }

    int inordenNRec(void (*visitFct)(BinNode<T>*,int ,int )){

        Stack<BinNode<T>*> pilaAux;
        BinNode<T>*  nodAux;
        int position=0;

        if(root==NULL) return 0;

        nodAux=root;

        while (true){

            while(LLINK(nodAux)!=NULL){
                pilaAux.push(nodAux);
                nodAux=LLINK(nodAux);
            }

            while (true){

                (*visitFct)(nodAux,pilaAux.size(),position++);
                if (RLINK(nodAux)!=NULL){
                    nodAux=RLINK(nodAux);
                    break;
                }
                if (pilaAux.isEmpty()) return position;
                nodAux=pilaAux.pop();
            }
        }

    }



    int postorden(void (*visitFct)(BinNode<T>*,int ,int )){

        int level=0;
        int position=0;
        if (root!=0)
            _postordenRec(root,level,position,visitFct);
        cout<<" "<<endl;
        return 1;
    }

    int cardinal(){

        int card;

        if (root==0) return 0;
            card = _cardinalidadTree(root);
        return card;
    }

     int h(){

        if (root==0) return 0;
        return _H(root);
    }

    private:


    void _preordenRec(BinNode<T>* aux,const int & level, int & position, void (*visitFct)(BinNode<T>*,int,int)){

        if (aux==0) return;
        (*visitFct)(aux,level,position);
        ++position;
        _preordenRec(LLINK(aux),level+1,position,visitFct);
        _preordenRec(RLINK(aux),level+1,position,visitFct);
        return;
    }

     void _inordenRec(BinNode<T>* aux,const int & level, int & position, void (*visitFct)(BinNode<T>*,int,int)){

        if (aux==0) return;

        _inordenRec(LLINK(aux),level,position,visitFct);
         (*visitFct)(aux,level+1,position);
        ++position;
        _inordenRec(RLINK(aux),level+1,position,visitFct);
        return;
    }

     void _postordenRec(BinNode<T>* aux, const int & level, int & position, void (*visitFct)(BinNode<T>*,int,int)){

        if (aux==0) return;

        _postordenRec(LLINK(aux),level+1,position,visitFct);
        _postordenRec(RLINK(aux),level+1,position,visitFct);
        (*visitFct)(aux,level,position);
        ++position;
        return;
    }



     int _cardinalidadTree(BinNode<T>* aux){

         if (aux==0) return 0;
         return (_cardinalidadTree(LLINK(aux))+1+_cardinalidadTree(RLINK(aux)));

    }

    int _H(BinNode<T>* aux){

        if (aux==0) return 0;
         return ( 1 + max(_H(LLINK(aux)),_H(RLINK(aux))));
    }

    //


    BinNode<T>* _buildTree(T preorden[], int lip, int lsp,
                        T inorden[], int lii, int lsi){

        BinNode<T>* aux;
        int pos;

        if (lip>lsp) return NULL;
        aux=new BinNode<T>(preorden[lip]);

        if (lip == lsp) return aux;
        if (aux!= 0){
            pos=findRoot(preorden[lip],inorden,lii,lsi);
            if (pos >= 0){
                LLINK(aux)=_buildTree(preorden,lip+1,lip+pos,inorden,lii,lii+(pos-1));
                RLINK(aux)=_buildTree(preorden,lip+pos+1,lsp,inorden,lii+pos+1,lsi);
            }
        }
         //cout<<"root "<<KEY(aux)<<endl;
        return aux;
    }

    int findRoot(T cla,T inorden[],int lii,int lsi){

        int i=lii;
        while(i<=lsi){
            // cout<<"buscando cla "<<cla<<"en inorden  "<<inorden[i]<<endl;
            if (cla==inorden[i]) return i-lii;
                i++;
        }
        return -1;
    }

    int max(int a,int b){
        return (a>b) ? a:b;
    }

     void _eraseTree(BinNode<T>* aux){

        if (aux==0) return;

        _eraseTree(LLINK(aux));
        _eraseTree(RLINK(aux));
        aux->reset();
        delete aux;
        return;
     }

};


#endif // BINTRESS_H_INCLUDED
