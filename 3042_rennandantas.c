#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*Pista esquerda ->1, pista central -> 2 e pista direita -> 3*/

int main (){

  int i,l, c, r, anterior, atual;
  unsigned long int movimentos=0, m;
  vector<unsigned long int> saida;

  while (cin>>m && m>0){/*Enquanto o usuário não digitar "0" como entrada...*/
  i=0;/*Reseta o contador do while*/
  anterior=2; /*Começa na pista central*/
  movimentos=0; /*Reseta a contagem de movimentos*/
  while (i<m){/*Enquanto estiver recebendo entrada...*/
      cin >> l >> c >> r;
      if (l == 1 || c == 1 || r == 1){/*...verifique se alguma das entradas é igual a 1*/
	  /*Se tiver entrada igual a 1, somente uma delas é igual a zero. Papai noel deve ir para a pista
	  correspondente ao 0.*/
	  if (l == 0){atual=1;}
	  else{if (c == 0){atual=2;}
	       else{atual=3;}}
      movimentos+=(abs(atual-anterior));/*Valor absoluto da subtração entre os identificadores
      da pista onde ele estava e da pista para onde ele vai.*/
      anterior=atual;}/*A pista atual se torna pista anterior para a próxima iteração*/
      i++;}
    /*Coloca o número de movimentos de caso de teste num vetor de saída*/
    saida.push_back(movimentos);}

    /*Imprime o resultado */
    for(i=0;i<saida.size();i++){
        cout << saida[i] << "\n";
    }
  return 0;
}
