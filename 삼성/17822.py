from collections import deque
N,M,T = list(map(int, input().split()))

onepan = []
onepan.append(deque())
global cnt, _sum
cnt = N*M
_sum = 0
for i in range(N):
    onepan.append(deque(map(int, input().split())))
for i in range(1, N+1):
    for j in range(M):
        _sum += onepan[i][j]


def rotate(num, d, k):
    dq = onepan[num]
    if d == 1: k = M-k
    for i in range(k):
        dq.appendleft(dq.pop())

def erase():
    checker = [[0] * M for i in range(N + 1)]
    flag= False
    global cnt, _sum
    for num in range(1, N+1):
        dq = onepan[num]
        for i in range(M):
            if i == 0:
                prev = M-1
            else:
                prev = i-1

            if dq[i] == dq[prev] and dq[i] != 0:
                flag=True
                checker[num][i] = True
                checker[num][prev] = True

    for j in range(M):
        for i in range(2, N+1):
            if onepan[i][j] == onepan[i-1][j] and onepan[i][j] != 0:
                checker[i][j] = True
                checker[i-1][j] = True
                flag=True
    if flag:
        for i in range(1, N+1):
            for j in range(M):
                if checker[i][j]:
                    cnt -= 1
                    if cnt == 0 :
                        print(0)
                        exit(0)
                    onepan[i][j] = 0
    else:
        avg = hap() / cnt
        for i in range(1, N+1):
            for j in range(M):
                nn = onepan[i][j]
                if nn != 0:
                    if nn < avg:
                        onepan[i][j] += 1
                    elif nn > avg:
                        onepan[i][j] -= 1


def print_onepan():
    print()
    for i in range(1, N+1):
        for j in range(M):
            print(onepan[i][j], end=" ")
        print()

def hap():
    ret = 0
    for i in range(1, N + 1):
        for j in range(M):
           ret += onepan[i][j]
    return ret

for _ in range(T):
    x, d, k = list(map(int, input().split()))
    #원판 회전
    tmp = x
    while tmp <= N:
        rotate(tmp, d, k)
        tmp += x
    # 지우기
    erase()
print(hap())

