
import sys
input = sys.stdin.readline

if __name__ == "__main__":
    P_n = ((1,4,5),(0,2,6),(1,3,7),(2,4,8),(0,3,9),(0,7,8),(1,8,9),(2,5,9),(3,5,6),(4,6,7),
                (0,1,2,3,4),(5,6,7,8,9))
    P_v = list("ABCDEABCDE")
    P_s = list("0123456789")

    T = int(input())
    for tx in range(T):
        S = input().strip()
        opts = [[[],10],[[],11]]
        for c in S:
            deadend = 0
            for opt in opts:
                for adj in P_n[opt[1]]:
                    if P_v[adj] == c:
                        opt[0].append(P_s[adj])
                        opt[1] = adj
                        break
                else:
                    opt.clear()
                    deadend += 1
            if deadend:
                if len(opts) == deadend:
                    print("-1")
                    break
                for _ in range(deadend):
                    opts.remove([])
        else:
            print("".join(min(opts)[0]))
