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
    if(start >= end ):
        return
    print(start,end)
    res = []
    for i in range(start,end+1):
        res.append(lst[i])
    print(res)
    mid = math.ceil((start + end) / 2)
    func(start, mid-1)
    func(mid, end)

func(start,end)
#################

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

