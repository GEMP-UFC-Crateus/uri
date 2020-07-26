// https://www.urionlinejudge.com.br/judge/pt/problems/view/2733

#include <bits/stdc++.h>

#define endl "\n"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0); // truque para ler entradas grandes.
    int n, v;
    // lendo numero de livros
    while (cin >> n) {
        deque<int> a;
        deque<int>::iterator it;
        int count = 0;
        // para cada livro
        for (int i = 1; i <= n; i++) {
            cin >> v;
            // ponteiro para armazenar posicao do livro no armario
            it = find(a.begin(), a.end(), v);
            // se o livro nao esta no armario
			if (it == a.end()) {
			    count++;
			    // adiciona o livro no armario
			    a.push_back(v);
			    // se tiver mais de 4 livros entao remove o livro do topo.
			    if (a.size() > 4) a.erase(a.begin());
			} else {
				// se o livro estiver no armario, entao remove ele e adiciona no topo.
			    a.erase(it);
			    a.push_back(v);
			}
        }
        // imprime o contador.
        cout << count << endl;
    }
    return 0;
}