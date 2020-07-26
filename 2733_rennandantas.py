import collections

#Armário da Carla
armario=collections.deque()

while(True):
    try:
        #Número de livros
        n=int(input())
        
        #Limpando i, o contador e o armário
        i=0
        contador=0
        armario.clear()
        
        #Para cada livro...
        while(i<n):
            livro=int(input())
            #...se ele não estiver no armário
            if livro not in armario:
                contador+=1 #Incrementa o contador
                armario.appendleft(livro) #Coloca o livro no armário
                if len(armario)==5: #Se extrapolou a capacidade do armário...
                    armario.pop() #...então retira o livro mais a direita que é o que foi lido a mais tempo dentre os que estão no armário
            else:#Se o livro estiver no armário
                armario.remove(livro) #Retira da posição onde ele está...
                armario.appendleft(livro) #...e o reinsere no armário. Esse movimento faz com que ele seja o livro mais recentemente lido.
            i+=1#Incrementa o índide i do while
        print(contador) #Quando sair do while, imprime o contador do caso de teste   
    except EOFError:
        break
