// https://www.urionlinejudge.com.br/judge/pt/problems/view/1987

#include <bits/stdc++.h> // standard template library (STL)

using namespace std;

int main() {
	int sum;
	string n, k;
	while (cin >> n >> k) {
		sum = 0;
    // para cada caractere da string, somamos.
		for (char c : k)
		{
      // c - '0' significa que estamos pegando o correspondente valor
      // da tabela ascii e transformando em inteiro. 
			sum += int(c - '0');
		}
    // no final imprimimos a soma e se a soma é divisivel por 3.
		cout << sum << " " << ((sum % 3) ? "nao" : "sim") << "\n";
	}
	return 0;
}

