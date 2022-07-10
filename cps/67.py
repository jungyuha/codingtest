# 67. 최소비용(DFS : 인접행렬)
# 가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그램을 작성하세요.
# ▣ 입력설명
# 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다.그 다음부터 M줄에 걸쳐 연결정보가 주어진다.
# ▣ 출력설명 최소비용을 출력합니다.
# ▣ 입력예제 1
# 5 8
# 1 2 12
# 1 3 6
# 1 4 10
# 2 3 2
# 2 5 2
# 3 4 3
# 4 2 2
# 4 5 5
# ▣ 출력예제 1
# 13

import sys

a,b = map(int,sys.stdin.readline().split())
lst=[[0]*(a+1) for i in range(0,a+1)]
pos=[0]*(a+1)

for i in range(0,b):
    y , x , val= map(int, sys.stdin.readline().split())
    lst[y][x] = val

route=[]
cnt = 0
min = 999999

def func(p,sum):
    global a , cnt , min
    #print("p : %d , sum : %d " %(p,sum))
    #print("lst[p] L ",lst[p])
    if p == a :
        if min > sum :
            #print("cnt > sum :: ",sum)
            min = sum
        return
    for i in range(1,len(lst[p])):
        if pos[i] != 1 and lst[p][i]>0 :
            pos[p] = 1
            func(i, sum+lst[p][i])
            pos[p] = 0
func(1,0)
print(min)

