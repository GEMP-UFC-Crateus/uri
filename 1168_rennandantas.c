#include <stdio.h>
#include <string.h> 

int main()
{
    int soma, n; #Variáveis para acumular o somatório da quantidade de leds e a quantidade de entradas respectivamente.
    char numero[110]; #Vetor de caracteres que armazenará cada uma das entradas. 
    scanf("%d",&n); #Quantidade de entradas
    while(n--){
        scanf("%s", numero);
        soma=0; #Resetando o valor do acumulador
        for (int i=0;i<strlen(numero);i++){ #strlen(numero) retorna o tamanho da string 'numero'    
            if (numero[i]=='0'){soma+=6;} #Análise de casos
            else if (numero[i]=='1'){soma+=2;}
            else if (numero[i]=='2' || numero[i]=='3' || numero[i]=='5'){soma+=5;}
            else if (numero[i]=='4'){soma+=4;}
            else if (numero[i]=='6' || numero[i]=='9'){soma+=6;}
            else if (numero[i]=='7'){soma+=3;}
            else if (numero[i]=='8'){soma+=7;}
        }
        printf("%d leds\n",soma);
    }
    return 0;
}
