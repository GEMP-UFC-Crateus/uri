#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<unsigned long int> saida;
    unsigned long long int i,x,k,parcial;

/*A ideia desse algoritmo � simular a transforma��o do n�mero dado na entrada em uma sequ�ncia de 1s atrav�s da multiplica��o.
Para o n�mero 23, por exemplo: Qual o algarismo que multiplcado por 23 tem final 1? O algoritmos 7. 23*7=161. 161 � o que chamamos de
parcial. Perceba que o �ltimo algarismo 1 dessa parcial n�o ser� mais alterado pelas multiplica��es. Ent�o retiramos esse algarismo
e seguimos com a "transforma��o".*/

    while (cin >> x){//Enquanto tiver entrada

          /*Reseta a parcial da soma para o pr�ximo for*/
          parcial=0;
          k=0;

          do { /*Enquando n�o atingir o valor da parcial para sair...*/
          for(i=0;i<10;i++){
            /*Procurando o m�ltiplo que somado ao que t� na parcial d� 1 como �ltimo d�gito*/
            /*Fazendo a opera��o "%10" captura o �ltimo algarismo que comp�e o n�mero.*/
            if ( ((((i*x)%(10)) + ((parcial)%(10)))%10) == 1){
                parcial+=(i*x);
                i=100;}
            }
            parcial=(parcial/10);/*Retirando o �ltimo d�gito da parcial. A cada itera��o, a parcial fica menor.*/
            k++;/*Incrementa o n�mero de opera��es feitas*/
          }while (parcial>1);/*Valor da parcial para sair � menor que 1*/

          saida.push_back(k+1);}/*Coloca na sa�da o n�mero de opera��es feitas. � assim que saberemos quantos
          d�gitos tem o n�mero desejado.*/

    k=0; /*Mostrando a sa�da armazenada*/
    while (k<saida.size()){
        cout << saida[k] << "\n";
        k++;
    }
    return 0;
}
