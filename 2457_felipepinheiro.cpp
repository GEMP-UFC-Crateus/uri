#include<iostream>
#include <iomanip>
#include<string>
 
using namespace std;
 
int main() {
char letra;
string k;
float contCima = 0, contBaixo = 1;
int retorno =0;

cin >> letra;
cin.ignore(80, '\n'); 
/* Esse trecho serve para ocorrer a leitura do getline, sem ele a linha
19 iria ler apenas o /n e não a frase
*/

getline(cin, k); // Vai ser pego a frase


int i = 0; //Contador que vai percorrer a frase

do{
if(k[i] == letra){
    retorno++; /* Vai aumentar um se a letra estiver na palavra, 
    sem utilizar ele iria ter letras a mais visto que ele quer saber apenas se a letra está na palavra
    não a quantidade de vezes que ela ta na frase
    */
}
if(k[i] == ' '){ // Serve para saber que está começando uma nova palavra
    contBaixo++; // Quantidade de palavras na frase
    if(retorno !=0)
    {
        retorno = 0; // Vai ser zerado para uma nova verificação com outra palavra
        contCima++; // Possui a letra na palavra
    }
}
i++;
}while(i < k.size());

if(retorno != 0){ // Verifica se tinha uma letra na ultima palavra
contCima++;
}

float resp = (contCima/contBaixo) * 100; // Pegando a porcentagem

cout << fixed << setprecision(1); // Deixando uma casa decimal
cout << resp << endl;
system("pause");
return 0;
}