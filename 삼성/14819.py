from collections import deque

def pr():
    for i in range(1, 5):
        for j in range(0, 8):
            print(topnis[i][j], end="")
        print()
    print()

def rotate(n, di):
    topni = topnis[n]
    if di == 1:
        topni.appendleft(topni.pop())
    else:
        topni.append(topni.popleft())

topnis = [0]+[deque(map(int, list(input()))) for i in range(4)]
K = int(input())
for i in range(K):
    num, dir = map(int, input().split())
    topni =topnis[num]
    # 회전
    left, right=topni[6], topni[2]
    rotate(num, dir)
    left_num, right_num = num-1, num+1
    left_dir, right_dir = dir, dir
    while left_num > 0:
        if left == topnis[left_num][2]: break
        left = topnis[left_num][6]
        left_dir *= -1
        #print("left", left_num, dir)
        rotate(left_num, left_dir)
        left_num -= 1

    while right_num < 5:
        if right == topnis[right_num][6]: break
        right = topnis[right_num][2]
        right_dir *= -1
        #print("right", right_num, dir)
        rotate(right_num, right_dir)
        right_num += 1
score=1
answer=0
for i in range(1, 5):
    if topnis[i][0] == 1:
        answer += score
    score *= 2
print(answer)