#include <stdio.h>
#include <math.h>

/*Essa fun��o determina o n�mero de d�gitos do n�mero c*/
long long int tamanho(int c){
    long long int i=0;
    while (c>=10){
        c=(c/10);
        i++;
    }
    i++;
    return i;
}

/*Essa fun��o imprime c espa�os em branco*/
void imprimir_espacos(long long int c){
    long long int i=0;
    while (i<c){
        printf(" ");
        i++;
    }}

/*Essa � a fun��o que faz a impress�o de cada array*/
void imprime(long long int n){

     long long int c1=0,i,j,c2=0,tam;

     /*Capturamos o n�mero de d�gitos do maior n�mero do array a ser impresso. Esse tamanho � justamente o
     n�mero de espa�os em branco para fazer a justificativa � direita.*/
     tam=tamanho(pow(2,(2*(n-1))));

     /*Finalmente vamos imprimir. */
     for (i=0;i<n;i++){
         c1=c2;/*Em cada linha, se come�a a gerar da pot�ncia de dois inicial da linha anterior +1.
         Ent�o o c2 tem a tarefa de guardar a pot�ncia inicial da linha anterior. O �ltimo passo antes de
         come�ar a gerar uma nova linha � justamente incrementar o c2.*/

         /*imprimir_espacos(tam-1);/*Como imprimimos um espa�o em branco antes de cada n�mero, ent�o vamos pedir
         que um espa�o em branco a menos seja impresso pela fun��o.*/
         for (j=0;j<n;j++){
              imprimir_espacos(tam-(tamanho(pow(2,c1))));/* Entre os n�meros, deveremos ter um espa�o dado pela formata��o.
              Ent�o imprimimos espa�os em branco proporcionais � diferen�a entre os tamanhos. Assim garantimos a formata��o*/
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
    long long int x[999999];/*N�o sei o tamanho exato. Coloquei um tamanho bem grande*/

    /*Preenchendo o vetor com os valores de entrada at� encontrar um 0.*/
    while ((scanf("%lld",&y)) && (y>0)){
       x[count2]=y;
       count2++;
    }

    /*Nessa parte, faremos a impress�o a partir dos valores armazenados em x.*/

    j=0;
    while (j<count2){
        imprime(x[j]);
        printf("\n");/*Ao final de cada array, imprimimos uma linha em branco*/
        j++;
    }
    return 0;
}
