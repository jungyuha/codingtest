# 49. 블록의 최댓값
# 현수는 블록놀이를 좋아합니다.
# 현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고 최대 블록개수를 사용하여 정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
# 현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.
# ▣ 입력설명
# 첫 줄에 블록의 크기 N(3<=N<=10)이 주어집니다. 블록이 크기는 정사각형 N*N입니다. 두 번째 줄에 N개의 정면에서의 높이 정보가 왼쪽 정보부터 주어집니다.
# 세 번째 줄에 N개의 오른쪽 측면 높이 정보가 앞쪽부터 주어집니다.
# 블록의 높이는 10 미만입니다.
# ▣ 출력설명
# 첫 줄에 블록의 최대 개수를 출력합니다.
# ▣ 입력예제 1
# 4
# 2 0 3 1
# 1 1 2 3
# ▣ 출력예제 1
# 17

import sys

n = int(sys.stdin.readline())
a=[]
b=[] # 측면
res = 0
a.append(list(map(int,sys.stdin.readline().split())))
for i in range(1,n):
    a.append(a[0].copy())
#print(a)
b = list(map(int,sys.stdin.readline().split()))
#print(b)
for i in range(0,n):
    for j in range(0,n):
        #print("i , j : %d , %d " % (i, j))
        #print("a[i][j] , b[i] : %d , %d " % (a[i][j], b[i]))
        if(a[i][j] > b[i]):
            a[i][j] = b[i]
        #print(a)
for i in range(0,n):
    for j in range(0,n):
        res = res + a[i][j]
print(res)