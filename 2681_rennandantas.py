MOD=86400

def StringModToInt(numero):
    
 resultado=0
    
 for i in range(len(numero)):
  resultado=(((resultado*10)+int(numero[i]))%MOD)
 return resultado

def binpow(a,b):
    
 if (b==0): return 1;

 res=1
    
 while (b>1):
        
  if (b%2==1): 
    res=((res*(a%MOD))%MOD)
        
  a*=a%MOD
  a%=MOD
  b>>=1

 return (((a%MOD)*(res%MOD))%MOD)

numero=str(input())
    
n=StringModToInt(numero)
    
total=(binpow(2,n)-1)
   
h=int(total/3600)
    
total=(total%3600)

m=int(total/60)

s=(total%60)

print(str(h).zfill(2),end='')
print(':',end='')
print(str(m).zfill(2),end='')
print(':',end='')
print(str(s).zfill(2))
