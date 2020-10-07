def find(x) :
    global root
    if root[x] == x :
        return x
    else:
        p = find(root[x])
        root[x] = p
        return p

T = int(input())
for _ in range(T):
    N = int(input())
    size = {}
    global count
    global root
    root={}
    for __ in range(N):

        a, b = input().split()

        if a not in root:
            root[a] = a
            size[a] = 1
        if b not in root:
            root[b] = b
            size[b] = 1

        # root 각자 찾고
        if a < b:
            a, b = b, a

        roota = find(a)
        rootb = find(b)
        if roota == rootb:
            print(size[roota])
            continue

        print(size[roota] + size[rootb])

        #root 업데이트
        root[roota] = rootb
        size[rootb] += size[roota]
        size[roota] = 1

