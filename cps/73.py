# 73. 최대힙(priority_queue : 우선순위 큐)
# 최대힙은 완전이진트리로 구현된 자료구조입니다.그 구성은 부모 노드값이 왼쪽자식과 오른 쪽 자식노드의 값보다 크게 트리를 구성하는 것입니다.
# 그렇게 하면 트리의 루트(root)노드는 입력된 값들 중 가장 큰 값이 저장되어 있습니다.예를 들어 5 3 2 1 4 6 7순으로 입력되면 최대힙 트리는 아래와 같이 구성됩니다.
# 최대힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
# 1) 자연수가 입력되면 최대힙에 입력한다.
# 2) 숫자 0 이 입력되면 최대힙에서 최댓값을 꺼내어 출력한다.
# (출력할 자료가 없으면 -1를 출력한다.)
# 3) -1이 입력되면 프로그램 종료한다.
# ▣ 입력설명
# 첫 번째 줄부터 숫자가 입력된다. 입력되는 숫자는 100,000개 이하이며 각 숫자의 크기는 정수형 범위에 있다.
# ▣ 출력설명
# 2) 연산을 한 결과를 보여준다.
# ▣ 입력예제 1
# 5
# 3
# 6
# 0
# 5
# 0
# 2
# 4
# 0
# -1
# ▣ 출력예제 1
# 6
# 5
# 5
import sys

qList = [0]
p = 0
while 1:
    print(qList)
    a = int(sys.stdin.readline())
    if a == -1:
        break
    if a > 0:
        p = p + 1
        child = p
        qList.append(a)
        #print("p", p)
        #print("0",qList)
        while 1:
            parent = child // 2
            if parent > 0 and qList[parent] < qList[child] :
                qList[child] , qList[parent] = qList[parent] ,  qList[child]
                child = parent
                #print("1 :",qList)
            else:
                break
    elif a == 0 :
        if len(qList) == 1 :
            print("-1")
            break
        qList[p], qList[1] = qList[1], qList[p]
        cur = 1
        #print("2 :", qList)
        i = 0
        child = 1
        while 1:
            child = 2 * cur
            #print("child :", child)
            if child + 1 < len(qList) :
                #print("qList:", qList)
                #print("cur :", cur)
                if qList[child] < qList[child+1]:
                    child = child + 1
                if qList[child] < qList[cur]:
                    qList[child] , qList[cur] = qList[cur] , qList[child]
                    cur = child
                else :
                    break
            elif child + 1 == len(qList) and qList[child] < qList[cur]:
                qList[child] , qList[cur] = qList[cur] , qList[child]
                break
            else :
                break
        print(qList.pop(p))
        p = p -1


# ############debug
# #   5
# # 3   6
# qList = [0]
# p = 0
# #### round 1 (5)
# p = 1
# qList.append(5)  # qList = [0 5]
# parent = p // 2  # 0
#
# #### round 2 (3)
# p = 2
# parent = p // 2  # 1
# qList.append(3)  # qList = [0 5 3]
# qList[parent]  # qList[1] = 5
# x = qList[p]  # qList[1] = 5
#
# #### round 3 (6)
# p = 3
# qList.append(6)  # qList = [0 5 3 6]
# parent = p // 2  # 1
# qList[parent]  # qList[1] = 5
# x = qList[p]  # qList[3] = 6
# # qList[parent] < qList[p]:
# # qList[parent] = qList[p] 바꿔치기
# # qList[p] = qList[parent] # [0 6 3 5 ]
# parent = parent // 2
# #   6
# # 3   5
#
# #### round 4 (0)
# p = 3
# # qList = [0 6 3 5]
# parent = 1
# qList[parent]  # qList[1] = 6
# # qList[parent] = qList[p] 바꿔치기
# # qList[p] = qList[parent] # [0 5 3 6 ]
# qList.pop(p)
# p = p - 1
# child = 2 * parent
# while 1:
#     child = 2 * parent
#     if child + 1 <= len(qList) and qList[child] > qList[child + 1]:
#         child = child + 1
#     if child == len(qList) or qList[child] < qList[parent]:
#         break
#     qList[child], qList[parent] = qList[parent], qList[child]
#     parent = child
#
# # [0 3 5]
#
# #### round 5 (5)
# p = 5
# qList.append(0)  # qList = [0 6 3 5 0 5]
# ## round 1
# parent = p // 2  # 2
# qList[parent]  # qList[2] = 3
# x = qList[p]  # qList[5] = 5
# # qList[parent] < qList[p]:
# # qList[parent] = qList[p] 바꿔치기
# # qList[p] = qList[parent] # [0 6 5 5 0 3]
# ## round 2
# parent = parent // 2  # 1
# qList[parent]  # qList[1] = 6
# #       6
# #     5   5
# #   0   3
