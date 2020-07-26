import collections

armario=collections.deque()

while(True):
    try:
        n=int(input())
        i=0
        contador=0
        armario.clear()
        
        while(i<n):
            
            livro=int(input())
            
            if livro not in armario:
                contador+=1
                armario.appendleft(livro)
                if len(armario)==5:
                    armario.pop()
            else:
                armario.remove(livro)
                armario.appendleft(livro)
            i+=1
        print(contador)    
    
    except EOFError:
        break
