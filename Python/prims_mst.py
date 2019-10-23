import heapq
from collections import defaultdict

g = defaultdict(list)                   # graph
n, m = map(int, raw_input().split(' ')) # number of vertexes and edges
weight = 0                              # weight of MST
connected = set([])                     # set containing connected vertexes
pq = []                                 # heap

for _ in range(m):
    u, v, c = map(int, raw_input().split(' '))
    g[u].append((c, v))
    g[v].append((c, u))

start = int(raw_input())
connected.add(start)

for tup in g[start]:
    heapq.heappush(pq, tup)

while pq:
    w, b = heapq.heappop(pq)
    if b not in connected:
        weight += w
        connected.add(b)

        for tup in g[b]:
            heapq.heappush(pq, tup)

print weight