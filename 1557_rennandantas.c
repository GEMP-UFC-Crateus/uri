#include <stdio.h>
#include <math.h>

/*Essa função determina o número de dígitos do número c*/
long long int tamanho(int c){
    long long int i=0;
    while (c>=10){
        c=(c/10);
        i++;
    }
    i++;
    return i;
}

/*Essa função imprime c espaços em branco*/
void imprimir_espacos(long long int c){
    long long int i=0;
    while (i<c){
        printf(" ");
        i++;
    }}

/*Essa é a função que faz a impressão de cada array*/
void imprime(long long int n){

     long long int c1=0,i,j,c2=0,tam;

     /*Capturamos o número de dígitos do maior número do array a ser impresso. Esse tamanho é justamente o
     número de espaços em branco para fazer a justificativa à direita.*/
     tam=tamanho(pow(2,(2*(n-1))));

     /*Finalmente vamos imprimir. */
     for (i=0;i<n;i++){
         c1=c2;/*Em cada linha, se começa a gerar da potência de dois inicial da linha anterior +1.
         Então o c2 tem a tarefa de guardar a potência inicial da linha anterior. O último passo antes de
         começar a gerar uma nova linha é justamente incrementar o c2.*/

         /*imprimir_espacos(tam-1);/*Como imprimimos um espaço em branco antes de cada número, então vamos pedir
         que um espaço em branco a menos seja impresso pela função.*/
         for (j=0;j<n;j++){
              imprimir_espacos(tam-(tamanho(pow(2,c1))));/* Entre os números, deveremos ter um espaço dado pela formatação.
              Então imprimimos espaços em branco proporcionais à diferença entre os tamanhos. Assim garantimos a formatação*/
              printf("%.0f",(pow(2,c1)));
              c1++;
              if (j<n-1) {printf(" ");}
         }
         printf("\n");/*Ao final de cada linha, quebrado a linha.*/
         c2++;
     }
}

int main()
{
    long long int i,y=1,c1=0,c2=0,count=0,count2=0,j;
    long long int x[999999];/*Não sei o tamanho exato. Coloquei um tamanho bem grande*/

    /*Preenchendo o vetor com os valores de entrada até encontrar um 0.*/
    while ((scanf("%lld",&y)) && (y>0)){
       x[count2]=y;
       count2++;
    }

    /*Nessa parte, faremos a impressão a partir dos valores armazenados em x.*/

    j=0;
    while (j<count2){
        imprime(x[j]);
        printf("\n");/*Ao final de cada array, imprimimos uma linha em branco*/
        j++;
    }
    return 0;
}
