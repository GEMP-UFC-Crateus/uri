#A �nica coisa que precisamos saber � a dimens�o da matriz. O n�mero de pontos nessa matriz �
#a sua dimens�o ao quadrado. De um passo para outro, a dimens�o da matriz aumenta a dimens�o da
#matriz anterior somanda a uma unidade.*/

n=int(input()) #N�mero de passos.

#A f�rmula fechada para a dimens�o da matriz no passo n � (2^n+1). Podemos conseguir esse valor
#analisando que a dimens�o da matriz no passo n � igual a duas vezes a dimens�o da matriz no passo n-1
#menos uma unidade.

print (((2**n)+1)**2) #Aplicando a f�rmula
