#include <stdio.h>

int main() {
    long long int hashmat, oponente;

    while (scanf("%lld %lld", &hashmat, &oponente) != EOF) {
        if (hashmat > oponente) {
            printf("%lld\n", hashmat - oponente);
        } else {
            printf("%lld\n", oponente - hashmat);
        }
    }

    return 0;
}