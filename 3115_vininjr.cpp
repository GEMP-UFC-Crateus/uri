// https://www.urionlinejudge.com.br/judge/pt/problems/view/3115
#include <bits/stdc++.h>

using namespace std;
using Int = unsigned long long int;

#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);

// Tamanho maximo da entrada (10^5)+1
const int MAX = 1e5 + 1;

// vetor de pares para representar o grafo
vector<pair<Int,Int>> graph[MAX];

void dfs(int v, int p, Int min_cap, vector<Int> &ans) {
    // inicia a resposta para o vertice v com o melhor
    // de seus antecessores ate aqui
    ans[v] = min_cap;

    int u;
    Int w;
    // for para pecorrer todos os vertices adjacentes a v
    for (pair<int, Int> e: graph[v]) {
        u = e.first; // u é o vertice vizinho a v
        w = e.second; // w é a capacidade da aresta (u,v)
        if (u == p) continue; // nao pode haver ciclos
        // chamada recursiva atualizando o valor otimo
        // como o minimo ate agora
        dfs(u, v, min(min_cap, w), ans); 
    }
}

int main() {
    _
    int n;
    cin >> n;
    int v, u;
    // vetor para armazenar os resultados
    vector<Int> ans(n + 1);

    Int c;
    for (int i = 1; i < n; i++) {
        // lendo as entradas
        // c representa a capacidade da aresta (v,u)
        cin >> v >> u >> c;
        // no vertice v existe uma aresta para o vertice u
        // com capacidade c
        graph[v].push_back({ u, c });
        graph[u].push_back({ v, c });
    }

    // iniciando o dfs a apartir do vertice 1.
    dfs(n, 1, INT_MAX, ans);

    for (int v = 1; v < n; v++) {
        cout << ans[v];
        if (v != n - 1) cout << " "; // imprimir espaco ate a penultima linha
    }
    cout << endl;
    return 0;
}