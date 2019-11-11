import sys
sys.setrecursionlimit(10**6)

def prin():
    for i in range(n):
        for j in range(n):
            print(arr[i][j])

def dfs(now_x, now_y):
    if dp[now_x][now_y] == 1:
        for i in range(4):
            next_x = now_x + di[i][0]
            next_y = now_y + di[i][1]

            if next_x < 0 or next_x >= n or next_y < 0 or next_y >=n: continue
            #print("next_x: ", next_x, "next_y: ", next_y)
            if arr[next_x][next_y] > arr[now_x][now_y]:
                a = dfs(next_x, next_y) + 1
                if dp[now_x][now_y] < a:
                    dp[now_x][now_y] = a
        #print("now_x: ", now_x, "now_y: ", now_y)
    return dp[now_x][now_y]

global n, arr, dp, di, visited
n = int(input())
arr = [list(map(int, input().split())) for i in range(n)]
dp = [[1]*n for _ in range(n)]

di = [[0,1], [0,-1], [1,0], [-1,0]]
visited = [[False]*n for _ in range(n)]
m = -1

for i in range(n):
    for j in range(n):
        tmp = dfs(i,j)
        if m < tmp:
            m = tmp

print(m)
