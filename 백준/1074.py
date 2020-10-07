import sys
sys.setrecursionlimit(5000)

def dfs(sr, er, sc, ec):
    global tr, tc
    if sr < tr
    #분할해야 할 때
    if er != sr:
        dfs(sr, int((sr+er)/2), sc, int((sc+ec)/2))
        dfs(sr, int((sr + er) / 2), int((sc + ec) / 2) + 1, ec)
        dfs(int((sr+er)/2) + 1, er, sc, int((sc+ec)/2))
        dfs(int((sr+er)/2) + 1, er, int((sc+ec)/2) + 1, ec)
    else:
        global cnt, answer
        if tr == sr and tc == sc:
            answer = cnt
            return
        cnt += 1

N, r, c = list(map(int, input().split()))
global tr, tc, cnt, answer
cnt, tr, tc = 0, r, c
print(2**3-1)
dfs(0, (2**N) -1, 0, (2**N) -1)
print(answer)

