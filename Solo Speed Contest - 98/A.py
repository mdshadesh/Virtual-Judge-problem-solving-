test = int(input())
for _ in range(test):
    n, k = map(int, input().split())
    if n < k:
        print(n)
    elif k == 0 and n != 0:
        print(n)
    elif n == k:
        print(0)
    elif n > k:
        n = n % k
        print(n)
