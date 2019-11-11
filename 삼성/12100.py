import copy
global N, visited, dir
m=0
dxdy = [[-1,0], [0,1], [1,0], [0,-1]]
N = int(input())
inp = [list(map(int, input().split())) for i in range(N)]
def prin(arr):
    for i in range(N):
        for j in range(N):
            print(arr[i][j], end='')
        print("\n")

def dfs(old, d, cnt):
    global m
    if cnt == 5:
        if m < int(max(map(max, old))):
            m = max(map(max, old))
        return
    arr = copy.deepcopy(old)
    visited = [[0] * N for i in range(N)]
    if d == 0 or d ==3:
        start_idx, end_idx, ite_dir = 0, N, 1
    else:
        start_idx, end_idx, ite_dir = N-1, -1, -1
    for i in range(start_idx, end_idx, ite_dir):
        for j in range(start_idx, end_idx, ite_dir):
            #print("i:" ,i,"j: ",j)
            #prin(arr)
            if arr[i][j] != 0:
                tmp_i = i
                tmp_j = j
                flag=0
                while tmp_i+dxdy[d][0] >= 0 and tmp_j+dxdy[d][1] >=0 and\
                        tmp_i+dxdy[d][0] < N and tmp_j+dxdy[d][1]<N and \
                        arr[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]] == 0:
                    arr[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]] = arr[tmp_i][tmp_j]
                    arr[tmp_i][tmp_j] = 0
                    tmp_i+=dxdy[d][0]
                    tmp_j+=dxdy[d][1]

                #print("tmp_i:", tmp_i, "tmp_j:", tmp_j, "flag: ", flag)
                if tmp_i + dxdy[d][0] >= 0 and tmp_j + dxdy[d][1] >= 0 and \
                        tmp_i + dxdy[d][0] < N and tmp_j + dxdy[d][1] < N and \
                    not visited[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]]  \
                        and arr[tmp_i][tmp_j] == arr[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]]:
                    #print("dfsdg: ", tmp_i)
                    arr[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]] *= 2
                    arr[tmp_i][tmp_j] = 0
                    visited[tmp_i+dxdy[d][0]][tmp_j+dxdy[d][1]] = 1
    #print(cnt)
    #prin(arr)
    for i in range(4):
        dfs(arr, i, cnt+1)


for i in range(4):
    dfs(inp, i, 0)

print(m)