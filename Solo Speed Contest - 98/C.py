for _ in range(int(input())):

    n,k = map(int,input().split())
    s = set(list(map(int,input().split())))
    c = 0
    while True:
        if c not in s:
            if k==0:
                break 
            else:
                k-=1 
                c+=1 
        else:
            c+=1 
        
    print(c)