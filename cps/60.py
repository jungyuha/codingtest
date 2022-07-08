# 60. 합이 같은 부분집합(DFS : 아마존 인터뷰)
# N개의 원소로 구성된 자연수 집합이 주어지면, 이 집합을 두 개의 부분집합으로 나누었을 때 두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 “YES"를 출력하고,
# 그렇지 않으면 ”NO"를 출력하는 프로그램을 작성하세요.
# 예를 들어 {1, 3, 5, 6, 7, 10}이 입력되면 {1, 3, 5, 7} = {6, 10} 으로 두 부분집합의 합이 16으로 같은 경우가 존재하는 것을 알 수 있다.
# ▣ 입력설명
# 첫 번째 줄에 자연수 N(1<=N<=10)이 주어집니다.
# 두 번째 줄에 집합의 원소 N개가 주어진다. 각 원소는 중복되지 않으며 그 크기는 1,000,000 이하입니다.
# ▣ 출력설명
# 첫 번째 줄에 “YES" 또는 ”NO"를 출력한다.
# ▣ 입력예제 1
# 6
# 1 3 5 6 7 10
# ▣ 출력예제 1
# YES

import sys

a = int(sys.stdin.readline())
set_yn = [0 for i in range(0,a+1)] # 0 0 0 0 0 0 0
lst = list(map(int,sys.stdin.readline().split()))
lst.insert(0,-1)  #
# -1 1 3 5 6 7 10

# 원소의 합이 서로 같은 경우 > 부분 집합

# 부분집합
# func(1)
def func_set(tg):
    if(tg > a):
        sum = 0
        for i in range(1,a+1):
            if(set_yn[i]==1):
                sum = sum + lst[i]
        print(sum)
    else :
        # tg(인덱스) 포함
        print('tg : %d '  %tg)
        set_yn[tg] = 1
        func_set(tg+1)
        # tg(인덱스) 포함 X
        set_yn[tg] = 0
        func_set(tg+1)
func_set(1)