#ifndef AVLTEST_H
#define AVLTEST_H
#include <QtCore>
#include <cstdlib>
#include "nodohumano.h"

struct node{
    NodoHumano* humano;
    unsigned char height;
    node* left;
    node* right;
    node(NodoHumano* pHumano){
        humano = pHumano;
        left = NULL;
        right = NULL;
        height = 1;
    }
};

/*struct node
{
    int key;
    unsigned char height;
    node* left;
    node* right;
    node(int k) {
    key = k; left = right = 0; height = 1; }
};*/

unsigned char height(node* p);
int bfactor(node* p);
void fixheight(node* p);
node* rotateright(node* p);
node* rotateleft(node* q);
node* balance(node* p);
node* insert(node* p, NodoHumano* pHumano);
node* findmin(node* p);
node* removemin(node* p);
node* remove(node* p, int k);
node* randomNode(node* p);
int countNodes(node* p);
#endif // AVLTEST_H
