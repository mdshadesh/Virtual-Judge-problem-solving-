t=int(input())
for i in range(t):
    n=int(input()) 
    arr=list(map(int,input().strip().split()))
    if 100<=sum(arr)<100+n-arr.count(0):
        print("YES")
    else:
        print("NO")