#6:13
dxy = [[None,None],[-1,0],[1,0],[0,-1],[0,1]]
N, M, k = list(map(int, input().split()))
board=[[] for _ in range(N)]
board2 = [[0]*N for _ in range(N)]
now_location = []

for i in range(N):
    board[i] = list(map(lambda x: [int(x), 0], input().split()))
    for j in range(N):
        if board[i][j][0] != 0:
            board[i][j][1] = k
            now_location.append((board[i][j][0], i, j))
now_location.sort(key=lambda x: -x[0])
now_dir = [0] + list(map(int, input().split()))
priority = [[[] for __ in range(5)] for _ in range(M+1)]
for i in range(1, M+1):
    for d in range(1,5):
        priority[i][d] = list(map(int, input().split()))
time = 0

def check_if_wall(x, y):
    if x >= N or x < 0 or y >= N or y < 0:
        return False
    return True
def print_board():
    for i in range(N):
        for j in range(N):
            print("(",board[i][j][0],",", board[i][j][1],")", end='')
        print()
def time_goes_on(): # 1씩 빼기
    for i in range(N):
        for j in range(N):
            if board[i][j][1] != 0 :
                board[i][j][1] -= 1
                if board[i][j][1] == 0:
                    board[i][j][0] = 0
left_sharks = len(now_location)
while time < 1000:
    time += 1

    for shark in now_location:
        num, x, y = shark
        flag = True
        for d in priority[num][now_dir[num]]: # 각자의 우선순위
            nx = x + dxy[d][0]
            ny = y + dxy[d][1]
            if check_if_wall(nx, ny): # 아무 냄새가 없는 칸
                if board[nx][ny][1] == 0:
                    next_x, next_y = nx, ny
                    now_dir[num] = d
                    flag = False
                    break
        if flag: #냄새가 없는 칸을 못찾음
            for d in priority[num][now_dir[num]]:  # 각자의 우선순위
                nx = x + dxy[d][0]
                ny = y + dxy[d][1]
                if check_if_wall(nx, ny):  # 내 냄새
                    if board[nx][ny][0] == num:
                        next_x, next_y = nx, ny
                        now_dir[num] = d
                        break
        for i in range(len(now_location)):
            if now_location[i][0] == num:
                now_location[i] = (num, next_x, next_y)
        if board2[next_x][next_y] != 0: # 겹치면 상어 지우기
            now_location = list(filter(lambda x: x[0] != board2[next_x][next_y], now_location))
            # print(now_location)
            left_sharks -= 1
            if left_sharks == 1:
                print(time)
                exit(0)
        board2[next_x][next_y] = num
    time_goes_on()
    for i in range(N):
        for j in range(N):
            if board2[i][j] != 0:
                board[i][j] = [board2[i][j], k]  # 보드 업데이트
    board2 = [[0]*N for _ in range(N)]
    # print_board()
    # print()
if left_sharks > 1: print(-1)
