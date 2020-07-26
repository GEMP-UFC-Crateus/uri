#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
long long int i,n,k,ni,j,z,contador=0;
long double media_k;

while (cin >> n >> k){

    i=0;
    contador=0;
    vector<long long int> notas;
    vector<long double> media;
    
    while (i<n){
        cin >> ni;
        notas.push_back(ni);
        i++;}

    /*Todas as combinações de notas tomadas 3 a 3*/
    for (i=0;i<n;i++){
        for (j=i+1;j<n;j++){
            for (z=j+1;z<n;z++){
                    media_k=((notas[i]+notas[j]+notas[z])/3.0);/*Calculamos a média*/
                    media.push_back(media_k);} /*E inserimos no vetor de médias*/
    }
  }

    /*Ordenamos as médias*/
    sort(media.begin(),media.end());
    cout << fixed << setprecision(1);
    cout << media[(media.size()-(k))] << endl; /*Imprimimos a k-ésima maior média com a precisão de uma casa decimal*/
}
return 0;
}
