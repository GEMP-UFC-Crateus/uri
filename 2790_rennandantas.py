n=int(input())
dices=[int(val) for val in input().split()]
minimo=1000000

for i in range(1,7):
    contador=0
    for j in range(n):
        if (dices[j]!=i):
            if (dices[j]+i==7):
                contador+=2
            else:
                contador+=1
    if (contador<minimo):
        minimo=contador
        
print(minimo)
