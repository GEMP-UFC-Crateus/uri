#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned long int> saida;
    unsigned long long int i,x,k,parcial;

/*A ideia desse algoritmo é simular a transformação do número dado na entrada em uma sequência de 1s através da multiplicação.
Para o número 23, por exemplo: Qual o algarismo que multiplcado por 23 tem final 1? O algoritmos 7. 23*7=161. 161 é o que chamamos de
parcial. Perceba que o último algarismo 1 dessa parcial não será mais alterado pelas multiplicações. Então retiramos esse algarismo
e seguimos com a "transformação".*/

    while (cin >> x){//Enquanto tiver entrada

          /*Reseta a parcial da soma para o próximo for*/
          parcial=0;
          k=0;

          do { /*Enquando não atingir o valor da parcial para sair...*/
          for(i=0;i<10;i++){
            /*Procurando o múltiplo que somado ao que tá na parcial dá 1 como último dígito*/
            /*Fazendo a operação "%10" captura o último algarismo que compõe o número.*/
            if ( ((((i*x)%(10)) + ((parcial)%(10)))%10) == 1){
                parcial+=(i*x);
                i=100;}
            }
            parcial=(parcial/10);/*Retirando o último dígito da parcial. A cada iteração, a parcial fica menor.*/
            k++;/*Incrementa o número de operações feitas*/
          }while (parcial>1);/*Valor da parcial para sair é menor que 1*/

          saida.push_back(k+1);}/*Coloca na saída o número de operações feitas. É assim que saberemos quantos
          dígitos tem o número desejado.*/

    k=0; /*Mostrando a saída armazenada*/
    while (k<saida.size()){
        cout << saida[k] << "\n";
        k++;
    }
    return 0;
}
