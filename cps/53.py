# 53. K진수 출력
# 10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사용하시기 바랍니다.
# ▣ 입력설명
# 첫 번째 줄에 10진수 N(10<=N<=1,000)과 K(2, 5, 8, 16)가 주어진다.
# ▣ 출력설명 K진수를 출력한다.
# ▣ 입력예제 1
# 11 2
# ▣ 출력예제 1
# 1011
# ▣ 입력예제 2
# 31 16
# ▣ 출력예제 2
# 1F

# [이해 과정 디버깅]
# 11/2 = 5
# 11 % 2 = 1
#
# 5 / 2 = 2
# 5 % 2 = 1
#
# 2 / 2 = 1
# 2 % 2 = 0
#
# 1 / 2 = 0
# 1 % 2 = 1

import sys

num, k = map(int,sys.stdin.readline().split())
stack = []
nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'D', 'F']
a = num
b = 1
res = []
while 1:
    if a == 0:
        break
    b = a % k
    a = a // k
    stack.append(nums[b])
for i in reversed(stack):
    res.append(i)
print(''.join(res))

