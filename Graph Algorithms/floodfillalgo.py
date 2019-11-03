
def floodfill(x, y, oldColor, newColor):

    # assume surface is a 2D image and surface[x][y] is the color at x, y.

    if surface[x][y] != oldColor: # the base case

        return

    surface[x][y] = newColor

    floodfill(x + 1, y, oldColor, newColor) # right

    floodfill(x - 1, y, oldColor, newColor) # left

    floodfill(x, y + 1, oldColor, newColor) # down

    floodfill(x, y - 1, oldColor, newColor) # up
#adjacency matrix representation of graph
surface[M][N] = [[1, 1, 1, 1, 1, 1, 1, 1], 
                  [1, 1, 1, 1, 1, 1, 0, 0], 
                  [1, 0, 0, 1, 1, 0, 1, 1], 
                  [1, 2, 2, 2, 2, 0, 1, 0], 
                  [1, 1, 1, 2, 2, 0, 1, 0], 
                  [1, 1, 1, 2, 2, 2, 2, 0], 
                  [1, 1, 1, 1, 1, 2, 1, 1], 
                  [1, 1, 1, 1, 1, 2, 2, 1]]
#change all the nodes having color 2 to 3
x=4 
y=4
newC= 3
oldColor=2
floodfill(x, y,oldColor,newColor)
#print
for i in range(m):
    for j in range(n):
        print([i][j])
