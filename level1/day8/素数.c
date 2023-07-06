#include <stdio.h>

int main()

{
    int map[501] = {0};

    for(int i = 2;i < 501; i++){
        for(int j = i; ;j++){
            if(i * j < 501){  
                map[i * j] = 1;
                continue;
            }
            break;
        }
    }

    for(int i = 101; i < 501; i++){
        if(!map[i])
          printf("%d ",i);
    }

    printf("\n");

}

