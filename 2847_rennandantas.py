entrada=input()
tamanho=len(entrada)

letras=[0 for j in range(8)]

for i in range(tamanho):
    if (entrada[i]=='I'):
        letras[0]+=1
    if (entrada[i]=='l'):
        letras[1]+=1
    if (entrada[i]=='o'):
        letras[2]+=1
    if (entrada[i]=='v'):
        letras[3]+=1
    if (entrada[i]=='e'):
        letras[4]+=1
    if (entrada[i]=='y'):
        letras[5]+=1
    if (entrada[i]=='u'):
        letras[6]+=1
    if (entrada[i]=='!'):
        letras[7]+=1

letras[2]//=2
        
minimo=tamanho        
for i in range(8):
    if (letras[i]<minimo):
        minimo=letras[i]
        
print(minimo)
