#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#endif

/*Os pragmas são necessários para conseguir a otimização para bater o tempo exigido na questão em C++17.*/

#include <bits/stdc++.h> // standard template library (STL)
using namespace std;

const int MAX=1e5+1;/*O maior N possível é 10^5*/

vector<bool> isPrime(MAX,true); /*Vetor que indicará se o número correspondente ao índice é ou não primo.*/
vector<int> max_prime_divider(MAX); /*Vetor que armazenará, para cada índice, o maior divisor 
primo do índice em questão.*/

/*Essa função utiliza o ideia do Crivo de Eratóstenes para para determinar todos os números primos, os não primos e o máximo divisor primo de cada número.*/
void sieve(){

/*0 e 1 não são primos.*/
isPrime[0]=false;
isPrime[1]=false;

/*O procedimento baseado no Crívo: se estiver marcado como primo, 
então é primo. Assim, o maior divisor primo é ele mesmo.*/ 
for (int i=2;i<=MAX;i++){
    if (isPrime[i]){
            max_prime_divider[i]=i;
            /*Os mútiplos de um número primo, não são primos. Nesse momento da iteração, o número primo em questão é o maior divisor primo daquele múltiplo.*/
            for (int j=i+i;j<=MAX;j+=i){
                isPrime[j]=false;
                max_prime_divider[j]=i;}
    }
  }  
}

int main(){
    sieve();
    
    int cases,n,k,counter;

    scanf("%d",&cases);/*Número de casos de teste.*/
    
    while(cases--){/*Para cada caso de teste.*/
        
        scanf("%d %d", &n, &k);
        counter=0;/*Contador de números que atendem à propriedade. Para cada nova entrada, ele é reiniciado.*/

        /*Entre 2 e N, vemos quantos números atendem à propriedade.*/  
        for (int i=2;i<=n;i++){
            if (max_prime_divider[i]<=k) {counter++;}  
        }
        /*Imprime a quantidade encontrada.*/
        printf("%d\n",counter);
    }    
    return 0;
}
