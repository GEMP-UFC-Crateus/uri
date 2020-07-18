while(True):
    try:
        
        M=float(input())
        T=int(M*240)

        h=(((int(T/3600))+6)%24)
        T=T%3600
        m=int(T/60)
        s=int(T%60)
        
        if(h>=0 and h<6):
            print("De Madrugada!!")
        if(h>=6 and h<12):
            print("Bom Dia!!")
        if(h>=12 and h<18):
            print("Boa Tarde!!")
        if(h>=18 and h<24):
            print("Boa Noite!!")

        print('{0:0>2}:'.format(h),end='')
        print('{0:0>2}:'.format(m),end='')
        print('{0:0>2}'.format(s))
        
    except EOFError:
        break
