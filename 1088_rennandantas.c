#include <iostream>
#include <cmath>

using namespace std;

/*Andrea tem raz�o: o jogo � decidido antes mesmo de come�ar a ser jogado. O que define o vencedor � a permuta��o
gerada. A partir disso, basta calcular o n�mero de invers�es que existem no vetor. Se o n�mero de invers�es for
�mpar, ent�o Marcelo ser� o vencedor j� que ele sempre come�a jogando. Caso contr�rio, Carlos ser� o vencedor.*/

/*Vetor de inteiros para armazenar a maior sequ�ncia poss�vel (N=10^6).*/
unsigned long long int vetor[1000001];
unsigned long long int vetor_auxiliar[1000001];


/*A estrat�gia dessa fun��o � usar uma adapta��o do algoritmo Merge Sort para contar o n�mero de invers�es
utilizando, ao inv�s da for�a bruta que gera um TLE, a t�cnica de Divis�o e Conquista.*/

unsigned long long int conta_inversoes(unsigned long long int inicio_vetor, unsigned long long int fim_vetor){

    unsigned long long int tamanho_vetor,q,i,j,k,acc_esq,acc_dir,acc_intercalacao,
    meio_vetor,acc_total=0;

    tamanho_vetor=(fim_vetor-inicio_vetor+1);/*Tamanho do vetor*/

    if (tamanho_vetor==1){return 0;}/*Se tem apenas uma posi��o, ent�o n�o temos invers�es a contar*/

    else{/*Se o vetor tem mais de uma posi��o, precisamos contar o n�mero de invers�es*/

    q=(floor(tamanho_vetor/2)-1);/*N�mero de posi��es a partir da inicial onde se encontra o ponto de
    separa��o do vetor. No piso na metade do intervalo investigado*/
    meio_vetor=inicio_vetor+q;
    acc_esq=conta_inversoes(inicio_vetor,meio_vetor);/*Captura o n�mero de invers�es da chamada recursiva � esquerda*/
    acc_dir=conta_inversoes(meio_vetor+1,fim_vetor);/*Captura o n�mero de invers�es da chamada recursiva � direita*/
    acc_intercalacao=0;/*Ir� armazenar o n�mero de invers�es observadas durante o intercalamento*/


    /*Nessa se��o, contamos quantas invers�es teremos ao intercalar o vetor.*/
    i=inicio_vetor;
    j=meio_vetor+1;

    /*Intercalando e ordenando*/
    for(k=0;k<tamanho_vetor;k++){
        if (i<=meio_vetor && j<=fim_vetor){
        if (vetor[i]>vetor[j]){
            if (i!=meio_vetor) {acc_intercalacao+=((meio_vetor-i)+1);}/*Nesse caso, temos que contar as invers�es
            de todos os demais elementos que est�o � direita de i no vetor do lado esquerdo.*/
            else {acc_intercalacao++;}

            vetor_auxiliar[k]=vetor[j];
            j++;
        }
        else {
            vetor_auxiliar[k]=vetor[i];
            i++;
        }
        }

        /*Se um dos intervalos a serem intercalados j� acabou,ent�o continuamos apenas com o outro lado.*/
        else{
            if (i>meio_vetor){
                vetor_auxiliar[k]=vetor[j];
                j++;
            }
            else{
                vetor_auxiliar[k]=vetor[i];
                i++;
            }
        }
    }

    /*O total de invers�es do n�vel da chamada recursiva at� o momento.*/
    acc_total+=acc_esq+acc_dir+acc_intercalacao;

    /*Agora atualizamos o vetor vet de acordo com a ordena��o que armazenamos em v1.*/
    i=inicio_vetor;
    for(k=0;k<tamanho_vetor;k++){
       vetor[i]=vetor_auxiliar[k];
       i++;
    }
    }

    return acc_total;
}

int main()
{
    unsigned long long int n,x,i,j,acumulador;

    /*Enquanto a entrada n n�o for 0....*/
    while (cin >> n && n!=0){
        i=0;
        while (i<n){/*Armazena os n valores no vetor global.*/
            cin >> x;
            vetor[i]=x;
            i++;
        }

        /*Acumulador que armazenar� o n�mero de invers�es de cada caso de teste*/
        acumulador=conta_inversoes(0,n-1);

        if (acumulador%2==0) {cout << "Carlos\n";}/*Se o n�mero de invers�es for par, ent�o Carlos ser� o vencedor.*/
        else {cout << "Marcelo\n";}/*Se o n�mero de invers�es for �mpar, ent�o Marcelo ser� o vencedor.*/
    }
    return 0;
}
