# 61. 특정 수 만들기(DFS : MS 인터뷰)
# N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 특정 수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요.
# 각 원소는 연산에 한 번만 사용합니다.
# 예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
# 2+4+6=12
# 4+8=12
# 6+8-2=12
# 2-4+6+8=12
# 로 총 4가지의 경우가 있습니다. 만들어지는 경우가 존재하지 않으면 -1를 출력한다.
# ▣ 입력설명
# 첫 번째 줄에 자연수 N(1<=N<=10)와 M(1<=M<=100) 주어집니다.
# 두 번째 줄에 집합의 원소 N개가 주어진다. 각 원소는 중복되지 않는다.
# ▣ 출력설명
# 첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.
# ▣ 입력예제 1
# 4 12
# 2 4 6 8
# ▣ 출력예제 1
# 4

import sys

a,b = map(int,sys.stdin.readline().split())
lst = list(map(int,sys.stdin.readline().split())) # 0 2 4 6 8
cnt = 0
lst.insert(0,0)
res = [0 for i in range(0,a+1)]
def func(i,val,sum):
    global cnt, res
    #print("i :%d ,val : %d ,sum : %d" % (i, val , sum))
    res[i]=val
    if i == a :
        if sum == b :
            cnt = cnt +1
            print(res)
        return
    else :
        func(i+1,lst[i+1],sum+lst[i+1])
        func(i + 1, -lst[i+1],sum-lst[i+1])
        func(i + 1, 0,sum)
func(0,0,0)
print(cnt)



#### 디버깅 (1)
# a,b = map(int,sys.stdin.readline().split())
# lst = list(map(int,sys.stdin.readline().split())) # 0 2 4 6 8
# cnt = 0
# lst.insert(0,0)
# res = []
# def func(i,b):
#     print("i :%d ,val : %d" %(i , lst[i] * b))
#     global cnt , res
#     if i == a :
#         return
#     else :
#         func(i+1,1)
#         func(i + 1, -1)
#         func(i + 1, 0)
# func(0,0)
# print(cnt)

# 0 부터 시작 : func(0,0)
# 2 (i=1 , lst[i] = 2 )
    # +4 (i=2)
        # +8 (i=3)
        # -8
        # 8 x
    # -4
        # +8
        # -8
        # 8 x
    # 4 X
        # +8
        # -8
        # 8x
# -2
    # +4
        # +8
        # -8
        # 8 x
    # -4
        # +8
        # -8
        # 8 x
    # 4 X
        # +8
        # -8
        # 8x
# 2 x
    # +4
        # +8
        # -8
        # 8 x
    # -4
        # +8
        # -8
        # 8 x
    # 4 X
        # +8
        # -8
        # 8x
