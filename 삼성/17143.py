

def move(sharks, N, M):
    global board
    for q, shark in enumerate(sharks):
        r, c, s, d, z = shark
        if r == -1:
            continue
        nr, nc, nd, ls = r, c, d, s
        while True:
            nr += dxy[d][0]
            nc += dxy[d][1]
            if nr < 1 or nr > N or nc <1 or nc > M or ls <= 0:
                break
            ls -=1
        nr -= dxy[d][0]
        nc -= dxy[d][1]

        #방향 올바르게 바꿔주기
        if d == 1 and nr == 1:
            nd = 2
        elif d == 2 and nr == N:
            nd = 1
        elif d == 3 and nc == M:
            nd = 4
        elif d == 4 and nc == 1:
            nd = 3



        if nd == 1 or nd == 2:
            mok = int(ls/(R-1))
            nam = ls % (R-1)
        else :
            mok = int(ls / (C - 1))
            nam = ls % (C-1)
        #print(q, "nd, ls, mok, nam", nd, ls, mok, nam)
        if mok % 2 == 0: #짝수: 방향그대로
            tmpd = nd
        else : #홀수: 방향이 바뀜
            tmpd = rev[nd]
            if nd == 1:
                nr = 1
            elif nd == 2:
                nr = N
            elif nd == 3:
                nc = M
            elif nd == 4:
                nc = 1
        while nam > 0:
            nr += dxy[tmpd][0]
            nc += dxy[tmpd][1]
            nam -= 1
        sharks[q] = [nr, nc, s, tmpd, z]
        #print(q, ": ", nr, nc)
    board = [['X']*102 for _ in range(102)]
    for i, s in enumerate(sharks):
        if s[0] == -1: continue
        if board[s[0]][s[1]] != 'X':
            sharks[board[s[0]][s[1]]][0] = -1 #삭제
        board[s[0]][s[1]] = i

def catch(i):
    global R, answer, board
    for rr in range(1, R+1):
       if board[rr][i] != 'X':
           #print("GOT IT")
           answer += sharks[board[rr][i]][4]
           sharks[board[rr][i]][0] = -1
           break


def print_board(N, M):
    global board
    for x in range(1, N+1):
        for y in range(1,M+1):
            print(board[x][y], end="")
        print()
answer = 0
R,C,M = list(map(int, input().split()))
dxy = [[-3,-3],[-1,0],[1,0], [0,1], [0,-1]]
rev = [0, 2,1,4,3]
sharks = []
board = [['X']*102 for _ in range(102)]
for i in range(1, M+1):
    new_shark = list(map(int, input().split()))
    sharks.append(new_shark)
sharks.sort(key=lambda x : x[4])
for i, x in enumerate(sharks):
   board[x[0]][x[1]] = i

for x in range(1, C+1):
    catch(x)
    move(sharks, R, C)
    #print("after move:")
    #print(sharks)
    #print_board(R, C)

print(answer)




