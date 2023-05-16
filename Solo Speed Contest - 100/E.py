t = int(input())
for i in range(t):
    n, m, p = map(int, input().split())
    a = sorted(list(map(int, input().split())))
    b = sorted(list(map(int, input().split())))
    c = sorted(list(map(int, input().split())))
    ans = 0
    mod = 1000000007
    a1, b1, c1, d1 = 0, 0, 0, 0
    for j in b:
        while a1 < n and a[a1] <= j:
            c1 += a[a1]
            a1 += 1 
        while b1 < p and c[b1] <= j:
            d1 += c[b1]
            b1 += 1 
        ans += ((a1 * j + c1) * (b1 * j + d1))
    print(ans % mod)
