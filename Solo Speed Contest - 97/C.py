for i in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    
    bit_l = [0 for i in range(32)]
    
    for x in l:
        t = x
        j = 0
        while t != 0:
            bit_l[j] += (t & 1)
            t >>= 1
            j += 1
            
    ret_n = 0
    for j in range(31, -1, -1):
        if bit_l[j] == n:
            ret_n += 2**j
    res = 0
    for x in l:
        res |= x^ret_n
    print(ret_n, res)