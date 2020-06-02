board = [list(map(int, input().split())) for i in range(10)]
ones = 0
for i in range(10):
    for j in range(10):
        if board[i][j] == 1:
            ones +=1
answer=99999999999
papers=[-1,5,5,5,5,5]
# 사각형 내에 다 1이고 visit 0인지 확인
def checker(x, y, n):
    for i in range(x, x+n):
        for j in range(y, y+n):
            if board[i][j] != 1:
                return False
    return True

def changeboard(x,y,n):
    for i in range(x, x + n):
        for j in range(y, y + n):
            board[i][j] = 2


def unchangeboard(x,y,n):
    for i in range(x, x + n):
        for j in range(y, y + n):
            board[i][j] = 1


def dfs(xy, cnt):
    if xy == 100:
        global answer
        # print(cnt)
        # quit()
        answer = min(answer, cnt)
        return
    if cnt >= answer: return
    x, y  = xy//10, xy%10
    #print(x, y)
    if board[x][y] != 1:
        dfs(xy+1, cnt)
    else:
        for i in range(5, 0, -1):
            if y + i >= 11 or x + i >= 11: continue
            if papers[i] == 0: continue
            if checker(x, y, i): #다 1이고 unvisit이면
                #print(x,y,i, cnt, papers, left-i*i, visit[6][2])
                changeboard(x, y, i)
                papers[i] -= 1
                #print(papers)
                dfs(xy+i, cnt+1)
                papers[i] += 1
                unchangeboard(x,y,i)

dfs(0, 0)
#print(-1)
if answer == 99999999999:
    answer = -1
print(answer)