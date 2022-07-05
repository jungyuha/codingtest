# 56. 재귀함수 분석
# 자연수 N이 주어지면 아래와 같이 출력하는 프로그램을 작성하세요. 재귀함수를 이용해서 출력해야 합니다.
# ▣ 입력설명
# 첫 번째 줄에 자연수 N(1<=N<=20)이 주어집니다.
# ▣ 출력설명
# 첫 번째 줄에 재귀함수를 이용해서 출력하세요.
# ▣ 입력예제 1
# 3
# ▣ 출력예제 1
# 1 2 3

# func(3)
# input : 3 > 1이 아님 > func(2)

# func(2)
# input : 2 > 1이 아님 > func(1)

# func(1)
# input :1 > 1 맞음 > print(1) > return

# func(2)
# func(1) 끝남 > print(2) > return

# func(3)
# func(2) 끝남 > print(3) > return

import sys

res = []

def func(b):
    if (b > 1):
        func(b - 1)
    res.append(str(b))

a = int(sys.stdin.readline())
func(a)
print(' '.join(res))
