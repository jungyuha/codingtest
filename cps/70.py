# 70. 그래프 최단거리(BFS)
# 다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.
# ▣ 입력설명
# 첫째 줄에는 정점의 수 N(1<=N<=20)와 간선의 수 M가 주어진다. 그 다음부터 M줄에 걸쳐 연 결정보가 주어진다.
# ▣ 출력설명
# 1번 정점에서 각 정점으로 가는 최소 간선수를 2번 정점부터 차례대로 출력하세요.
# ▣ 입력예제 1
# 6 9
# 1 3
# 1 4
# 2 1
# 2 5
# 3 4
# 4 5
# 4 6
# 6 2
# 6 5
# ▣ 출력예제 1
# 2 : 3
# 3 : 1
# 4 : 1
# 5 : 2
# 6 : 2

import sys

a, b = map(int,sys.stdin.readline().split())
lst2 = [[0]*(a+1) for i in range(0,a+1)]
pos = [0]*(a+1)
qList = []
dis = [0]*(a+1)
head= 0
cur = 0

for i in range(0,b):
    s, e = map(int,sys.stdin.readline().split())
    lst2[s][e]=1
#print(lst2)
qList.append(1)
pos[1]=1
head_v = 0
head = -1
cur = 0

while 1:
    head = head + 1
    if cur < head :
        break
    head_v = qList[head]
    for i in range(1, len(lst2[head_v])):
        if lst2[head_v][i] == 1 and pos[i] != 1:
            qList.append(i)
            pos[i] = 1
            cur = cur + 1
            # 최단 거리 기록
            dis[i] = dis[head_v] + 1
#print(qList)
for i in range(2,len(dis)):
    print(i," : ",dis[i])

######### 풀이 과정1
# 1 3 4 5 6 2
# 1
    # 3
    # 4
        # 5
        # 6
            # 2
########## 풀이 과정 2
# qList.append(1)
# pos[1]=1
# dis[1]=0
#

# head_v = 1
# head_v = qList[head]
# for i in range(1,len(lst2[head_v])):
#     if lst2[head_v][i] == 1 and pos[i] != 1:
#         qList.append(i)
#         pos[i] = 1
#         cur = cur + 1
# # qList = [1,3,4] cur = 2 head = 0
#
# head = head + 1
# head_v = qList[head]
# # qList = [1,3,4] cur = 2 head = 1 head_v = 3
# for i in range(1,len(lst2[head_v])):
#     if lst2[head_v][i] == 1 and pos[i] != 1 :
#         qList.append(i)
#         pos[i] = 1
#         cur = cur + 1
# # qList = [1,3,4] cur = 2 head = 1 head_v = 3
#
# head = head + 1
# head_v = qList[head]
# # qList = [1,3,4] cur = 2 head = 2 head_v = 4
# for i in range(1,len(lst2[head_v])):
#     if lst2[head_v][i] == 1 and pos[i] != 1 :
#         qList.append(i)
#         pos[i] = 1
#         cur = cur + 1
# # qList = [1,3,4,5,6] cur = 4 head = 2 head_v = 4
#
# head = head + 1
# head_v = qList[head]
# # qList = [1,3,4,5,6] cur = 4 head = 3 head_v = 5
#
# head = head + 1
# head_v = qList[head]
# # qList = [1,3,4,5,6] cur = 4 head = 4 head_v = 6
# for i in range(1,len(lst2[head_v])):
#     if lst2[head_v][i] == 1 and pos[i] != 1 :
#         qList.append(i)
#         pos[i] = 1
#         cur = cur + 1
# # qList = [1,3,4,5,6,2] cur = 5, head = 4 head_v = 6
#
# head = head + 1
# head_v = qList[head]
# # qList = [1,3,4,5,6,2] cur = 5 head = 5 head_v = 6
# for i in range(1,len(lst2[head_v])):
#     if lst2[head_v][i] == 1 and pos[i] != 1 :
#         qList.append(i)
#         pos[i] = 1
#         cur = cur + 1
#
# head = head + 1
# if(cur < head) # return
# qList = [1,3,4,5,6,2] cur = 5 head = 6 head_v = 6

##### bfs 순회
# while 1:
#     head = head + 1
#     if cur < head :
#         break
#     head_v = qList[head]
#     for i in range(1, len(lst2[head_v])):
#         if lst2[head_v][i] == 1 and pos[i] != 1:
#             qList.append(i)
#             pos[i] = 1
#             cur = cur + 1
# print(qList)

