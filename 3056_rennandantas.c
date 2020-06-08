#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*A �nica coisa que precisamos saber � a dimens�o da matriz. O n�mero de pontos nessa matriz �
a sua dimens�o ao quadrado. De um passo para outro, a dimens�o da matriz aumenta a dimens�o da
matriz anterior somanda a uma unidade.*/

int main(){

long double a;/*Apesar de ser inteiro, estamos usando long double por conta do seu tamanho de armazenamento.*/
int n;/*Vari�vel que armazenar� a entrada.*/

cin >> n; /*Queremos saber a dimens�o da matriz no passo n.*/

/*A f�rmula fechada para a dimens�o da matriz no passo n � (2^n+1). Podemos conseguir esse valor
analisando que a dimens�o da matriz no passo n � igual a duas vezes a dimens�o da matriz no passo n-1
menos uma unidade.*/

/*O C++ possui uma limita��o de tipo de vari�vel. Precisar�amos de algo como "BigInt" para representar os
casos extremos. Dessa forma, vamos usar o ceil para contornar essa limita��o.*/
a = ceil(((pow(2,n))+1));

cout << fixed << setprecision(0);/*N�o deixa que sejam exibido a evetual parte real que a vari�vel double pode
acarretar.*/
cout << ceil((pow(a,2))) << "\n";/*Basta imprimir o quadrado da dimens�o da matriz no passo n. Esse
ser� o n�mero de pontos.*/

    return 0;
}
