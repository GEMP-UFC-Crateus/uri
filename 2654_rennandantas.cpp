#include <bits/stdc++.h>

using namespace std;

/*Struct para armazenar o nome e dos demais atributos dos candidatos à Godofor*/
typedef struct candidato{
    string nome;
    int p,k,m;
} Candidato;

/*Vetor para armazenar o número máximo de candidatos*/
Candidato cand[101];

/*Função de comporação a ser utilizada na ordenação. A ordenação se dá pelos seguintes critérios:
1) Maior poder;
2) Em caso de empate: maior número de deuses que matou;
3) Persistindo o empate: menor número de vezes que morreu;
4) O último critério é o menor nome lexicográfico.*/

bool comp(Candidato a, Candidato b){
    if (a.p!=b.p) {return a.p > b.p;}
    if (a.k!=b.k) {return a.k > b.k;}
    if (a.m!=b.m) {return a.m < b.m;}
    return (a.nome < b.nome);
}

int main()
{
    int i=0,n;
    
    /*Número de candidatos*/
    cin >> n;
    
    while(i<n){
        /*Recebendo o nome e os demais atributos dos candidatos e inserindo no vetor cand*/
        cin >> cand[i].nome >> cand[i].p >> cand[i].k >> cand[i].m;
        i++;
    }
    
    /*Ordena o vetor 'cand' com base na função comp*/
    sort(&cand[0],&cand[n],comp);
    
    /*Imprime o nome do primeiro candidato de acordo com os critérios.*/
    cout << cand[0].nome << endl;

    return 0;
}
