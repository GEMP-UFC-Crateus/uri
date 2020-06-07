#include <iostream>

using namespace std;

int main ()
{
  int n,t,i=0,j=0,max=-1;;
  unsigned long long *saida; /*Vetor que armazenar� as sa�das que ser�o mostradas*/
  unsigned long long *fibon;/*Vetor que armazenar� os n�meros de fibonacci*/
  int *ent; /*Vetor que armazenar� as entradas passadas pelo usu�rio*/

  /*Recebe do usu�rio o n�mero de testes que ser�o realizados*/
  cin >> t;

  /*Alocando dinamicamente os vetores para armazenar entrada e sa�da*/
  saida = (unsigned long long*) malloc (t*sizeof(unsigned long long));
  ent = (int*) malloc (t*sizeof(int));

  /*Capturar as entradas e determinar a entrada m�xima*/
  while (j<t){
  cin >> n;
  ent[j]=n;
  if (n>max) {max=n;} /*Guardaremos em "max" a maior de todas as entradas passadas pelo usu�rio*/
  j++;
  }

  /*Alocamos dinamicamente o vetor com o maior valor de fib solicitado*/
  fibon = (unsigned long long*) malloc (max*sizeof(unsigned long long));

  /*Come�amos a calcular todos os n�meros de fibonacci de forma botton up*/

  /*Casos bases*/
  fibon[0]=0;
  fibon[1]=1;

  /*A partir do terceiro n�mero da sequ�ncia Fibonacci, basta usar os dois n�meros anteriores para determin�-lo*/
  for (i=2;i<=max;i++){
        fibon[i]=fibon[i-1]+fibon[i-2];
  }

  /*Agora vamos pegar os valores solicitados na entrada. Como constr�mos o vetor, basta consult�-lo!*/
  j=0;
  while (j<t){
  saida[j]=fibon[ent[j]];
  j++;}

  /*Agora � s� imprimir a sa�da*/
  i=0;
  while (i<t){
      cout << "Fib(" << ent[i] << ") = " << saida[i] <<"\n";
      i++;
  }
  return 0;
}
