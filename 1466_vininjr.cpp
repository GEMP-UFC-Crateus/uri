// https://www.urionlinejudge.com.br/judge/pt/problems/view/1466

#include <bits/stdc++.h> // standard template library (STL)

using namespace std;

struct node { // estrutura utilizada para representar os nós da arvore 
    int val, l, r;
    node() {
        val = l = r = -1; // inicializando os dados do nó
    }
    node(int a) { // recebendo valor do nó por parametro.
        val = a;
        l = r = -1;
    }
};

typedef vector < node > graph; // representacao do grafo(arvore) como uma lista de nos.

void insert(graph & g, int node, int value) { // funcao de insercao de um no na arvore binaria
    if (value < g[node].val) { // se o valor a ser inserido for menor que o valor do no, entao ele vai ser inserido a esquerda.
        if (g[node].l == -1) { // se nao existe um filho esquerdo, entao o valor é adicionado como novo no
            int id = g.size();
            g[node].l = id;
            g.emplace_back(value);
        } else { // se ja existe a funcao e chamada recursivamente para outro no. 
            insert(g, g[node].l, value);
        }
    } else { // caso valor seja maior/igual que o valor do no, entao ele vai ser inserido no filho direito.
        if (g[node].r == -1) {
            int id = g.size();
            g[node].r = id;
            g.emplace_back(value);
        } else {
            insert(g, g[node].r, value);
        }
    }
}

void bfs() { // busca em largura
    int n, val;
    cin >> n; // lendo quantidade de numeros que vai compor a arvore
    graph g;
    g.reserve(n); // seta a capacidade do vector para n, ou mais.
    for (int i = 0; i < n; ++i) {
        cin >> val;
        if (i == 0) { // se for o primeiro elemento basta inseri-lo na lista.
            g.emplace_back(val);
        } else { // se nao for o primeiro, chama a funcao insert pra inseri-lo no lugar correto.
            insert(g, 0, val);
        }
    }
    queue < node > q; // fila pra armazenar os nós
    q.push(g[0]); // adicioando primeiro no(raiz)
    vector < int > ans; // vector pra armazenar os nos em ordem de impressão.
    ans.reserve(n);
    while (!q.empty()) { // enquanto a pilha não estiver vazia
        node cur = q.front(); // primeiro no da fila.
        q.pop(); // removendo primeiro elemento da fila.
        ans.push_back(cur.val);
        if (cur.l != -1) // se o nó tiver um filho esquerdo adiciona o filho esquerdo na pilha
            q.push(g[cur.l]);
        if (cur.r != -1) // o mesmo para o filho direito
            q.push(g[cur.r]);
    }

    for (int i = 0; i < ans.size(); ++i) { // imprimindo os valores do no por nivel
        if (i) cout << " "; // imprimir espaco entre os numeros, menos para o primeiro e o ultimo.
        cout << ans[i];
    }
}

// Note que no enunciado desse problema é dado que os valores são distintos, por isso é optado por utilizar
// emplace_back ao inves de push_back. Pois emplace_back é mais eficiente, embora so possa ser utilizados nesse caso
// particular em que os dados são distintos.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // truque para ler entradas grandes.
    int cases;
    cin >> cases; // lendo a quantidade de casos
    for (int i = 0; i < cases; ++i) {
        cout << "Case " << (i + 1) << ":" << endl;
        bfs(); // para cada caso é da a funcao bfs.
        cout << endl << endl;
    }
    return 0;
}