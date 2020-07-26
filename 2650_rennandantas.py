lista=[] #Lista vai armazenar a entrada

n,w=[int(val) for val in input().split()] #Valores n (número de Titãs) e w (Altura da Wall)

while(n>0):
    lista=input().split() #Armazenando a entrada na lista
    number=int(lista.pop()) #Pegando a última 'palavra' da entrada que é justamente a altura do titã

    if (number>w): #Se a altura do titã for maior que a altura da wall...
        #..então o titã passa pela wall. Nesse caso, imprimimos o nome desse titã.
        i=0
        for i in range(len(lista)-1):
            print(lista[i],end=' ')
        #Caso o titã tenha mais de um nome, ó último será impresso com quebra de linha. Diferente dos anteriores.
        if (len(lista)>1):
            print(lista[i+1])
        #Se o titã só tem um nome, então esse único nome é impresso no else.
        else:
            print(lista[i])
    
    lista.clear() #Limpamos a lista que armazena as entradas para a próxima entrada.
    n-=1
