t = int(input())
for _ in range(t):
    n, x, s = map(int, input().split())
    c = x
    for i in range(s):
        a, b = map(int, input().split())
        if c == b:
            c = a
        elif c == a:
            c = b
    print(c)
