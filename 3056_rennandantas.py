#A única coisa que precisamos saber é a dimensão da matriz. O número de pontos nessa matriz é
#a sua dimensão ao quadrado. De um passo para outro, a dimensão da matriz aumenta a dimensão da
#matriz anterior somanda a uma unidade.*/

n=int(input()) #Número de passos.

#A fórmula fechada para a dimensão da matriz no passo n é (2^n+1). Podemos conseguir esse valor
#analisando que a dimensão da matriz no passo n é igual a duas vezes a dimensão da matriz no passo n-1
#menos uma unidade.

print (((2**n)+1)**2) #Aplicando a fórmula
