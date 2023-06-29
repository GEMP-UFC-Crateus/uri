/*1160 - Crescimento Populacional*/

#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    int i;
    for (i = 0; i < T; i++) {
        int PA, PB;
        double G1, G2;
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
        int anos = 0;

        while (PA <= PB) {
            PA += (int)(PA * G1 / 100);
            PB += (int)(PB * G2 / 100);
            anos++;

            if (anos > 100) {
                break;
            }
        }

        if (anos > 100) {
            printf("Mais de 1 seculo.\n");
        } else {
            printf("%d anos.\n", anos);
        }
    }

    return 0;
}

