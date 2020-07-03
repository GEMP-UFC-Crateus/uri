/* Créditos ao Joao Paulo (JoaoPauloA) que desenvolveu boa parte desse código. */
// https://www.urionlinejudge.com.br/judge/pt/problems/view/1872

#include <bits/stdc++.h>

// truque para ler entradas grandes
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(0);

using namespace std;

// funcao para inverter uma string
inline string reverse_string(string str){
    return string(str.rbegin(),str.rend()); 
}

// funcao para verificar se uma string é palindroma
inline bool is_palindrome(string str){
    return str.compare(reverse_string(str)) == 0;
}

// essa funcao é utilizada para remover todos os zeros da direita dos numeros
// para evitar possiveis redundancias
// ex:. o numero 0.0001200 é igual ao numero 0.00012
string removeZerosRight(string str) {
    int size = str.size();
    if (size == 1) return str;
    while (size > 0 && str[size - 1] == '0') {
        size--;
    }
    // se apos eliminar todos os 0 a direita chegarmos a um ponto
    // entao temos que remove-lo
    // ex:. 100.0 é igual a 100, apos remover os zeros a direita teriamos 100.
    if (str[size - 1] == '.') 
        size--;
    str = str.substr(0, size);
    return str;
}

// funcao para formatar a saida do problema
// como temos no maximo 6 casas decimais(dado fornecido pelo problema) e
// contando com o ponto e o numero mais a esquerda, 
// temos no maximo uma string de tamanho 8
// obs: esta acao eh necessaria devido ao arrendodamento de algumas operacoes.
string format_print(string str){
    return removeZerosRight(str.substr(0,8));
}

// funcoes nativas do c++ utilizadas ->
// stod: funcao que transforma string em double
// stoi: funcao que transforma string em inteiro
// to_string: funcao que transforma int/double em string
// string::compare: funcao que compara se uma string eh
// igual a outra, retorna 0 se for verdade.
int main() {_
    int cases;

    cin >> cases;

    while (cases--) {
        string str = "";
        cin >> str; // lendo o dado
        // verificando se o numero tem um ponto e guardando posicao do ponto
        int i = str.find(".");
        str = removeZerosRight(str); // remove zeros a direita da string
        // primeiro caso: verifica se o numero eh palindromo
        if(is_palindrome(str)){
            cout << 0 << endl;
            continue; // o continue pula para a proxima iteracao do while.
        }
        // o segundo caso: se o numero nao possui ponto, ou seja, se eh um numero inteiro.
        // nesse caso basta imprimir 0. o inverso do numero
        // ex:. 122, nao eh palindromo e falta 0.221 para que ele se torne um, 122.221
        if (i == string::npos) {
            cout << "0."+reverse_string(str) << endl;
            continue;
        }

        // integerValue vai ser igual a substring entre o inicio e a posicao do ponto
        // ou seja, a parte inteira, ja decimal value vai depois do ponto ate
        // o final da string, a parte decimal
        string integerValue = str.substr(0, i), decimalValue = str.substr(i+1, str.size());

        // para facilitar a nossa vida e tbm o calculo 
        // tomamos por leftValue o valor do lado inteiro, so que da forma reversa
        // representando o caso em que o menor valor a ser adicionado
        // para que o numero se torne palindromo seja 0. o seu inverso
        // como mostrado no caso 2
        double leftValue = stod("0." + reverse_string(integerValue));
        // rightValue é igual ao valor da parte decimal.
        double rightValue = stod("0."+decimalValue);

        // caso 3: se o valor do inverso da parte inteira for maior que o valor da parte decimal
        // entao basta verificarmos quanto falta para que esses valores se tornem iguais.
        // a resposta é essa diferenca
        // ex:. 12.10, o proximo palindromo seria 12.21, assim pegamos o 12 e invertemos 
        // em termos da parte decimal, ficando assim 0.21, como 0.21 > 0.10,
        // entao o que falta seria 0.21-0.10=0.11 para que se torne um palindromo
        if (leftValue > rightValue) {
            cout << format_print(to_string(leftValue - rightValue)) << endl;
        } else {
            // diferenca entre a parte decimal 1.0
            // isto representa quanto falta para u numero chegar no seu sucessor
            // ex:. 12.33, falta 0.67 para chegar no 13, e note que 1.0-0.33=0.67
            double diff2numbers = 1.0 - rightValue;
            // caso 4: se o valor do inverso da parte inteira for menor que o valor
            // da parte decimal, entao temos dois casos 
            // se o proximo numero for palindromo, entao tudo certo,
            // basta imprimir a diferenca que falta para a parte decimal completar 1.0
            // caso contrario, entao alem de somar o que falta para o proximo 
            // adicionamos o inverso da parte inteira, que é o leftValue
            if (is_palindrome(to_string(stoi(integerValue) + 1))) { // verificando se a parte inteira + 1 é palindromo.
                cout << format_print(to_string(diff2numbers)) << endl;
            } else {
                // note que 0.1 é o inverso de 1, por isso a soma aqui
                cout << format_print(to_string(diff2numbers + leftValue + 0.1)) << endl;
            }
        }

    }
}