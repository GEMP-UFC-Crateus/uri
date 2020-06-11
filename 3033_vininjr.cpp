// https://www.urionlinejudge.com.br/judge/pt/problems/view/3033

#include<bits/stdc++.h>

using namespace std;
// Criando tipo para representar a grid.
typedef vector<pair<int,int>> Grid;
// Criando tipo para representar cada elemento da grid, ou seja, um ponto.
typedef Grid::iterator point;

// definindo funcao para pecorrer a grid, somente para diminuir codigo.
#define forEach(it, grid) for (it = grid.begin(); it != grid.end(); it++)
#define YES "Y"
#define NO "N"

// funcao para checar se um ponto p esta dentro do retangulo formado por p1 e p2.
inline bool check_point_in_rectangle(point p1, point p, point p2) {
	return (min(p1 -> first,p2 -> first) <= p -> first && p -> first <= max(p1 -> first,p2 -> first)) && 
		   (min(p1 -> second,p2 -> second) <= p -> second && p -> second <= max(p1 -> second,p2 -> second));
}

// 
bool check(point p1, point p2, Grid &grid) {
    // verifica se p1 e p2 estao na mesma linha ou coluna, caso positivo entao eles estao respeitando a propriedade.
    if (p1 -> first == p2 -> first || p1 -> second == p2 -> second) return true;
    point p;
    forEach(p, grid) {
        // para todo ponto p, diferente de p1 e p2, é chamada pra verificar se ele esta no retangulo limitado por p1 e p2.
        if (p != p1 && p != p2 && check_point_in_rectangle(p1, p, p2)) return true;
    }
    return false;
}

// funcao para resolver se a grid é arboriamente satisfeita.
string solve(Grid &grid) {
	point p1, p2; // dois pontos quaisquer
    forEach(p1, grid) { // para todos os pontos da grid
        forEach(p2, grid) {
            // para pontos diferentes, é verificado se eles respeitam a propriedade
            // perceba que se apenas um ponto não respeita, entao a grid completa nao respeita.
            if (p1 != p2 && !check(p1, p2, grid)) return NO;
        }
    }
    return YES;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL); // truque para ler entradas grandes
    int m, n, p, x, y;
    Grid grid; // Declarando a grid.

    while (cin >> n >> m >> p) { // lendo as entradas enquanto for diferente de EOF

        while (p--) {
            cin >> x >> y; // lendo os valores x e y do ponto (x,y)
            // a funcao make_pair(x,y) retorna um objeto tupla com (x,y)
            grid.push_back(make_pair(x, y)); // adicionando a tupla (x,y) na grid
        }

        cout << solve(grid) << endl;
        grid.clear(); // ao fim da execucao é eliminando os elementos da grid para proxima iteracao.
    }
    return 0;
}