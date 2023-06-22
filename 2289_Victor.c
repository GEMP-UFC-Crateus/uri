/*  2289 - Distância Hamming - Victor*/

#include <stdio.h>

// Função para calcular a distância de Hamming entre dois números inteiros
int distanciaHamming(int num1, int num2) {
    int resultadoXor = num1 ^ num2;  // Realiza a operação XOR bit a bit entre os números
    int distancia = 0;
    
    // Conta o número de bits diferentes contando os bits 1 no resultado do XOR
    while (resultadoXor > 0) {
        if (resultadoXor & 1) {
            printf("%d", resultadoXor);
            distancia++;
        }
        resultadoXor >>= 1;  // Desloca para a direita para verificar o próximo bit
    }
    
    return distancia;
}

int main() {
    int num1, num2;
    
    printf("Digite o primeiro número inteiro: ");
    scanf("%d", &num1);
    
    printf("Digite o segundo número inteiro: ");
    scanf("%d", &num2);
    
    // Calcula a distância de Hamming entre os números digitados
    int distancia = distanciaHamming(num1, num2);
    
    printf("A distância de Hamming entre %d e %d é: %d\n", num1, num2, distancia);
    
    return 0;
}