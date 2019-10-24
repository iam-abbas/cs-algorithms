# Getting number of Queens
print ("Enter the number of Queens")
N = int(input())

# Chessboard
# NxN matrix with all the elements 0
chess_board = [[0]*N for _ in range(N)]

def is_attack(i, j):
    # Checking if there is a Queen in row or column
    for k in range(0,N):
        if chess_board[i][k]==1 or chess_board[k][j]==1:
            return True
    # Checking diagonals
    for k in range(0,N):
        for l in range(0,N):
            if (k+l==i+j) or (k-l==i-j):
                if chess_board[k][l]==1:
                    return True
    return False

def N_queen(n):
    # If n is 0, solution found
    if n==0:
        return True
    for i in range(0,N):
        for j in range(0,N):
            '''Checking if we can place a queen here or not
            queen will not be placed if the place is being attacked
            or already occupied'''
            if (not(is_attack(i,j))) and (chess_board[i][j]!=1):
                chess_board[i][j] = 1
                # Recursion
                # Whether we can put the next Queen with this arrangment or not
                if N_queen(n-1)==True:
                    return True
                chess_board[i][j] = 0

    return False

N_queen(N)
for i in chess_board:
    print (i)