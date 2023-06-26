/*===============================================
*   文件名称：main.c
*   创 建 者：Null-zzj
*   创建日期：2023年06月26日
*   描    述：
================================================*/
#include <stdio.h>
#include <unistd.h>
#include "btree.h"
int main(int argc, char *argv[])
{ 
    printf("创建完全二叉树\n");
    Btree* btree = createNode(10, 1);
    printf("前序遍历");
    PreOrderTraverse(btree);
    printf("\n");
   
    printf("中序遍历");
    MidOrderTraverse(btree);
    printf("\n");

    printf("后序遍历");
    AftOrderTraverse(btree);
    printf("\n");
    return 0;
} 
