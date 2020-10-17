#1번

def calculator(p, n):
    m, time = p.split()
    hh, mm, ss = list(map(int, time.split(':')))
    if m == "PM" and hh < 12:
        hh += 12
    elif m == "AM" and hh >= 12:
        hh -= 12

    _time = hh * 3600 + mm * 60 + ss + n
    h = (_time // 3600) % 24
    m = (_time % 3600) // 60
    s = (_time % 3600) % 60
    return "%02d:%02d:%02d" % (h, m, s)


def solution(p, n):
    return calculator(p, n)



# 2번
# 그룹(a,b)을 시작점 기준으로 정렬해두고 돌면서 전구마다 그룹 체크
# 1. 이미 모두 불들어와있으면 X
# 2. 현재 체크중인 그룹(b)의 시작-끝 범위 속의 전구들을 원래 점유하고 있는 그룹들(a)의 시작점-현재 체크중인 그룹(b)의 시작점 까지 모든 전구들에 점유중인 그룹이 2개 이상이라면 a를 없앰

on = [[] for _ in range(5001)]  # 해당 전구에 들어와있는 그룹의 인덱스


def no_need(s, e):  # 들어올 필요가 없으면
    for i in range(s, e + 1):
        if len(on[i]) == 0:
            return False
    return True


def solution(n, groups):
    answer = 0
    groups.sort(key=lambda x: (x[0]))
    for idx, g in enumerate(groups):
        s, e = g[0], g[1]
        if no_need(s, e):  # 들어올 필요가 없으면
            continue
        for i in range(s, e + 1):
            for pre in on[i]:  # 원래 있던 애들 검사. 걔의 시작~ 나의 시작점까지 다른애로 채워지면 치워도됨
                flag = True
                for x in range(groups[pre][0], s):
                    if len(on[x]) == 1:  # 하나만 있으므로 치울수 없음
                        flag = False
                        break
                if flag:  # 치울 수 있음
                    answer -= 1
                    for x in range(groups[pre][0], groups[pre][1] + 1):
                        on[x].remove(pre)
        for i in range(s, e + 1):
            on[i].append(idx)
        answer += 1
    for i in range(1, n + 1):  # 할당된 그룹이 없으면 단일작업
        if not on[i]:
            answer += 1
    return answer

# 3번

from collections import defaultdict


def solution(votes, k):
    answer = ''
    dic = defaultdict(int)
    for v in votes:
        dic[v] += 1
    arr = []
    for key, v in dic.items():
        arr.append((key, v))
    arr.sort(key=lambda x: (-x[1], x[0]))
    gizun, lose = 0, 0
    for i in range(k):
        gizun += arr[i][1]
    for i in range(len(arr) - 1, -1, -1):
        lose += arr[i][1]
        if lose >= gizun:
            return arr[i + 1][0]
    return answer

# 4번

SELECT T.ID, T.NAME
FROM (SELECT P.ID, P.NAME
FROM PLACES P INNER JOIN PLACE_REVIEWS R
ON P.ID = R.PLACE_ID
GROUP BY P.ID) as T, SCHEDULES S
WHERE S.PLACE_ID = T.ID
AND S.SCHEDULED_AT = '2019-01-06'
ORDER BY T.ID