#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/*Pista esquerda ->1, pista central -> 2 e pista direita -> 3*/

int main (){

  int i,l, c, r, anterior, atual;
  unsigned long int movimentos=0, m;
  vector<unsigned long int> saida;

  while (cin>>m && m>0){/*Enquanto o usu�rio n�o digitar "0" como entrada...*/
  i=0;/*Reseta o contador do while*/
  anterior=2; /*Come�a na pista central*/
  movimentos=0; /*Reseta a contagem de movimentos*/
  while (i<m){/*Enquanto estiver recebendo entrada...*/
      cin >> l >> c >> r;
      if (l == 1 || c == 1 || r == 1){/*...verifique se alguma das entradas � igual a 1*/
	  /*Se tiver entrada igual a 1, somente uma delas � igual a zero. Papai noel deve ir para a pista
	  correspondente ao 0.*/
	  if (l == 0){atual=1;}
	  else{if (c == 0){atual=2;}
	       else{atual=3;}}
      movimentos+=(abs(atual-anterior));/*Valor absoluto da subtra��o entre os identificadores
      da pista onde ele estava e da pista para onde ele vai.*/
      anterior=atual;}/*A pista atual se torna pista anterior para a pr�xima itera��o*/
      i++;}
    /*Coloca o n�mero de movimentos de caso de teste num vetor de sa�da*/
    saida.push_back(movimentos);}

    /*Imprime o resultado */
    for(i=0;i<saida.size();i++){
        cout << saida[i] << "\n";
    }
  return 0;
}
