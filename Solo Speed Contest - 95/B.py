t = int(input())
for _ in range(t):
    n, x, y = map(int, input().split())
    arr = list(map(int, input().split()))
    temp = [0]*101
    range_ = x * y
    for i in range(n):
        mn, mx = max(1, arr[i]-range_), min(100, arr[i]+range_)
        for j in range(mn, mx+1):
            temp[j] = 1
    count = sum(temp)
    print(100 - count)
