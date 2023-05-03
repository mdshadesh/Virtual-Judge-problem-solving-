t9 = int(input())
for _ in range(t9):
    n9, x9, y9 = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = 1
    for i in range(n9):
        if (b[i]-a[i] != x9) and (b[i]-a[i] != y9):
            c = 0
            break
    if c == 0:
        print("NO")
    else:
        print("YES")
