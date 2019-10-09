#!/usr/bin/env python3

# Reference: Rosalind (http://rosalind.info/problems/cc/)

def cc(g):
    """
    >>> graph = [[1, 4], [0], [3, 6, 7], [2, 7], [0, 8, 9], [], [2, 10], \
                 [2, 3, 10, 11], [4, 9], [4, 8], [6, 7, 11], [10, 7]]
    >>> cc(graph)
    3
    """
    def dfs(g, t, seen):
        for v in g[t]:
            if v not in seen:
                seen.add(v)
                dfs(g, v, seen)

    seen = set()
    cnt = 0
    for v in range(len(g)):
        if v in seen:
            continue
        dfs(g, v, seen)
        cnt += 1
    return cnt

if __name__ == '__main__':
    import doctest
    doctest.testmod()

    with open('cc.txt') as f:
        line = f.readline()
        n, m = [int(x.strip()) for x in line.strip().split()]
        graph = [[] for _ in range(n)]
        for edge in range(m):
            line = f.readline()
            i, j = [int(x.strip()) for x in line.strip().split()]
            graph[i-1].append(j-1)
            graph[j-1].append(i-1)

    value = cc(graph)
    print(value)

