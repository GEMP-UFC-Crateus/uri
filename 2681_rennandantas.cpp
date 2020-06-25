/*Créditos ao Marcus Vinícius (vinijr) que desenvolveu boa parte desse código.*/

#include <iostream>
#include <vector> 
#include <iomanip>
#define MOD 86400

using namespace std;

using Int=unsigned long long int;

/*Função que converte a string em número observando o módulo.*/
Int StringModToInt(string numero){
    Int resultado=0;
    for (int i=0;i<numero.length();i++){
        /*Tomamos cada caracter da string e o convertemos para uma parte do número inteiro.*/
        /*O (Int) retornará o número relacionado do caracter na tabela ASCII. Como o número 
        0 é 48 na tabela ASCII, o número 1 é 49 e assim por diante, sempre executaremos a 
        subtração do caracter a ser transformado por '0'.*/
        resultado=(((resultado*10)+(Int)(numero[i]-'0'))%MOD);}
    return resultado;
}

/*Função que realizará a exponenciação de a^b com a verificação do módulo MOD.*/
Int binpow(Int a, Int b){
    
    if (b==0) return 1;/*Em caso de expoente 0.*/
    
    /*Se o expoente for maior que zero, então prosseguimos da seguinte forma.*/
    Int res=1;
    
    while (b>1){
        
        if (b%2==1){
           /*Quando o expoente é impar, aumentamos em um o expoente do nosso acumulado. */
           res=((res*(a%MOD))%MOD);
        }
        /*Consideramos que o expoente é par. Se não o for, a informação adicional ficou 
        armazenada no if anterior.*/
        a*=a%MOD;/*A variável a, por sua vez, também funciona como um acumulador. É como 
        se ela acumulasse os expoentes relacionados aos b's pares. Dividiremos o b por 2 mas 
        compensarmos no acúmulo do expoente em a.*/
        a%=MOD;
        b>>=1;/*Deslocamento de bit para a direita dividindo, assim, o b por dois. Se 
        o b era ímpar, então a informação adicional foi armazenada no if.*/
    }
    /*Quando o expoente for 1, finalmente encerramos a execução.*/
    return (((a%MOD)*(res%MOD))%MOD);
}

int main()
{
    Int n,h,m,s,total;
    string numero;
    
    /*Recebe o número da entrada.*/
    cin >> numero;
    
    /*O número pode ser muito grande. Como estamos interessados apenas no trabalho que será realizado no último dia, 
    faremos o seguinte procedimento: receberemos a entrada como uma string e a converteremos em um número usando uma 
    técnica que utiliza módudo. Dessa forma, garantiremos que o número nunca será muito grande.*/
    n=StringModToInt(numero);
    
    /*O número n corresponde ao número de discos que ficaram para o último dia de trabalho. O binpow usa módulo também. 
    Assim garantimos que o número não cresça muito.*/
    total=(binpow(2,n)-1);
   
    /*Dividindo o total de movimentos por 3600, saberemos quantas horas foram necessárias no último dia.*/
    h=(total/3600);
    
    /*Atualizando o restante dos movimentos.*/
    total=(total%3600);
    /*Dividindo o restante de movimentos por 60, saberemos quantos minutos foram necessárias no último dia.*/
    m=(total/60);
    /*Dividindo o restante de movimentos por 60, saberemos quantos segundos foram necessárias no último dia.*/
    s=(total%60);
    
    /*Indicamos que eventuais preenchimentos devem ser feitos com 0.*/
    cout.fill('0'); 
    /*Indicamos que o campo de impressão deve ter tamanho 2. Se o número de saída não tiver esse tamanho, 
    então será completado com 0 de acordo com o comando fill.*/
    cout << setw(2) << h << ":" << setw(2) << m << ":" << setw(2) << s << endl;
    
    return 0;
}
