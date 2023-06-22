/*1253 - Cifra de César - Victor*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, i, j, k, tam;
    char frase[51];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%s", frase);
        tam = strlen(frase);
        scanf("%d", &k);

        for (j = 0; j < tam; j++)
        {
            if (frase[j] - k < 65)
            {
                frase[j] = frase[j] - k + 26;
            }
            else
            {
                frase[j] = frase[j] - k;
            }
        }
        printf("%s\n", frase);
    }

    return 0;
}