# 65. 미로탐색(DFS)
# 7*7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요.
# 출발점은 격자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다.
# 격자판의 1은 벽이고, 0은 통로이다. 격 자판의 움직임은 상하좌우로만 움직인다. 미로가 다음과 같다면 위의 지도에서 출발점에서 도착점까지 갈 수 있는 방법의 수는 8가지이다.
# ▣ 입력설명
# 첫 번째 줄부터 7*7 격자의 정보가 주어집니다.
# ▣ 출력설명
# 첫 번째 줄에 경로의 가지수를 출력한다.
# ▣ 입력예제 1
# 0 0 0 0 0 0 0
# 0 1 1 1 1 1 0
# 0 0 0 1 0 0 0
# 1 1 0 1 0 1 1
# 1 1 0 0 0 0 1
# 1 1 0 1 1 0 0
# 1 0 0 0 0 0 0
# ▣ 출력예제 1
# 8

import sys

lst = []
for i in range(0,7):
    lst.append(list(map(int,sys.stdin.readline().split())))
cnt = 0
def func(y,x):
    global cnt
    if x == -1 or y == -1:
        #print("return -1: (%d ,%d)" %(y , x))
        return
    if x == 7 or y == 7 :
        #print("return 7: (%d ,%d)" % (y, x))
        return
    if lst[y][x] == 1 :
        #print("return 1: (%d ,%d):%d" % (y, x, lst[y][x]))
        return
    if x == 6 and y == 6 :
        #print("yes : (%d ,%d)" % (y, x))
        cnt = cnt + 1
        return
    lst[y][x] = 1
    func(y-1,x)
    func(y+1,x)
    func(y,x-1)
    func(y,x+1)
    lst[y][x] = 0
func(0,0)
print(cnt)
################# 풀이 과정
# 0 0 0 0
# 0 1 0 1
# 0 0 0 0

# (0,0)
    # 상 (-1,0)
        # return
    # 하 (1,0:0)
        # 상 (0,0:1)
            # return
        # 하 (2,0:0)
            # 상(0,1:1)
                # return
            # 하(3,0)
                # return
            # 좌(2,-1)
                # return
            # 우(2,1:0)
                # 상
                # 하
                # 좌
                # 우 ..
        # 좌 (-1,0)
            # return
        # 우 (1.1:1)
            # return
    # 좌 (-1,0)
    # 우 (1,0)
