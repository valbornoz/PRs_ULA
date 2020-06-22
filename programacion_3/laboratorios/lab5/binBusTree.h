#ifndef BINBUSTREE_H_INCLUDED
#define BINBUSTREE_H_INCLUDED
#include "binTree.h"
#include "binNode.h"


template <class T>
class BinBusTree: public BinTree<T> {


    public:
        BinBusTree(){}
        ~BinBusTree(){}

        BinNode<T>* searchABB(T cl){

            BinNode<T>* nodAux;

            nodAux=NULL;
            if (BinTree<T>::root==0) return nodAux;

            nodAux=BinTree<T>::root;
            while (nodAux!=NULL){
                if (KEY(nodAux)==cl) return nodAux;
                if (cl<KEY(nodAux))
                    nodAux=LLINK(nodAux);
                else
                    nodAux=RLINK(nodAux);
            }
            return nodAux;
        }

        BinNode<T>* searchABBMen(T cl,BinNode<T>*& parent){

            BinNode<T>* nodAux;

            nodAux=NULL;
            parent=NULL;
            if (BinTree<T>::root==0) return nodAux;
            nodAux=BinTree<T>::root;
            while (nodAux!=NULL){
                if (KEY(nodAux)==cl) return nodAux;
                parent=nodAux;
                if (cl<KEY(nodAux))
                    nodAux=LLINK(nodAux);
                else
                    nodAux=RLINK(nodAux);
            }
            return nodAux;
        }

        bool insertABB(BinNode<T>* nod){

            BinNode<T>* pp=NULL;
            BinNode<T>* p;

            if (BinTree<T>::root == 0) {
                BinTree<T>::root=nod;
                return true;
            }
            p=searchABBMen(KEY(nod),pp);
            if (p != NULL)  return false;
            if (KEY(pp)>KEY(nod))
                LLINK(pp)=nod;
            else
                RLINK(pp)=nod;
            return true;
        }

//los metodos que hice//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void _insertPreABB(BinNode<T>* root2){	//esto estara bn asi tal cual?

	BinNode<T>* left, *right;

	if(root2==NULL) return;

	left=LLINK(root2);
	right=RLINK(root2);
	LLINK(root2)=NULL;
	RLINK(root2)=NULL;
	this->insertABB(root2);

	_insertPreABB(left);
	_insertPreABB(right);

	return;
}

void joinABB(BinBusTree<T> t2){


	if((this->root==NULL) and (t2.root==NULL)) return;

	if((this->root==NULL) and (t2.root!=NULL)){
		this->root=t2.root;
		t2.root=NULL;
	}

	if((this->root!=NULL) and (t2.root!=NULL))
		_insertPreABB(t2.root);

	t2.root=NULL;
	return;
}

void swap(BinNode<T>* aux, BinNode<T>* aux1){

	T temp;

	temp=KEY(aux);
	KEY(aux)=KEY(aux1);
	KEY(aux1)=temp;

}


void deleteABB(BinNode<T>* nod){

	BinNode<T>* aux, *pp;

	pp=NULL;
	aux=BinTree<T>::root;

	while(aux!=NULL){
		if(KEY(aux)==KEY(nod))
			break;
		pp=aux;
		if(KEY(aux)>KEY(nod))
			aux=LLINK(aux);
		else
			aux=RLINK(aux);
	}

	if(aux==NULL) return;

	if(LLINK(aux)==NULL or RLINK(aux)==NULL){

		if(LLINK(aux)==NULL){
			if(RLINK(pp)==aux)
				RLINK(pp)=RLINK(aux);
			else
				LLINK(pp)=RLINK(aux);

			LLINK(aux)=NULL;
			RLINK(aux)=NULL;
			return;
		}
		else{
			if(RLINK(pp)==aux)
				RLINK(pp)=LLINK(aux);
			else
				LLINK(pp)=LLINK(aux);

			LLINK(aux)=NULL;
			RLINK(aux)=NULL;
			return;
		}

	}//if principal

	else{

		BinNode<T>* Paux, *aux1;

		aux1=LLINK(aux);
		while(RLINK(aux1)!=NULL){
			Paux=aux1;
			aux1=RLINK(aux1);
		}

		swap(aux, aux1);

		if(aux1==LLINK(aux))
			LLINK(aux)=LLINK(aux1);
		else
			RLINK(Paux)=LLINK(aux1);


		LLINK(aux)=NULL;
		RLINK(aux)=NULL;
		return;

	}

}

//////////////////////////////////////////////////practica 5////////////////////////

void buildBusTree2(T V[], int li, int ls){

	int n;
	n=ls-li;
	BinNode<T>* aux;

	for(int i=0; i<=n; i++){
		aux=new BinNode<T>(V[i]);
		insertABB(aux);
	}
}

void buildBusTree(T V[], int li, int ls){

	if(BinTree<T>::root==0)
	BinTree<T>::root=_buildBusTree(V,li,ls);
	cout<<" root "<<KEY(BinTree<T>::root)<<endl;
	return;
}

BinNode<T>* _buildBusTree(T V[], int li, int ls){


	BinNode<T>* aux;
	int pos;

	aux = new BinNode<T>(V[li]);

	if(li>ls) return NULL;
	if(li==ls) return aux;

	pos=Mayor(V,li,ls);

	LLINK(aux)=_buildBusTree(V,li+1,pos-1);
	RLINK(aux)=_buildBusTree(V,pos,ls);

	return aux;

}

int Mayor(T V[], int M, int ls){

	int i;
	i=M+1;

	while(i<=ls){
		if(V[i]>M)
			return i;
		i++;
	}

	return M+1;
}

void insertRoot(BinNode<T>* nod){

	if(BinTree<T>::root==NULL){
		BinTree<T>::root=nod;
		return;
	}

	BinNode<T>* aux;

	aux=BinTree<T>::root;

	while(aux!=NULL){

		if(KEY(aux)==KEY(nod)){ 
			deleteABB(aux);
			break;
		}

		if(KEY(aux)>KEY(nod))
			aux=LLINK(aux);
		else
			aux=RLINK(aux);
	}

	insertRoot2(nod);
}

void insertRoot2(BinNode<T>* nod){

	if(BinTree<T>::root==NULL){
		BinTree<T>::root=nod;
		return;
	}

	Stack<BinNode<T>*> path;
	BinNode<T>* aux,*aux1,*aux2;

	aux=BinTree<T>::root;

	while(aux!=NULL){
		path.push(aux);

		if(KEY(aux)==KEY(nod)) return;

		if(KEY(aux)>KEY(nod))
			aux=LLINK(aux);
		else
			aux=RLINK(aux);
	}

	aux=path.pop();

	if(KEY(aux)>KEY(nod)){
		LLINK(aux)=nod;
		aux1=_rotateRight(aux);
	}
	else{
		RLINK(aux)=nod;
		aux1=_rotateLeft(aux);
	}

	while(!path.isEmpty()){
		aux=path.pop();

		if(KEY(aux)>KEY(aux1)){
			LLINK(aux)=aux1;
			aux1=_rotateRight(aux);
		}
		else{
			RLINK(aux)=aux1;
			aux1=_rotateLeft(aux);
		}
	}

	BinTree<T>::root=nod;
	return;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

};

#endif // BINBUSTREE_H_INCLUDED
