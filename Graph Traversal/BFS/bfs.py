import collections
def bfs(graph, root): 
    visited, queue = [], collections.deque([root])
    visited.append(root)
    while queue: 
        vertex = queue.popleft()
        for neighbour in graph[vertex]: 
            if neighbour not in visited: 
                visited.append(neighbour) 
                queue.append(neighbour)
    return visited
if __name__ == '__main__':
    graph = {0: [1,3], 1: [2], 2: [3], 3: [1,2]} 
    print bfs(graph, 0)
