#Lista de 100 posições. A ideia é evitar ficar redimensionando a lista.
entrada=list(range(0,100,1))

#Enquanto não ocorrer EOF...
while(True):
    try:
        
        n=int(input()) #Número de elementos
        entrada=[int(val) for val in input().split(" ")] #Pega os elementos da entrada e armazena na lista 'entrada'
        
        entrada.sort() #Ordena a lista
        
        i=0 #Índice do menor elemento
        j=n-1 #Índice do maior elemento
        soma=0 #Acumulador da soma
        
        #Vamos acumular na variável 'soma' a diferença entre as variáveis de maior e menor valor ainda não somadas
        while(i<j):
            soma+=entrada[j]-entrada[i]
            i+=1 #Vai para o menor valor disponível após essa iteração
            j-=1 #Vai para o maior valor disponível após essa iteração
        
        print(soma) #Imprime o resultado    
        
    except EOFError: #Encerra a execução com o EOF
        break
