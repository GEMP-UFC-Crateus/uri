#include <stdio.h>
int main()
{
    for (int i=1;i<=9;i+=2){//A variável i é incrementada de duas em duas unidades até o valor 9
        for (int j=7;j>=5;j--){//A variável j é decrementada unidade por unidade até atingir o valor de 5 dentro de cada iteração da variável i. 
            printf("I=%d J=%d\n",i,j);
        } 
    }
    return 0;
}