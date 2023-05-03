import sys
input = sys.stdin.readline

def read():
    return int(input().strip())

def write(x):
    sys.stdout.write(str(x))

N = 10**5 + 5
s = [0] * N
c = [0] * N
r1 = [0] * N
r2 = [0] * N
g1 = [0] * N
g2 = [0] * N
f1 = [0] * N
f2 = [0] * N

n, w = map(int, input().split())

for i in range(1, n+1):
    s[i], c[i] = map(int, input().split())
    r1[i] = r1[i - 1] + c[i]

for i in range(n, 0, -1):
    r2[i] = r2[i + 1] + c[i]

ans = 0

for i in range(1, n+1):
    ans = max(ans, r1[i] - s[i])
    g1[i] = max(g1[i - 1], r1[i] - 2 * s[i])
    f1[i] = max(f1[i - 1], r1[i] - s[i])

for i in range(n, 0, -1):
    ans = max(ans, r2[i] - w + s[i])
    g2[i] = max(g2[i + 1], r2[i] - 2 * (w - s[i]))
    f2[i] = max(f2[i + 1], r2[i] - w + s[i])

for i in range(n+1):
    ans = max(ans, g1[i] + f2[i + 1])
    ans = max(ans, g2[i + 1] + f1[i])

write(ans)
print('')
