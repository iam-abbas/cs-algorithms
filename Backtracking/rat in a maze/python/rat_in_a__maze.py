SIZE = 5
#maze problem
maze = [
    [0,1,0,1,1],
    [0,0,0,0,0],
    [1,0,1,0,1],
    [0,0,1,0,0],
    [1,0,0,1,0]
]
#list to store the solution matrix
solution = [[0]*SIZE for _ in range(SIZE)]

#function to solve the maze
#using backtracking
def solvemaze(r, c):
    #if destination is reached, maze is solved
    #destination is the last cell(maze[SIZE-1][SIZE-1])
    if (r==SIZE-1) and (c==SIZE-1):
        solution[r][c] = 1;
        return True;
    #checking if we can visit in this cell or not
    #the indices of the cell must be in (0,SIZE-1)
    #and solution[r][c] == 0 is making sure that the cell is not already visited
    #maze[r][c] == 0 is making sure that the cell is not blocked
    if r>=0 and c>=0 and r<SIZE and c<SIZE and solution[r][c] == 0 and maze[r][c] == 0:
        #if safe to visit then visit the cell
        solution[r][c] = 1
        #going down
        if solvemaze(r+1, c):
            return True
        #going right
        if solvemaze(r, c+1):
            return True
        #going up
        if solvemaze(r-1, c):
            return True
        #going left
        if solvemaze(r, c-1):
            return True
        #backtracking
        solution[r][c] = 0;
        return False;
    return 0;
if(solvemaze(0,0)):
    for i in solution:
        print (i)
else:
    print ("No solution")
