for _ in range(int(input())):
    p, a, b, c, x, y = map(int, input().split())
    A = a * x + b
    C = a * y + c
    m = min(A, C)
    print(p // m)
