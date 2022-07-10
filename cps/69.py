# 69. 이진트리 넓이우선탐색(BFS)
# 아래 그림과 같은 이진트리를 넓이우선탐색해 보세요. 간선 정보 6개를 입력받아 처리해보세요.
# 넓이 우선 탐색 : 1 2 3 4 5 6 7
# ▣ 입력예제 1
# 1 2
# 1 3
# 2 4
# 2 5
# 3 6
# 3 7
# ▣ 출력예제 1
# 1 2 3 4 5 6 7

import sys

lst = [[0]*10 for i in range(0,10)]
pos = [0]*10
qList = []
for i in range(0,6):
    a,b = map(int,sys.stdin.readline().split())
    lst[a][b] = 1
#print(lst)

head = -1
p = 0
pos[1] = 1
qList.append(1)
for i in range(1,7):
    for j in range(1, 7):
        if lst[i][j] == 1 :
            if(pos[j] != 1):
                qList.append(j)
                #print(qList)
print(qList)