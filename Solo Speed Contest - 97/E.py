n, m = map(int, input().split())
p = [input() for y in range(n)][::-1]
l = r = d = 0
i = j = 0
for y, t in enumerate(p):
    if '1' in t:
        l, r = min(l - i, r - j) + 2 * m + 2, min(l + i, r + j)
        i, j = t.find('1'), t.rfind('1')
        l, r, d = l - i, r + j, y
print(min(l, r) + d)
