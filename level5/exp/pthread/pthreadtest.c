#include<pthread.h>
#include<stdint.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



void* pthreadtest1(void* p);
void* pthreadtest2(void* p);

int num;

int main()
{
    // int num;
    int ret;
    pthread_t tid1, tid2;
    void* retval;
    ret = pthread_create(&tid1, NULL, (void*)pthreadtest1, (void*)&num);
    if(ret == -1)
    {
        printf("pthread_create error \n");
        exit(-1);
    }

    pthread_create(&tid2, NULL, (void*)pthreadtest2, (void*)&num);
    if(ret == -1)
    { 
        printf("pthread_create error \n");
        exit(-1); 
    }
    pthread_join(tid1, &retval);
    printf("pthread1: %ld\n", (intptr_t)retval);
    pthread_join(tid2, &retval);
    printf("pthread1: %ld\n", (intptr_t)retval);

    
    
    return 0;
}



void* pthreadtest1(void* p)
{
    
//    for(int i = 0; i < 20; i++){
//        printf("pthread: %ld\n", (intptr_t)p);

//    }
    int i = 0;
    while(1)
    {

        printf("pthread1: %d\n", (*(int*)p)++);
        sleep(1);
        i++;
        if(i == 3)
            break;
    }
    return (void*)56;
}

void* pthreadtest2(void* p)
{
    int i = 0;
    while(1)
    {
        printf("pthread2: %d\n", (*(int*)p)++);
        sleep(1);
        i++;
        if(i == 3)
            break;
    }
    return (void*)66;
}

