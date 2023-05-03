s = input()
size = len(s)
f = [0] * 10
pos = 0
max = 0

for i in range(size):
    f[ord(s[i]) - 48] += 1

for i in range(9, -1, -1):
    if f[i] >= max:
        max = f[i]
        pos = i

print(pos)
