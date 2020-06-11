// https://www.urionlinejudge.com.br/judge/pt/problems/view/1775

#include <bits/stdc++.h> // standard template library (STL)

#define MAX 1001 // maximo valor que N pode atingir

using namespace std;

int sabores[MAX]; // vetor para armazenar os sabores dos mentos
int pd[MAX][MAX]; // matriz pra armazenar valores ja calculados(pd = programacao dinamica)

const int INF = numeric_limits <int>::max(); // contante para representar o valor infinito, no caso, o maior inteiro representavel.

// funcao para calcular a solucao, onde a e b representa os indices dos extremos do tubo de mentos.
int solve(int a, int b) {
    if (a > b) return 0; // caso indices extrapolem, nenhuma escolha nesse caso.
    if (a == b) return 1;  // caso de indices na mesma posicao, so resta uma escolha neste caso.
    if (pd[a][b] != INF) return pd[a][b]; // se a solucao ja foi calculado retorna o valor armazenado

    int ret = INF; // ret representa o retorno das chamadas recursivas e inicia com infinito pra facilitar.
    // ret é atualizado com o minimo entre seu valor atual, infinito na primeira iteracao, 
    // com o resultado da chamada recursiva para opcao de selecionar o mentos do extremo da direita
    ret = min(ret, 1 + solve(a + 1, b)); 
    ret = min(ret, 1 + solve(a, b - 1)); // ret é atualizado com o minimo do valor atual com a chamada para escolha domentos do extremo da esquerda.

    // se os sabores nas pontas forem iguais, entao ele pega os dois sabores e a recursao é chamada para o restante.
    if (sabores[a] == sabores[b]) ret = min(ret, 1 + solve(a + 1, b - 1));

    pd[a][b] = ret; // armazena o valor do retorno ja calculado para a e b.
    return ret; // return o menor quantidade vezes que andre precisa parar pra pegar mentos, resultado para a e b.
}

// É recomendado utilizar memset ao inves de fill_n, pois opera a nivel de bit e por isso é mais eficiente, 
// mais tive problemas com memset por isso usei fill_n, que ainda assim é mais eficiente que 2 `for` aninhados.

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); // truque para ler entradas grandes.

    int cases, n;
    cin >> cases; // lendo a quantidade de casos

    for (int t = 1; t <= cases; t++) {
        cin >> n; // lendo a quantidade de mentos no tubo

        for (int i = 0; i < n; i++) cin >> sabores[i]; // recebendo sabores dos mentos

        fill_n( *pd, sizeof(pd) / sizeof(**pd), INF); // iniciando/reinicializando toda matriz com valor infinito

        cout << "Caso #" << t << ": " << solve(0, n - 1) << endl; // imprimindo a solucao para o t-esimo caso.
    }
    return 0;
}