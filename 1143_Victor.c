#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int j = 1;
    for (int i = 0; i < x; i++) {
        printf("%d %d %d\n", j, j * j, j * j * j);
        j = j + 1;
    }

    return 0;
}