#include <stdio.h>
#include <string.h>

int main() {
    int quantidade;
    scanf("%d", &quantidade);

    char a[51], b[51];
    for (int i = 0; i < quantidade; i++) {
        scanf("%s %s", a, b);
        int len_a = strlen(a);
        int len_b = strlen(b);
        int maior = (len_a > len_b) ? len_a : len_b;

        char palavra[102];
        int index = 0;

        for (int j = 0; j < maior; j++) {
            if (j < len_a) {
                palavra[index++] = a[j];
            }
            if (j < len_b) {
                palavra[index++] = b[j];
            }
        }

        palavra[index] = '\0';
        printf("%s\n", palavra);
    }

    return 0;
}