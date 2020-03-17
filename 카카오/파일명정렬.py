from functools import cmp_to_key 
def keycompare(x,y):
    if x[0]<y[0]:
        return -1
    elif x[0]>y[0]:
        return 1
    else :
        if x[1] <y[1]:
            return -1
        elif x[1]>y[1]:
            return 1
        else :
            if x[2] <y[2]:
                return -1
            elif x[2]>y[2]:
                return 1
            else:
                return 0
            
def filename_split(files):
    sort_keys=[]
    for i, filename in enumerate(files):
        head=""
        number=""
        digit_check=False
        for ch in filename:
            if ch.isdigit():
                digit_check=True
                number = number + ch
                if len(number)==5:
                    break
            else:
                if digit_check:
                    break
                head=head+ch
        sort_keys.append([head.lower(),int(number),i])
    return sort_keys


def solution(files):
    
    answer = []
    """
    #1. HEAD,NUMBER,TAIL 분리하기 
    #1-1) HEAD : 대문자 or 소문자로 바꿔서 넣기 원래 index랑 (index, 소문자HEAD, 숫자NUMBER)
    #(소문자HEAD, Number,index) // 얘를 정렬하면 순서대로 index  
    sort_keys = filename_split(files)
    #print(sort_keys)
    sort_keys.sort(key=cmp_to_key(keycompare))
    for keys in sort_keys:
        answer.append(files[keys[2]])
        """
    answer = "hello my name is sieun"
    arr = list(map(char,answer))
    print(arr)
    
    return answer