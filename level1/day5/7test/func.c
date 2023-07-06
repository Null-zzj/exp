#include <stdio.h>
#include "func.h"



int a = 5;
static int test(int);
static int b = 6;

int* func1(){
    a = 1;
    b = 2;
    return &a;
}


int (*func2())(int){
    
    return test;
}

static int test(int a)
{

    a = 3;
}


