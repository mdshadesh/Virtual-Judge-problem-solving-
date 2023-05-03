def main():
    # read in the input value N
    N = int(input())

    # initialize a list of length N+1 with all values set to 10^8 except for visited[0] which is set to 0
    visited = [10**8] * (N+1)
    visited[0] = 0

    # initialize a variable j to 1
    j = 1

    # loop through each number i from 1 to N
    for i in range(1,N+1):
        # keep incrementing j until we find a value that hasn't been visited for at least i steps
        while visited[j-i] < i:
            # if we've already visited all N values, we can exit the loop
            if j > N:
                break
            # mark the current value j as visited for i steps
            visited[j] = i 
            j += 1
        
        # if we've found a path from 1 to N, print it out and exit the program
        if visited[N] < 10**8:
            # initialize an empty list l to store the path
            l = []
            # start at the end of the path and work backwards, adding each value to l
            id = N
            while visited[id] > 0:
                l.append(visited[id])
                id -= visited[id]
            # print out the path in reverse order
            for a in reversed(l):
                print(a)
            # exit the program
            exit()

if __name__ == "__main__":
    main()
