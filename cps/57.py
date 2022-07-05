# 57. 재귀함수 이진수 출력
# 10진수 N이 입력되면 2진수로 변환하여 출력하는 프로그램을 작성하세요. 단 재귀함수를 이용
# 해서 출력해야 합니다.
# ▣ 입력설명
# 첫 번째 줄에 10진수 N(1<=N<=1,000)이 주어집니다.
# ▣ 출력설명
# 첫 번째 줄에 이진수를 출력하세요.
# ▣ 입력예제 1
# 11
# ▣ 출력예제 1
# 1011

import sys
res=[]
def func(b):
    c = b // 2
    d = b % 2
    if(c > 0):
        func(c)
    res.append(str(d))
    return
a=int(sys.stdin.readline())
func(a)
print(''.join(res))

###### 이해 과정
# func(11)
# 11//2 = 5 , 11%2 = 1
# 5 > 0 이다 -> func(5)

# func(5)
# 5 / 2 = 2 , 5%2 = 1
# 2 > 0 이다 -> func(2)

# func(2)
# 2 / 2 = 1 , 2%2 = 0
# 1 > 0 이다 -> func(1)

# func(1)
# 1 / 2 = 0 , 1%2 = 1
# 0 > 0 이다 -> res.append(1) -> 1
# return

# func(2)
# func(1) 리턴됨
# res.append(0) -> 10
# return

# func(5)
# func(2) 리턴됨
# res.append(1) -> 101
# return

# func(11)
# func(5) 리턴됨
# res.append(1) -> 1011
# return
