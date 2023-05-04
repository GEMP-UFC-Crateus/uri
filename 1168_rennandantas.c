#include <stdio.h>
#include <string.h>

int main()
{
    int soma, n;
    char numero[102];
    scanf("%d",&n);
    while(n--){
        scanf("%s", numero);
        soma=0;
        for (int i=0;i<strlen(numero);i++){
            if (numero[i]=='0'){soma+=6;}
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