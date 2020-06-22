#ifndef BINNODE_H_INCLUDED
#define BINNODE_H_INCLUDED
#include <iostream>

# define LLINK(p)  ((p)->getLeft())
# define RLINK(p)  ((p)->getRight())
# define KEY(p)  ((p)->getKey())

using namespace std;

template <class T>
class BinNode{

    protected:
        T key;
        BinNode<T>* left;
        BinNode<T>* right;

    public:
        typedef BinNode<T> Node;

    BinNode(){
        left=NULL;
        right=NULL;
    }

    BinNode(T dat): key(dat) {
        left=NULL;
        right=NULL;
    }

    ~BinNode(){}

    T& getKey(){return key;}

    Node*& getLeft(){return left;}

    Node*& getRight(){return right;}


    void setKey(T cl){
        key=cl;
        return;
    }

    void setLeft(Node* lf){
        left=lf;
        return;
    }

    void setRight(Node* rg){
        right=rg;
        return;
    }

    void reset(){
        left=NULL;
        right=NULL;
    }

};

#endif // BINNODE_H_INCLUDED
