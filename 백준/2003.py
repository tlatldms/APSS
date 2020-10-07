N, M = list(map(int, input().split()))
arr = list(map(int, input().split()))

s, e = 0, 0
sum, cnt = arr[0], 0
while e <len(arr):
    print(sum)
    if sum == M:
        cnt += 1
        sum -= arr[s]
        s += 1
        e += 1
        if e == len(arr): break
        sum += arr[e]
    elif sum > M: # 오히려 더 많을 때
        sum -= arr[s]
        s += 1
    elif sum < M : # 아직 부족할 때
        e += 1
        if e == len(arr): break
        sum += arr[e]


print(cnt)