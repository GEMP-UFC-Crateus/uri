#include <iostream>

using namespace std;

int main ()
{
  int n,t,i=0,j=0,max=-1;;
  unsigned long long *saida; /*Vetor que armazenará as saídas que serão mostradas*/
  unsigned long long *fibon;/*Vetor que armazenará os números de fibonacci*/
  int *ent; /*Vetor que armazenará as entradas passadas pelo usuário*/

  /*Recebe do usuário o número de testes que serão realizados*/
  cin >> t;

  /*Alocando dinamicamente os vetores para armazenar entrada e saída*/
  saida = (unsigned long long*) malloc (t*sizeof(unsigned long long));
  ent = (int*) malloc (t*sizeof(int));

  /*Capturar as entradas e determinar a entrada máxima*/
  while (j<t){
  cin >> n;
  ent[j]=n;
  if (n>max) {max=n;} /*Guardaremos em "max" a maior de todas as entradas passadas pelo usuário*/
  j++;
  }

  /*Alocamos dinamicamente o vetor com o maior valor de fib solicitado*/
  fibon = (unsigned long long*) malloc (max*sizeof(unsigned long long));

  /*Começamos a calcular todos os números de fibonacci de forma botton up*/

  /*Casos bases*/
  fibon[0]=0;
  fibon[1]=1;

  /*A partir do terceiro número da sequência Fibonacci, basta usar os dois números anteriores para determiná-lo*/
  for (i=2;i<=max;i++){
        fibon[i]=fibon[i-1]+fibon[i-2];
  }

  /*Agora vamos pegar os valores solicitados na entrada. Como constrímos o vetor, basta consultá-lo!*/
  j=0;
  while (j<t){
  saida[j]=fibon[ent[j]];
  j++;}

  /*Agora é só imprimir a saída*/
  i=0;
  while (i<t){
      cout << "Fib(" << ent[i] << ") = " << saida[i] <<"\n";
      i++;
  }
  return 0;
}
