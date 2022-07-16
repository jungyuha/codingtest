# 74. 최소힙(priority_queue : 우선순위 큐)
# 최소힙은 완전이진트리로 구현된 자료구조입니다.
# 그 구성은 부모 노드값이 왼쪽자식과 오른 쪽 자식노드의 값보다 작게 트리를 구성하는 것입니다.
# 그렇게 하면 트리의 루트(root)노드는 입력된 값들 중 가장 작은 값이 저장되어 있습니다.
# 예를 들어 5 3 2 1 4 6 7순으로 입력되면 최소힙 트리는 아래와 같이 구성됩니다.
# 최소힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
# 1) 자연수가 입력되면 최소힙에 입력한다.
# 2) 숫자 0 이 입력되면 최소힙에서 최솟값을 꺼내어 출력한다.
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
# 3
# 5
# 2
import sys
aList = [0]
p = 0
while 1:
    #print(aList)
    a = int(sys.stdin.readline())
    if a == -1 :
        break
    elif a > 0 :
        aList.append(a)
        p = p + 1
        child = p
        while 1 :
            parent = child // 2
            if parent > 0 and aList[child] < aList[parent]:
                    aList[child] , aList[parent] = aList[parent] , aList[child]
            else :
                break
    elif a == 0 :
        if len(aList) == 1:
            print("-1")
            break
        aList[p], aList[1] = aList[1], aList[p]
        print(aList.pop(p))
        p = p - 1
        parent = 1
        while 1 :
            #print(aList)
            child = 2 * parent
            if child + 1 < len(aList) :
                if aList[child] > aList[child+1] :
                    child = child + 1
                if aList[parent] > aList[child] :
                    #print('a')
                    #print(aList[parent], aList[child])
                    aList[parent] , aList[child] = aList[child] , aList[parent]
                    parent = child
                    #print(aList)
                else :
                    break
            elif child + 1 == len(aList) and aList[parent] > aList[child] :
                aList[parent] , aList[child] = aList[child] , aList[parent]
                #print('b')
                #print(aList[parent], aList[child])
                #print(aList)
                break
            else :
                break

########## 디버깅
# 5 3 2 1 4 6
# 0 5 3 2 1 4 6

# <r1>
# p = 1 , parent = p // 2 = 0
# 0 5
#

# <r2>
# p = 2 , parent = p // 2 = 1
# 0 5 3
# child val = q[2] = 3 , parent val = q[1] = 5
# child < parent : swap [0 3 5]
# parent = parent // 2 = 0

# <r2>
# p = 3 , parent = 3 // 2 = 1
# 0 3 5 2
# child val = q[3] = 2 , parent val = q[1] = 3
# child < parent : swap [0 2 5 3]
# parent = parent // 2 = 0

# <r3> 1
# p = 4 ,parent = p // 2 = 2
# 0 2 5 3 1
# child val = q[4] = 1 , parent val = q[2] = 5
# child < parent : swap [0 2 1 3 5]
# child = parent = 2
# <r3> 2
# parent = parent // 2 = 1
# child val = q[2] = 1 , parent val = q[1] = 2
# child < parent : swap [0 1 2 3 5]
# child = parent = 1
# <r3> 3
# parent = parent // 2 = 0

# <r4> : 0(pop)
# if len(list) == 0 : break
# [0 1 2 3 5]
# p = 4 # parent = 1
# q[p] <-> q[1] : swap [0 5 2 3 1]
# while
    # child= 2*parent = 2
    # if len(list) > child + 1 => child = 더 작은 애
    #   if list[child] > list[parent] : swap , parent = child
    #   else : break
    # elif len(list) = child and list[child] < list[parent] 이면 swap
    # else : break
