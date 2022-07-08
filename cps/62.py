# 62. 병합정렬
# N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
# 정렬하는 방법은 병합정렬입니다.
# ▣ 입력설명
# 첫 번째 줄에 자연수 N(1<=N<=100)이 주어집니다.
# 두 번째 줄에 N개의 자연수가 공백을 사이에 두고 입력됩니다. 각 자연수는 정수형 범위 안에 있습니다.
# ▣ 출력설명
# 오름차순으로 정렬된 수열을 출력합니다.
# ▣ 입력예제 1
# 8
# 7 6 3 1 5 2 4 8
# ▣ 출력예제 1
# 1 2 3 4 5 6 7 8

import sys
import math

a = int(sys.stdin.readline())
lst = list(map(int,sys.stdin.readline().split()))
lst.insert(0,0)

start = 1
mid = math.ceil((1+8)/2)
end = 8

def func(start,end):
    res = []
    if(start >= end ):
        return
    mid = math.ceil((start + end) / 2)
    func(start, mid-1)
    func(mid, end)
    p1 = start
    p2 = mid
    tmp = []
    while p1 < mid and p2 <= end :
        if lst[p1] > lst[p2]:
            tmp.append(lst[p2])
            p2 = p2 + 1
        else:
            tmp.append(lst[p1])
            p1 = p1 + 1
    while p1 < mid :
        tmp.append(lst[p1])
        p1 = p1 + 1
    while p2 <= end:
        tmp.append(lst[p2])
        p2 = p2 + 1
    print(tmp)
    j=0
    for i in range(start,end+1):
        lst[i] = tmp[j]
        j = j + 1
    #print(res)
#print(lst)

func(start,end)


#디버깅 과정################
# def func(start,end):
#     res = []
#     cur = start
#     for i in range(start,end+1):
#         res.append(lst[i])
#     print(res)
#     if(start >= end ):
#         return
#     #print(start,end)
#     mid = math.ceil((start + end) / 2)
#     func(start, mid-1)
#     func(mid, end)
# 7 6 3 1
    # 7 6
        # 7
        # 6
    # 3 1
        # 3
        # 1
# 5 2 4 8
    # 5 2
        # 5
        # 2
    # 4 8
        # 4
        # 8

