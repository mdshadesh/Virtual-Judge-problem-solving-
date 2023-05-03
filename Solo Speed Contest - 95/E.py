n, k = map(int, input().split())
p= input().split()
 
w= ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h']
 
q= [str(w[i // len(w)]).upper() + w[i % len(w)] for i in range(55)]
o= k
 
r= q[:(k - 1)]
 
for s in p:
    if s == 'NO':
        r.append(r[-(k - 1)])
    else:
        r.append(q[o])
        o+= 1
 
print(*r)
	 				      		   			 			 	  		