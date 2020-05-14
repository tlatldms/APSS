from queue import PriorityQueue
dxy = [[-1,0], [0,-1], [0,1], [1,0]]

def bfs(now_size):
    global board, sx, sy
    q = PriorityQueue()
    q.put((0, sx, sy))
    visit = [[0]*21 for _ in range(21)]
    visit[sx][sy] = 1
    board[sx][sy] = 0
    while not q.empty():
        cnt, x, y = q.get()
        if board[x][y] < now_size and board[x][y] != 0: #catch
            board[x][y] = 9
            sx , sy = x, y
            #print(x, y, cnt)
            return cnt
        for i in range(4):
            nx = x + dxy[i][0]
            ny = y + dxy[i][1]
            if nx < 0 or nx >= N or ny < 0 or ny >= N: continue
            if visit[nx][ny] or (board[nx][ny] > now_size): continue
            visit[nx][ny] = 1
            q.put((cnt+1, nx, ny))
    return -1 #못잡았을 때


N = int(input())
board = [[] for _ in range(N)]
for i in range(N):
    board[i] = list(map(int, input().split()))

fish = [[] for _ in range(7)]
sx, sy = -1, -1
for i in range(N):
    for j in range(N):
        t = board[i][j]
        if t == 9:
            sx, sy = i, j
nsize=1
ret = 0
flag = True
while flag:
    nsize += 1
    for _ in range(nsize):
        r = bfs(nsize)
        if r == -1: #못잡았음
            flag = False
            break
        else: #잡았음
            #print("got next fish in:", r)
            ret += r
print(ret)
