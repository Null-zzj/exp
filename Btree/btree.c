#include <malloc.h>
#include "btree.h"


Btree* createNode(int n, int i){
    Btree* node = malloc(sizeof(Btree)); 
    if(node == NULL)
    {
        perror("malloc");
        return NULL;
    
    }
    node->data = i;
    if(i*2 <= n)
    {
        node->lchild = createNode(n, i*2);
    }else
    {
        node->lchild = NULL;
    }

    if(i*2 + 1 <= n)
    {     
        node->rchild = createNode(n, i*2+1);
    }else
    {
        node->rchild = NULL;
    }

    return node;

}

void PreOrderTraverse(Btree* T) {
    if (!T)
        return;
    
    printf("%d ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);

}

void MidOrderTraverse(Btree* T) {
    if (!T)
        return;

    MidOrderTraverse(T->lchild);
    printf("%d ", T->data);  
    MidOrderTraverse(T->rchild);
}


void AftOrderTraverse(Btree* T) {
    if (!T)
        return;

    AftOrderTraverse(T->lchild);
    AftOrderTraverse(T->rchild);
    printf("%d ", T->data);
}

