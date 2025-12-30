def print_sudoku(board):
    for i in range(9):
        if i % 3 == 0 and i != 0:
            print("-"*25)
        row = "| "
        for j in range(9):
            if j % 3 == 0 and j != 0:
                row += "| "
            if board[i][j] == 0:
                row += ". "
            else:
                row += str(board[i][j]) + " "
        row += "|"
        print(row)

def check_empty(board):
    for i in range(9):
        for j in range(9):
            if board[i][j] == 0:
                return i, j
    return None

def is_valid(board, num, pos):
    row, col = pos

    if num in board[row]:
        return False

    
    for i in range(9):
        if board[i][col] == num:
            return False
    
    box_x = col // 3
    box_y = row // 3

    for i in range(box_y * 3, box_y * 3 + 3):
        for j in range(box_x * 3, box_x * 3 + 3):
            if board[i][j] == num :
                return False
            
    return True


def solve_board(board):
    empty = check_empty(board)
    if not empty:
        return True
    
    row, col = empty

    for i in range(1, 10):
        if is_valid(board, i, (row, col)):
            board[row][col] = i
        
            if solve_board(board):
                return True
            
            board[row][col] = 0

    return False

board = [
    [5, 0, 0, 0, 8, 0, 1, 0, 6],
    [0, 0, 0, 0, 7, 3, 2, 8, 4],
    [4, 0, 7, 1, 2, 0, 0, 0, 3],
    [7, 0, 9, 2, 6, 0, 0, 0, 0],
    [0, 0, 3, 0, 4, 5, 0, 1, 0],
    [0, 0, 1, 0, 0, 0, 6, 2, 5],
    [0, 9, 0, 7, 0, 4, 0, 3, 0],
    [0, 7, 0, 0, 0, 2, 8, 9, 0],
    [1, 2, 5, 9, 0, 0, 0, 0, 0]
]

if solve_board(board):
    print("Solved: \n")
    print_sudoku(board)
else:
    print("No Solutions")

