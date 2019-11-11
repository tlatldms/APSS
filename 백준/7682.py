def prin(arr):
    for i in range(3):
        for j in range(3):
            print(arr[i][j], end='')
        print()

while 1 :
    S = input()
    if S == 'end': break
    global arr
    arr = [['' for i in range(3)] for j in range(3)]
    xx=0
    oo=0
    for i in range(3):
        for j in range(3):
            arr[i][j] = S[i*3 + j]
            if arr[i][j] == 'X': xx += 1
            elif arr[i][j] == 'O': oo += 1

    if xx - oo > 1:
        print(invalid)
        
    prin(arr)

