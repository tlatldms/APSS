from copy import deepcopy

board = [[(-1, -1)] * 4 for _ in range(4)]
dxy = [[-1,0], [-1,-1], [0, -1], [1,-1],[1,0],[1,1], [0,1], [-1,1]]
fishxy = [(-1,-1,-1)] * 17
for i in range(4):
    arr = list(map(int, input().split()))
    idx = 0
    while idx < 8:

        board[i][idx//2] = (arr[idx], arr[idx+1]-1)
        idx += 2
for i in range(4):
    for j in range(4):
        fishxy[board[i][j][0]] = (i,j,board[i][j][1])

def move_fish(shark_x, shark_y):
    global board, fishxy
    for i in range(1, 17): # 작은 물고기부터
        x, y, d = fishxy[i]
        if d == -1: #먹히고 없음
            continue


        for k in range(8):
            nd = (d+k)%8
            nx = x + dxy[nd][0]
            ny = y + dxy[nd][1]
            if nx < 0 or nx >= 4 or ny < 0 or ny >= 4: # 벽 넘으면
                continue
            if nx == shark_x and ny == shark_y : # 상어가 있으면
                continue
            change_num, change_d = board[nx][ny]
            board[x][y] = (change_num, change_d)
            board[nx][ny] = (i, nd)
            fishxy[i] = (nx, ny, nd)
            if change_num != -1: # 바꿀 물고기가 있었다면 물고기 업데이트해줌
                fishxy[change_num] = (x,y,change_d)
            break


def dfs(depth, shark_x,shark_y, shark_d, _sum, ar):

    global fishxy, answer, tmp, board
    flag = True
    for i in range(1,4):
        nx = (shark_x + (dxy[shark_d][0] * i))
        ny = (shark_y + (dxy[shark_d][1] * i))

        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4 : #벽을 넘음
            break

        if board[nx][ny] != (-1,-1): # 먹을 물고기가 있음

            flag = False
            eaten_num, eaten_d = board[nx][ny]
            #먹히는애 비우기
            tmp_fish = deepcopy(fishxy)
            tmp_board = deepcopy(board)
            board[nx][ny] = (-1,-1)
            fishxy[eaten_num] = (-1, -1, -1) # 물고기 먹기

            #물고기 이동
            move_fish(nx, ny)

            dfs(depth+1, nx, ny, eaten_d, _sum + eaten_num, ar+[eaten_num])

            #되돌리기
            fishxy = tmp_fish
            board = tmp_board

    if flag: # 먹을게 하나도 없었음
        if _sum > answer:
            answer = _sum
            tmp = ar
        return

def print_board():

    for i in range(4):
        for j in range(4):
            print(board[i][j], end= " ")
        print()
    print()

def main():
    global answer, tmp
    tmp = []
    answer = 0
    #첫 물고기 잡기
    first_fish = board[0][0]
    fishxy[first_fish[0]] = (-1,-1,-1)
    board[0][0] = (-1,-1)
    move_fish(0,0)

    dfs(0, 0,0,first_fish[1],0, [])
    print(answer+first_fish[0])

if __name__ == "__main__":
    main()