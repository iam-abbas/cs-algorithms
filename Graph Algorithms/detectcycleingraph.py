def DFS(graph, v):
    color = [-1] * v
    parent = [-1] * v
    time = 0
    for i in range(v):
        if(color[i] == -1):
            DFSvisit(graph, v, i, color, parent, time)
    print(color)
    print(parent)

def DFSvisit(graph, v, s, color, parent, time):
    color[s] = 0
    time += 1
    for i in range(0,v):
        if(graph[s][i]==1):
            if(color[i]==0):
                print("Cycle detected at:",s)
                return
        if(graph[s][i] == 1):
            if(color[i] == 0):
                parent[i] = s
                DFSvisit(graph, v, i, color, parent, time)
    color[s] = 1
    time += 1 


def main():
    Graph=[[0, 1, 1, 0, 0, 0], 
          [1, 0, 0, 1, 0, 0], 
          [0, 0, 1, 0, 0, 0], 
          [0, 0, 1, 1, 0, 0], 
          [0, 0, 0, 0, 0, 0], 
          [0, 0, 0, 0, 0, 1]] 
    v = len(Graph[0])
    DFS(Graph, v)

if __name__ == '__main__':
    main()
