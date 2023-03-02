def readFile(name):
    path = "/home/lerskk/code/C/exam/" + name
    file = open(path)
    board = []

    for row in file:
        board.append([*row][:-1])

    return board

def checkWinOnRow(board):
    streak = {'player': '_', 'count': 1}

    for row in board:
        print(row)
        for iCell in range(1, len(row)):
            if (streak['count'] == 4):
                streak = {'player': streak['player'], 'win': True}
                return streak

            if (row[iCell] == row[iCell - 1]):
                streak['player'] = row[iCell]
                streak['count'] += 1
            else:
                streak = {'player': '_', 'count': 1}

    streak = {'player': '_', 'win': False}
    return streak

board = readFile("save.txt")
print(checkWinOnRow(board))
