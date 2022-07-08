# 64. 경로 탐색(DFS)
# 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 모든 경로의 가지 수를 출력하는 프로그램을 작성하세요.
# 아래 그래프에서 1번 정점에서 5번 정점으로 가는 가지 수는
# 1 2 3 4 5
# 1 2 5
# 1 3 4 2 5
# 1 3 4 5
# 1 4 2 5
# 1 4 5
# 총 6 가지입니다.
# ▣ 입력설명
# 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연결정보가 주어진다.
# ▣ 출력설명
# 총 가지수를 출력한다.
# ▣ 입력예제 1
# 5 9
# 1 2
# 1 3
# 1 4
# 2 1
# 2 3
# 2 5
# 3 4
# 4 2
# 4 5
# ▣ 출력예제 1
# 6
import sys

a,b = map(int,sys.stdin.readline().split())
lst=[[0]*(a+1) for i in range(0,a+1)]
pos =[0]*(a+1)

for i in range(0,b):
    y , x = map(int, sys.stdin.readline().split())
    lst[y][x] = 1

route=[]
cnt = 0

def func(k):
    global cnt
    if(pos[k]==1):
        return
    route.append(k)
    if (k == a):
        print(route)
        route.pop()
        cnt = cnt + 1
        return
    pos[k]=1
    for i in range(1,len(lst[k])):
        if(lst[k][i]==1):
            func(i)
    pos[k]=0
    route.pop()
func(1)
print(cnt)

#########디버깅
# 1
    # 2
        # 1 X
        # 3
            # 4
                # 2  X
                # 5 O
        # 5 O
    # 3
        # 4
            # 2
                # 5
            # 5
    # 4
        # 2
            # 1 x
            # 3
                # 4 x
            # 5
        # 5
