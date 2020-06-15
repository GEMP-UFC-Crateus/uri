#include <iostream>

using namespace std;

/*A fun��o find simula a aloca��o da matriz da quest�o*/

void find(int n, int s){

    int p,i,j,k,w,mov;

    k=1;/*� o n�mero da loja. Vai ser incrementado at� chegar na loja s desejada*/
    p=1;/*Guarda o n�mero de passos que ser�o dados em cada dire��o at� mudar de dire��o*/
    i=n/2;/*Guarda a posi��o no eixo y da matriz*/
    j=n/2;/*Guarda a posi��o no eixo x da matriz*/
    mov=1;/*Guarda o tipo de movimento que ser� feito:
    Tipo 1 -> direita, tipo 2 -> baixo tipo 3 -> esquerda e tipo 4 -> cima
    Como esse n�mero vai crescer muito, pegamos o mov%4*/

    /*Se quiser a posi��o da primeira loja, � s� imprimir o que j� tem.*/
    if (s==1) {cout << i << " " << j << "\n";}

    while (k<s){/*Enquanto n�o chegarmos ao n�mero s desejado...*/

        switch ((mov%4)){/*Verificamos a dire��o do movimento*/

            case 1: {/*Vamos para a direita at� p passos*/
                w=0;/*Contador do n�mero de passos*/
                while (w<p && k<s){/*Enquando n�o alcan�ar o n�mer de passos daquela dire��o e enquanto n�o
                alcan�ar o n�mero da loja desejada...*/
                k++;/*...Incrementa o n�mero de loja,*/
                j++;/*incrementa a posi��o j simulando a aloca��o da loja k na posi��o (i,j)*/
                w++;/*e incrementa o n�mero de passos dados naquela dire��o*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){break;}/*Se ainda n�o alcan�ou o n�mero s, ent�o continua a simula��o de aloca��o*/
                else {cout << i << " " << j << "\n"; break;}/*Se alcan�ou o n�mero s, ent�o mostra a posi��o
                onde ele seria alocado*/
                }

            case 2: {/*Vamos para baixo at� p passos*/
                w=0;/*Contador do n�mero de passos*/
                while (w<p && k<s){/*Enquando n�o alcan�ar o n�mer de passos daquela dire��o e enquanto n�o
                alcan�ar o n�mero da loja desejada...*/
                k++;/*...Incrementa o n�mero de loja,*/
                i++;/*incrementa a posi��o i simulando a aloca��o da loja k na posi��o (i,j)*/
                w++;/*e incrementa o n�mero de passos dados naquela dire��o*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){p++;break;}/*Se ainda n�o alcan�ou o n�mero s, ent�o continua a simula��o de aloca��o.
                Quando a aloca��o para baixo atinge o n�mero m�ximo de passos, o n�mero m�ximo de passos �
                incrementado para a pr�xima itera��o.*/
                else {cout << i << " " << j << "\n";break;}/*Se alcan�ou o n�mero s, ent�o mostra a posi��o
                onde ele seria alocado*/
                }

            case 3: {/*Vamos para a esquerda at� p passos*/
                w=0;/*Contador do n�mero de passos*/
                while (w<p && k<s){/*Enquando n�o alcan�ar o n�mer de passos daquela dire��o e enquanto n�o
                alcan�ar o n�mero da loja desejada...*/
                k++;/*...Incrementa o n�mero de loja,*/
                j--;/*decrementa a posi��o j simulando a aloca��o da loja k na posi��o (i,j)*/
                w++;/*e incrementa o n�mero de passos dados naquela dire��o*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){break;}/*Se ainda n�o alcan�ou o n�mero s, ent�o continua a simula��o de aloca��o*/
                else {cout << i << " " << j << "\n";break;}/*Se alcan�ou o n�mero s, ent�o mostra a posi��o
                onde ele seria alocado*/
                }

            case 0: {/*Vamos para cima at� p passos*/
                w=0;/*Contador do n�mero de passos*/
                while (w<p && k<s){/*Enquando n�o alcan�ar o n�mer de passos daquela dire��o e enquanto n�o
                alcan�ar o n�mero da loja desejada...*/
                k++;/*...Incrementa o n�mero de loja,*/
                i--;/*decrementa a posi��o i simulando a aloca��o da loja k na posi��o (i,j)*/
                w++;/*e incrementa o n�mero de passos dados naquela dire��o*/
                }
                /*Se saiu do while, verificamos o motivo*/
                if (k<s){p++;break;}/*Se ainda n�o alcan�ou o n�mero s, ent�o continua a simula��o de aloca��o.
                Quando a aloca��o para cima atinge o n�mero m�ximo de passos, o n�mero m�ximo de passos �
                incrementado para a pr�xima itera��o.*/
                else {cout << i << " " << j << "\n";break;}/*Se alcan�ou o n�mero s, ent�o mostra a posi��o
                onde ele seria alocado*/
                }
        }
        mov++;/*Mudo a dire��o de aloca��o*/
    }
}

int main()
{
    int n,s;

    while (cin >> n >> s){/*Enquanto tivermos entrada, procuramos Padm�*/
        find(n,s);/*Chamamos a fun��o que procura a loja s numa matriz n por n*/
    }
    return 0;
}
