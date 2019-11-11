def prin():
    for _ in range(N):
        print("i: ",_," ",robots[_])

A,B = map(int, input().split())
N, M = map(int, input().split())
robots = [list(input().split()) for _ in range(N)]
move_alpha = {'N':0,'E':1,'S':2,'W':3}
alpha = ['N', 'E', 'S', 'W']
move = [[0,1], [1,0], [0,-1],[-1,0]] #N E S W
flag=0
for _ in range(N):
    robots[_][0] = int(robots[_][0])
    robots[_][1] = int(robots[_][1])

for i in range(M):
    inst = input().split()
    now_robot = int(inst[0]) - 1
    now_inst = inst[1]
    repeat = int(inst[2])
    if now_inst == 'L' :
        dir_num = move_alpha[robots[now_robot][2]]
        robots[now_robot][2] = alpha[(dir_num + (4 - repeat%4))%4]
    elif now_inst == 'R' :
        dir_num = move_alpha[robots[now_robot][2]]
        robots[now_robot][2] = alpha[(dir_num + repeat)%4]
    else :
        dir_num = move_alpha[robots[now_robot][2]]
        next_y = robots[now_robot][0]
        next_x = robots[now_robot][1]
        while (repeat != 0):
            next_y += move[dir_num][0]
            next_x += move[dir_num][1]
            repeat -= 1
            if (next_y < 1 or next_y > A or next_x<1 or next_x > B) :
                print("Robot",inst[0],"crashes into the wall")
                flag=1
                break
            for i in range(N):
                if robots[i][0] == next_y and robots[i][1] == next_x:
                    print("Robot",inst[0],"crashes into robot",i+1)
                    flag=1
                    break
            if flag == 1: break
        if flag == 1: break
        robots[now_robot][0], robots[now_robot][1] = next_y, next_x
    #prin()

if flag == 0:
    print("OK")