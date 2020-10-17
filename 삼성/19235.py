import copy
import sys

# sys.stdin = open("input.txt", "r")
N = int(input())

global score
score = 0
global green, blue
board = [[[0]*4 for _ in range(10)] for __ in range(2)]


def first_down(color, blocks, bcnt):
    if color == 1:
        for block in blocks:
            tmp = block[0]
            block[0] = block[1]
            block[1] = 3 - tmp
    flag = True
    while flag:
        for block in blocks:
            block[0] += 1
        for block in blocks:
            if block[0] >= 10 :
                flag = False
                break
            if board[color][block[0]][block[1]] != 0: # 못감
                flag = False
                break
    for block in blocks:
        block[0] -= 1
    for block in blocks:
        board[color][block[0]][block[1]] = bcnt
    while checker(color):
        down(color)
    special(color)


def print_board(color):
    for i in range(4, 10):
        for j in range(4):
            print(board[color][i][j], end=" ")
        print()
    print()


def special(color):
    for _ in range(2):
        flag = False
        for j in range(4):
            if board[color][5][j] != 0:
                flag = True
                break

        if flag: # 특별구간에 있음
            fillit(9, color)

def find_me(xx, yy, color):
    dxy = [[-1,0], [0,1]]
    for k in range(2):
        nx = xx + dxy[k][0]
        ny = yy + dxy[k][1]
        if nx < 4 or ny > 3: continue
        if board[color][nx][ny] == board[color][xx][yy]: # 나랑 같은애면
            return [[xx,yy],[nx, ny]]

    return [[xx,yy]]

def down(color):
    visit ={}
    for i in range(9, 3, -1):
        for j in range(4):
            bnum = board[color][i][j]
            if bnum != 0 and bnum not in visit: #블록이 있으면
                visit[bnum] = True
                blocks = find_me(i, j, color)
                to_erase = copy.deepcopy(blocks)
                flag = True
                while flag:
                    for block in blocks:
                        block[0] += 1
                    for block in blocks:
                        if block[0] >= 10:
                            flag = False
                            break
                        if board[color][block[0]][block[1]] != 0 and board[color][block[0]][block[1]] != bnum:  # 못감
                            flag = False
                            break
                for block in blocks:
                    block[0] -= 1
                for b in to_erase:
                    board[color][b[0]][b[1]] = 0
                for block in blocks:
                    board[color][block[0]][block[1]] = bnum


def fillit(gizun, color):
    for i in range(gizun, 3, -1):
        for j in range(4):
            board[color][i][j] = board[color][i - 1][j]



def checker(color):
    global score
    arr = []

    for i in range(4, 10):
        flag = True
        for j in range(4):
            if board[color][i][j] == 0 :
                flag = False
                break
        if flag: # 한줄이 다 차있음
            arr.append(i)

    for r in arr:
        for k in range(4):
            board[color][r][k] = 0
        score += 1

    if arr: return True
    else: return False

def counter(color):
    cnt = 0
    for i in range(4, 10):
        for j in range(4):
            if board[color][i][j] != 0:
                cnt += 1
    return cnt

block_cnt = 1
for _ in range(N):
    t, x, y = map(int, input().split())
    # print(t,x,y)
    if t == 1:
        b = [[x,y]]
    elif t == 2:
        b = [[x,y], [x, y+1]]
    else:
        b = [[x,y], [x+1, y]]
    blocks = copy.deepcopy(b)
    first_down(0, blocks, block_cnt)
    first_down(1, b, block_cnt)

    block_cnt += 1
print(score)
print(counter(0)+counter(1))
