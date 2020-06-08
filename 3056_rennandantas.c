#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*A única coisa que precisamos saber é a dimensão da matriz. O número de pontos nessa matriz é
a sua dimensão ao quadrado. De um passo para outro, a dimensão da matriz aumenta a dimensão da
matriz anterior somanda a uma unidade.*/

int main(){

long double a;/*Apesar de ser inteiro, estamos usando long double por conta do seu tamanho de armazenamento.*/
int n;/*Variável que armazenará a entrada.*/

cin >> n; /*Queremos saber a dimensão da matriz no passo n.*/

/*A fórmula fechada para a dimensão da matriz no passo n é (2^n+1). Podemos conseguir esse valor
analisando que a dimensão da matriz no passo n é igual a duas vezes a dimensão da matriz no passo n-1
menos uma unidade.*/

/*O C++ possui uma limitação de tipo de variável. Precisaríamos de algo como "BigInt" para representar os
casos extremos. Dessa forma, vamos usar o ceil para contornar essa limitação.*/
a = ceil(((pow(2,n))+1));

cout << fixed << setprecision(0);/*Não deixa que sejam exibido a evetual parte real que a variável double pode
acarretar.*/
cout << ceil((pow(a,2))) << "\n";/*Basta imprimir o quadrado da dimensão da matriz no passo n. Esse
será o número de pontos.*/

    return 0;
}
