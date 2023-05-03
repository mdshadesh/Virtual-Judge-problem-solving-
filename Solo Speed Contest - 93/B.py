p, n = map(int, input().split())
b = [False] * p

for i in range(n):
    t = int(input())
    if b[t % p]:
        print(i+1)
        break
    else:
        b[t % p] = True
else:
    print(-1)
