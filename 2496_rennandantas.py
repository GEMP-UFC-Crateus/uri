entrada=list(range(0,26,1)) #Armazenar a entrada
entrada_ordenada=list(range(0,26,1)) #Armazenar a entrada ordenada
n=int(input()) #Armazenar o número de casos de teste

while(n>0): #Enquanto ainda tiver caso de teste para executar...        
    
    n_i=int(input()) #...recebe o número de elementos desse caso de teste
    entrada=input() #Recebe a entrada e a armazena em 'entrada'
    contador=0 #Reseta o contador
    
    entrada_ordenada=sorted(entrada) #Ordena a entrada e armazena em 'entrada_ordenada'. Note que 'entrada' continua sem o efeito da ordenação.
    
    #A ideia é verificar quantas alterações temos entre a entrada original e a entrada ordenada. 
    for i in range(n_i):
        if (entrada[i]!=entrada_ordenada[i]):
            contador+=1
    
    #Se o número de diferenças for maior do que duas, uma única mudança não será suficiente.
    if (contador>2):
            print("There aren't the chance.")
    #Se o número de diferenças é no máximo duas, então uma única alteração é capaz de ordenar a entrada.
    else:
        print("There are the chance.")
    n-=1 
