import heapq

#--------------------------------------------
import sys
data = list(map(int, sys.stdin.read().strip().split()))
N, L = data[0], data[1] #inteiros N,L
T = data[2:] #lista com T1, T2, ..., TL
#--------------------------------------------

dude = [[0,i] for i in range(1,N+1)]
qt = [0]*(N+1)
heapq.heapify(dude)

for i in range(len(T)):
    qt[dude[0][1]] += 1
    heapq.heapreplace(dude,[dude[0][0]+T[i],dude[0][1]])

for i in range(1,N+1):
    print(f'{i} {qt[i]}')