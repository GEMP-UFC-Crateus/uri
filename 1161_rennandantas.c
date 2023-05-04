#include <stdio.h>
#include <string.h>

int main()
{
    int m,n;//Entradas m e n
    long long int fatorial_1, fatorial_2; //Variáveis para calcular os fatoriais de m e n respectivamente
   while (scanf("%d %d",&m, &n)!=EOF){//Enquanto o usuário não digitar CTRL+D, o algoritmo irá receber entradas
       fatorial_1 = 1;
       fatorial_2 = 1;
       //Cálculo do fatorial de m
       while(m>1){
           fatorial_1=fatorial_1*m;
           m--;
       }
       //Cálculo do fatorial de n
       while(n>1){
           fatorial_2=fatorial_2*n;
           n--;
       }
       //Como o resultado que será impresso 
       //será a soma de dois long long ints, 
       //então o tipo da saída também será long long int
       printf("%lld\n",fatorial_1+fatorial_2);
   }
    return 0;
}