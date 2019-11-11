import queue;
dir = [[0,1,0], [0,0,1], [0,-1,0], [0, 0, -1], [1, 0, 0], [-1,0, 0 ]]
global L,R,C,z,x,y, info, visited

def fun():
    q = queue.Queue()
    q.put([z, x,y])
    while not q.empty():
        now = q.get()
        now_z = now[0]
        now_x = now[1]
        now_y = now[2]
        if info[now_z][now_x][now_y] == 'E':
            print("Escaped in", visited[now_z][now_x][now_y],"minute(s).")
            return
        for i in range(6):
            next_z = now_z + dir[i][0]
            next_x = now_x + dir[i][1]
            next_y = now_y + dir[i][2]

            if next_z<0 or next_z>=L or next_x<0 or next_x>=R or next_y<0 or \
                next_y>=C or visited[next_z][next_x][next_y] != 0 or \
                info[next_z][next_x][next_y] == '#': continue
            q.put([next_z, next_x, next_y])
            visited[next_z][next_x][next_y] = visited[now_z][now_x][now_y]+1
    print("Trapped!")

while 1:
    L, R, C = map(int, input().split())

    if L==0 and R == 0 and C == 0:
        break

    info = [[[0] for r in range(R)] for l in range(L)]
    visited = [[[0]*C for r in range(R)] for l in range(L)]
    for i in range(L):
        for j in range(R):
            info[i][j] = input()
            for k in range(C):
                if info[i][j][k] == 'S':
                    z, x,y = (i,j,k)
        input()

    fun()
