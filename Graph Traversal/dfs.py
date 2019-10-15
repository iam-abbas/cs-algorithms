def dfs(graph, root, visited = []): 
    res = [root]
    visited.append(root)
    for neighbour in graph[root]: 
        if neighbour not in visited: 
            res.extend(dfs(graph, neighbour, visited))
    return res
if __name__ == '__main__':
    graph = {0: [1,3], 1: [3], 2: [3], 3: [2,4], 4:[]} 
    print dfs(graph, 0)
