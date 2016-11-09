#include "avltest.h"

unsigned char height(node* p)
{
    return p?p->height:0;
}

int bfactor(node* p)
{
    return height(p->right)-height(p->left);
}

void fixheight(node* p)
{
    unsigned char hl = height(p->left);
    unsigned char hr = height(p->right);
    p->height = (hl>hr?hl:hr)+1;
}

node* rotateright(node* p)
{
    node* q = p->left;
    p->left = q->right;
    q->right = p;
    fixheight(p);
    fixheight(q);
    return q;
}

node* rotateleft(node* q)
{
    node* p = q->right;
    q->right = p->left;
    p->left = q;
    fixheight(q);
    fixheight(p);
    return p;
}

node* balance(node* p)
{
    fixheight(p);
    if( bfactor(p)==2 )
    {
        if( bfactor(p->right) < 0 )
            p->right = rotateright(p->right);
        return rotateleft(p);
    }
    if( bfactor(p)==-2 )
    {
        if( bfactor(p->left) > 0  )
            p->left = rotateleft(p->left);
        return rotateright(p);
    }
    return p;
}

node* insert(node* p, NodoHumano* pHumano)
{
    if( !p ) return new node(pHumano);
    if( pHumano->id<p->humano->id)
        p->left = insert(p->left,pHumano);
    else
        p->right = insert(p->right,pHumano);
    return balance(p);
}

node* findmin(node* p)
{
    return p->left?findmin(p->left):p;
}

node* removemin(node* p)
{
    if( p->left==0 )
        return p->right;
    p->left = removemin(p->left);
    return balance(p);
}

node* remove(node* p, int k)
{
    if( !p ) return 0;
    if(k < p->humano->id)
        p->left = remove(p->left,k);
    else if(k > p->humano->id)
        p->right = remove(p->right,k);
    else //  k == p->key
    {
        node* q = p->left;
        node* r = p->right;
        delete p;
        if( !r ) return q;
        node* min = findmin(r);
        min->right = removemin(r);
        min->left = q;
        return balance(min);
    }
    return balance(p);
}

node* randomNode(node *p){
    int randDepth = (rand()%p->height);
    node* actual = p;

    for(int i = 0; i < randDepth; i++){
        if(actual->left != NULL & actual->right != NULL){
            if(rand()%2){
                actual = actual->right;
            }else{
                actual = actual->left;
            }
        } else if(actual->left != NULL){
            actual = actual->left;
        } else if(actual->right != NULL){
            actual = actual->right;
        } else {
            return actual;
        }
    }
    return actual;
}

int countNodes(node *p){
    if(p == NULL){
        return 0;
    } else{
        return 1 + countNodes(p->left) + countNodes(p->right);
    }
}

bool buscar(int id,node*persona){

    if(persona==NULL){
        return false;
    }

   else if(id==persona->humano->id){
        return true;

    }
    else if(id>persona->humano->id){
        return buscar(id,persona->right);

    }
    else{
        return buscar(id,persona->left);

    }


}
