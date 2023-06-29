/* 1329 - Cara ou Coroa */

#include <stdio.h>

int main(){
    int N, R, maria, joao;

    while(scanf("%d", &N)){
        if(!N)  break;

        maria = 0, joao = 0;

        for(int i = 0; i < N; ++i){
            scanf("%d", &R);

            if(R){
                joao++;
            }else{
                maria++;
            }
        }

        printf("Mary won %d times and John won %d times\n", maria, joao);
    }

    return 0;
}

