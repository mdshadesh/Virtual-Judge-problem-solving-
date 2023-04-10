import bisect, heapq, sys, math, copy
from collections import defaultdict, deque
sys.setrecursionlimit(10**7)
def INT(): return int(input())
def MI(): return map(int, input().split())
def MS(): return map(str, input().split())
def LI(): return list(map(int, input().split()))
def LS(): return list(map(str, input().split()))
INF = 1<<62


S = input()
K = int(input())

ans = []
for i in range(len(S)):
    if S[i] != 'a' and K >= ord('z')-ord(S[i])+1:
        ans.append('a')
        K -= ord('z')-ord(S[i])+1
    else:
        ans.append(S[i])

if 'a' in ans:
    K %= 26

ans[-1] = chr((ord(ans[-1])-ord('a')+K)%26 + ord('a'))

print(''.join(ans))