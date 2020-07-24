// https://www.urionlinejudge.com.br/judge/pt/problems/view/2846

#include <bits/stdc++.h>

using Int = unsigned long long int;
// tamanho maximo tamanho possivel
const Int MAX = 1e5;

using namespace std;

// funcao pra calcular o nth fibonot
// utilizando metodo O(n) para calcular o fibonacci
Int build_fib(Int value) {
    // n_1 representa o fib(n-1), n_2 o fib(n-2) e n o fib(n).
    Int n_1 = 1, n_2 = 1, n = n_1 + n_2;
    // k vai representar o k-esimo fibonot ate entao.
    int k = 1;
    // for a aprtir do 3 ate o MAX.
    for (int i = 3; i <= MAX; i++) {
        // fib(n)=fib(n-1)+fib(n-2)
        n = n_1 + n_2;
        // tam representa o tamanho do intervalo entre o fib(n) e o fib(n-1)
        // ou seja, a quantidade de fibonots neste intervalo
        Int tam = n - n_1 - 1;
        // o k-esimo fibonot não pode ultrapassar MAX, e o intervalo nao pode ser vazio.
        if (k <= MAX && tam > 0) {
            // se o valor que eu estou buscando esta dentro do intervalo,
            // ou seja, fib(n-1)<value<fib(n), entao eu encontrei meu resultado.
            // basta retornar fib(n-1)+quantidade de elementos que precisa para chegar no value.
            if(tam + k > value) 
                return n_1 + 1 + (value - k);
            // atualiza o k-esimo com os novos eelementos do intervalo.
            k += tam;
        }
        // para proxima iteracao fib(n-2)=fib(n-1)
        n_2 = n_1;
        // para a proxima iteracao fib(n-1)=fib(n)
        n_1 = n;
    }
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0); // truque para ler entradas grandes.
    int n;
    // lendo a entrada
    cin >> n;
    cout << build_fib(n) << endl;

    return 0;
}
