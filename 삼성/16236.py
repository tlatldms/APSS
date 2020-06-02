from collections import deque

dxy = [[-1,0], [0,1], [1, 0], [0, -1]]

N, K = int(input()), int(input())
board = [[0]*(N+1) for _ in range(N+1)]
for _ in range(K):
    a,b = list(map(int, input().split()))
    board[a][b] = 'a'
L = int(input())
dirs = deque()
nd = 1 #오른쪽
for _ in range(L):
    a, b = input().split()
    dirs.append((int(a), b))

cnt = 0
x, y = 1, 1
snake = deque()
next_turn = dirs[0][0]
snake.append((1,1))
while True:
    cnt+=1
    x = x + dxy[nd][0]
    y = y + dxy[nd][1]
    #print(x,y, len(snake))
    if x < 1 or x > N or y < 1 or y > N: #벽에 닿았음
        answer = cnt
        break
    if board[x][y] == 's':  # 자기 몸에 닿았음
        answer = cnt
        break

    snake.appendleft((x,y))

    if board[x][y] == 'a': #사과 먹을 때
        pass
    else: # 사과 안먹으면 꼬리 자르기
        tx, ty = snake.pop()
        board[tx][ty] = 0
    board[x][y] = 's'

    if next_turn == cnt: # 회전 해야하면
        i, d = dirs.popleft()
        if d == 'D':
            nd = (nd + 1) % 4
        elif d == 'L':
            nd = (nd + 3) % 4
        if dirs:
            next_turn = dirs[0][0]
print(answer)