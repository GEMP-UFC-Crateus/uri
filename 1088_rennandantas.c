#include <iostream>
#include <cmath>

using namespace std;

/*Andrea tem razão: o jogo é decidido antes mesmo de começar a ser jogado. O que define o vencedor é a permutação
gerada. A partir disso, basta calcular o número de inversões que existem no vetor. Se o número de inversões for
ímpar, então Marcelo será o vencedor já que ele sempre começa jogando. Caso contrário, Carlos será o vencedor.*/

/*Vetor de inteiros para armazenar a maior sequência possível (N=10^6).*/
unsigned long long int vetor[1000001];
unsigned long long int vetor_auxiliar[1000001];


/*A estratégia dessa função é usar uma adaptação do algoritmo Merge Sort para contar o número de inversões
utilizando, ao invés da força bruta que gera um TLE, a técnica de Divisão e Conquista.*/

unsigned long long int conta_inversoes(unsigned long long int inicio_vetor, unsigned long long int fim_vetor){

    unsigned long long int tamanho_vetor,q,i,j,k,acc_esq,acc_dir,acc_intercalacao,
    meio_vetor,acc_total=0;

    tamanho_vetor=(fim_vetor-inicio_vetor+1);/*Tamanho do vetor*/

    if (tamanho_vetor==1){return 0;}/*Se tem apenas uma posição, então não temos inversões a contar*/

    else{/*Se o vetor tem mais de uma posição, precisamos contar o número de inversões*/

    q=(floor(tamanho_vetor/2)-1);/*Número de posições a partir da inicial onde se encontra o ponto de
    separação do vetor. No piso na metade do intervalo investigado*/
    meio_vetor=inicio_vetor+q;
    acc_esq=conta_inversoes(inicio_vetor,meio_vetor);/*Captura o número de inversões da chamada recursiva à esquerda*/
    acc_dir=conta_inversoes(meio_vetor+1,fim_vetor);/*Captura o número de inversões da chamada recursiva à direita*/
    acc_intercalacao=0;/*Irá armazenar o número de inversões observadas durante o intercalamento*/


    /*Nessa seção, contamos quantas inversões teremos ao intercalar o vetor.*/
    i=inicio_vetor;
    j=meio_vetor+1;

    /*Intercalando e ordenando*/
    for(k=0;k<tamanho_vetor;k++){
        if (i<=meio_vetor && j<=fim_vetor){
        if (vetor[i]>vetor[j]){
            if (i!=meio_vetor) {acc_intercalacao+=((meio_vetor-i)+1);}/*Nesse caso, temos que contar as inversões
            de todos os demais elementos que estão à direita de i no vetor do lado esquerdo.*/
            else {acc_intercalacao++;}

            vetor_auxiliar[k]=vetor[j];
            j++;
        }
        else {
            vetor_auxiliar[k]=vetor[i];
            i++;
        }
        }

        /*Se um dos intervalos a serem intercalados já acabou,então continuamos apenas com o outro lado.*/
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

    /*O total de inversões do nível da chamada recursiva até o momento.*/
    acc_total+=acc_esq+acc_dir+acc_intercalacao;

    /*Agora atualizamos o vetor vet de acordo com a ordenação que armazenamos em v1.*/
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

    /*Enquanto a entrada n não for 0....*/
    while (cin >> n && n!=0){
        i=0;
        while (i<n){/*Armazena os n valores no vetor global.*/
            cin >> x;
            vetor[i]=x;
            i++;
        }

        /*Acumulador que armazenará o número de inversões de cada caso de teste*/
        acumulador=conta_inversoes(0,n-1);

        if (acumulador%2==0) {cout << "Carlos\n";}/*Se o número de inversões for par, então Carlos será o vencedor.*/
        else {cout << "Marcelo\n";}/*Se o número de inversões for ímpar, então Marcelo será o vencedor.*/
    }
    return 0;
}
