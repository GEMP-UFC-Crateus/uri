#include <iostream>

using namespace std;

/*A função find simula a alocação da matriz da questão*/

void find(int n, int s){

    int p,i,j,k,w,mov;

    k=1;/*É o número da loja. Vai ser incrementado até chegar na loja s desejada*/
    p=1;/*Guarda o número de passos que serão dados em cada direção até mudar de direção*/
    i=n/2;/*Guarda a posição no eixo y da matriz*/
    j=n/2;/*Guarda a posição no eixo x da matriz*/
    mov=1;/*Guarda o tipo de movimento que será feito:
    Tipo 1 -> direita, tipo 2 -> baixo tipo 3 -> esquerda e tipo 4 -> cima
    Como esse número vai crescer muito, pegamos o mov%4*/

    /*Se quiser a posição da primeira loja, é só imprimir o que já tem.*/
    if (s==1) {cout << i << " " << j << "\n";}

    while (k<s){/*Enquanto não chegarmos ao número s desejado...*/

        switch ((mov%4)){/*Verificamos a direção do movimento*/

            case 1: {/*Vamos para a direita até p passos*/
                w=0;/*Contador do número de passos*/
                while (w<p && k<s){/*Enquando não alcançar o númer de passos daquela direção e enquanto não
                alcançar o número da loja desejada...*/
                k++;/*...Incrementa o número de loja,*/
                j++;/*incrementa a posição j simulando a alocação da loja k na posição (i,j)*/
                w++;/*e incrementa o número de passos dados naquela direção*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){break;}/*Se ainda não alcançou o número s, então continua a simulação de alocação*/
                else {cout << i << " " << j << "\n"; break;}/*Se alcançou o número s, então mostra a posição
                onde ele seria alocado*/
                }

            case 2: {/*Vamos para baixo até p passos*/
                w=0;/*Contador do número de passos*/
                while (w<p && k<s){/*Enquando não alcançar o númer de passos daquela direção e enquanto não
                alcançar o número da loja desejada...*/
                k++;/*...Incrementa o número de loja,*/
                i++;/*incrementa a posição i simulando a alocação da loja k na posição (i,j)*/
                w++;/*e incrementa o número de passos dados naquela direção*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){p++;break;}/*Se ainda não alcançou o número s, então continua a simulação de alocação.
                Quando a alocação para baixo atinge o número máximo de passos, o número máximo de passos é
                incrementado para a próxima iteração.*/
                else {cout << i << " " << j << "\n";break;}/*Se alcançou o número s, então mostra a posição
                onde ele seria alocado*/
                }

            case 3: {/*Vamos para a esquerda até p passos*/
                w=0;/*Contador do número de passos*/
                while (w<p && k<s){/*Enquando não alcançar o númer de passos daquela direção e enquanto não
                alcançar o número da loja desejada...*/
                k++;/*...Incrementa o número de loja,*/
                j--;/*decrementa a posição j simulando a alocação da loja k na posição (i,j)*/
                w++;/*e incrementa o número de passos dados naquela direção*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){break;}/*Se ainda não alcançou o número s, então continua a simulação de alocação*/
                else {cout << i << " " << j << "\n";break;}/*Se alcançou o número s, então mostra a posição
                onde ele seria alocado*/
                }

            case 0: {/*Vamos para cima até p passos*/
                w=0;/*Contador do número de passos*/
                while (w<p && k<s){/*Enquando não alcançar o númer de passos daquela direção e enquanto não
                alcançar o número da loja desejada...*/
                k++;/*...Incrementa o número de loja,*/
                i--;/*decrementa a posição i simulando a alocação da loja k na posição (i,j)*/
                w++;/*e incrementa o número de passos dados naquela direção*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){p++;break;}/*Se ainda não alcançou o número s, então continua a simulação de alocação.
                Quando a alocação para cima atinge o número máximo de passos, o número máximo de passos é
                incrementado para a próxima iteração.*/
                else {cout << i << " " << j << "\n";break;}/*Se alcançou o número s, então mostra a posição
                onde ele seria alocado*/
                }
        }
        mov++;/*Mudo a direção de alocação*/
    }
}

int main()
{
    int n,s;

    while (cin >> n >> s){/*Enquanto tivermos entrada, procuramos Padmé*/
        find(n,s);/*Chamamos a função que procura a loja s numa matriz n por n*/
    }
    return 0;
}
