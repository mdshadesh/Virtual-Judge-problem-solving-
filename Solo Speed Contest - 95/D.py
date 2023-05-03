t = int(input())

for i in range(t):
    a, b = map(int, input().split())
    if a > b:
        a, b = b, a
    if not a and not b:
        print("YES")
        continue
    if a * 2 < b or a < 0 or b < 0:
        print("NO")
        continue
    if (a + b) % 3 == 0:
        print("YES")
    else:
        print("NO")
