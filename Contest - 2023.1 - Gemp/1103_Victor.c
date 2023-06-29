/*1103 - Alarme Despertador*/

#include <stdio.h>

int main() {
    int H1, M1, H2, M2;

    while (scanf("%d %d %d %d", &H1, &M1, &H2, &M2) == 4 && (H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0)) {
        // Conversão das horas e minutos para minutos
        int minutos1 = H1 * 60 + M1;
        int minutos2 = H2 * 60 + M2;

        // Cálculo do número de minutos para dormir
        int minutosDormir;
        if (minutos1 <= minutos2) {
            minutosDormir = minutos2 - minutos1;
        } else {
            minutosDormir = (24 * 60 - minutos1) + minutos2;
        }

        printf("%d\n", minutosDormir);
    }

    return 0;
}

