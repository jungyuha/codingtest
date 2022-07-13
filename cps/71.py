# 71. 송아지 찾기(BFS : 상태트리탐색)
# 현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다.
# 현수의 위치와 송아 지의 위치가 직선상의 좌표 점으로 주어지면 현수는 현재 위치에서 송아지의 위치까지
# 다음과 같은 방법으로 이동한다.현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다.
# 최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성 하세요.
# ▣ 입력설명
# 첫 번째 줄에 현수의 위치 S와 송아지의 위치 E가 주어진다. 직선의 좌표 점은 1부터 10,000 까지이다.
# ▣ 출력설명
# 점프의 최소횟수를 구한다.
# ▣ 입력예제 1
# 5 14
# ▣ 출력예제 1
# 3

import sys

a , b = map(int,sys.stdin.readline().split())
qList = []
lst = [-1,1,5]
dis = [0 for i in range(0,10001)]
qList.append(a)
dis[a] = 1
head = -1

while 1:
    head = head + 1
    child = 0
    res = 0
    head_v = qList[head]
    #print("head_v : ",head_v)
    for i in lst :
        child = head_v + i
        #print("child : ", child)
        #print("dis[child] : ", dis[child])
        if dis[child] == 0 :
            dis[child] = dis[head_v]+1
            if child == b:
                #print("child == b : ", child)
                res = dis[child]
                break
            qList.append(child)
            #print("qList : ", qList)
    if res > 0 :
        print("answer : ",res)
        break
#####디버깅
# #### 1 Round
# # qList = [5]
# dis[5]=1
# head = 0
# child = 0
# res = 0
# head_v = qList[0] = qList[head] = 5
# for i in lst :
#     child = head_v + i
#     if dis[child] == 0 :
#         dis[child] = dis[head_v] + 1 # 2
#         if child == b :
#             res = dis[head]+1
#             break
#         qList.append(child)
# if res > 0 :
#     test = 1
# # 5의 child :: 4 , 6 , 8  > dis 모두 0
# # qList = [5 4 6 8] , dis [5 4 6 8] => 1 2 2 2
# #### 2 Round
# # qList = [5 4 6 8]
# # dis[4] = 1
# head = head + 1 # head = 1
# child = 0
# res = 0
# head_v = qList[1] = qList[head] = 4
# for i in lst:
#     child = head_v + i # 4의 child :: 3 , 5 , 9  > dis [5] =1
#     if dis[child] == 0:
#         dis[child] = dis[head_v] + 1
#         if child == b:
#             res = dis[head] + 1
#             break
#         qList.append(child) # qList = [5 4 6 8 3 9] , dis [5 4 6 8 3 9] => 1 2 2 2 3 3
# if res > 0:
#     test = 1
#     # break
# #### 3 Round
# # qList = [5 4 6 8 3 9]
# # dis[6] = 1
# head = head + 1 # head = 2
# child = 0
# res = 0
# head_v = qList[2] = qList[head] = 6
# for i in lst:
#     child = head_v + i # 4의 child :: 5 , 7 , 11  > dis [5] =1
#     if dis[child] == 0:
#         dis[child] = dis[head_v] + 1
#         if child == b:
#             res = dis[head] + 1
#             break
#         qList.append(child) # qList = [5 4 6 8 3 9 7 11] , dis [5 4 6 8 3 9 7 11] => 1 2 2 2 3 3 3 3
# if res > 0:
#     test = 1
#     # break
# #### 4 Round
# # qList = [5 4 6 8 3 9 7 11]
# # dis[8] = 1
# head = head + 1 # head = 3
# child = 0
# res = 0
# head_v = qList[2] = qList[head] = 8
# for i in lst:
#     child = head_v + i # 8의 child :: 7 , 9 , 13  > dis [7 9] =1
#     if dis[child] == 0:
#         dis[child] = dis[head_v] + 1
#         if child == b:
#             res = dis[head] + 1
#             break
#         qList.append(child) # qList = [5 4 6 8 3 9 7 11 13] , dis [5 4 6 8 3 9 7 13] => 1 2 2 2 3 3 3 3 3
# if res > 0:
#     test = 1
#     # break
# #### 4 Round
# # qList = [5 4 6 8 3 9 7 11 13]
# # dis[8] = 1
# head = head + 1 # head = 4
# child = 0
# res = 0
# head_v = qList[3] = qList[head] = 3
# for i in lst:
#     child = head_v + i # 3의 child :: 2 , 4 , 8  > dis [4 8] =1
#     if dis[child] == 0:
#         dis[child] = dis[head_v] + 1
#         if child == b:
#             res = dis[head] + 1
#             break
#         qList.append(child) # qList = [5 4 6 8 3 9 7 11 13 2] , dis [5 4 6 8 3 9 7 13 2] => 1 2 2 2 3 3 3 3 3 4
# if res > 0:
#     test = 1
#     # break
# #### 5 Round
# # qList = [5 4 6 8 3 9 7 11 13 2]
# head = head + 1 # head = 5
# child = 0
# res = 0
# head_v = qList[3] = qList[head] = 9
# for i in lst:
#     child = head_v + i # 3의 child :: 8 , 10 , 14  > dis [ 8 ] =1
#     if dis[child] == 0:
#         dis[child] = dis[head_v] + 1
#         if child == b: # 14
#             res = dis[child]
#             break
#         qList.append(child) # qList = [5 4 6 8 3 9 7 11 13 2 10 14] , dis [5 4 6 8 3 9 7 13 2 10 14] => 1 2 2 2 3 3 3 3 3 4 4 4
# if res > 0:
#     test = 1
#     # break