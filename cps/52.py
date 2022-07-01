# 52. Ugly Numbers
# 어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다.
# Ugly Number를 차례대로 적어보면
# 1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다. 숫자 1은 Ugly Number의 첫 번째 수로 합니다.
# 자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.
# ▣ 입력설명
# 첫 줄에 자연수 N(3<=N<=1500)이 주어집니다.
# ▣ 출력설명 첫 줄에 N번째 Ugly Number를 출력하세요.
# ▣ 입력예제 1
# 10
# ▣ 출력예제 1
# 12
# ▣ 입력예제 2
# 1500
# ▣ 출력예제 2
# 859963392
# 예제 => p2,p3,p5=1,1,1 => a[p2],a[p3],a[p5]

import sys

n = int(sys.stdin.readline())
# n : 10
a = [1,1] # Ugly Number 히스토리 배열 (인덱스는 1부터 세도록 한다.)
min =0
p2 , p3 , p5 = 1 , 1 , 1 # 현재 위치 (계산전)
for i in range(1,n+1):
    if(a[p2]*2 <a[p3]*3):
        min = a[p2]*2
    else :
        min = a[p3]*3
    if(min > a[p5]*5):
        min = a[p5]*5
    if (min == a[p2]*2):
        p2 = p2 +1
    if (min == a[p3]*3):
        p3 = p3 +1
    if (min == a[p5]*5):
        p5 = p5 +1
    a.append(min)
print(a[n])
# 반복문 과정
# if (a[p2] * 2 < a[p3] * 3):  # 1*2 1*3 1*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,(2)
#
# if (a[p2] * 2 < a[p3] * 3):  # (2)*2 (1)*3 (1)*5 비교
#     min = a[p2] * 2  # 4 > 3
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5): # 3 < 5
#     min = a[p5] * 5
# a.append(min) # 1 , 2 ,(3)
#
# if (a[p2] * 2 < a[p3] * 3):  # (2)*2 (2)*3 (1)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,(4)
#
# if (a[p2] * 2 < a[p3] * 3):  # (3)*2 (2)*3 (1)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,(5)
#
# if (a[p2] * 2 < a[p3] * 3):  # (3)*2 (2)*3 (2)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,5,6
#
# if (a[p2] * 2 < a[p3] * 3):  # (4)*2 (3)*3 (2)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,5,6,8
#
# if (a[p2] * 2 < a[p3] * 3):  # (5)*2 (3)*3 (2)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,5,6,8,9
#
# if (a[p2] * 2 < a[p3] * 3):  # (5)*2 (4)*3 (2)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,5,6,8,9,10
#
# if (a[p2] * 2 < a[p3] * 3):  # (6)*2 (4)*3 (3)*5 비교
#     min = a[p2] * 2
# else:
#     min = a[p3] * 3
# if (min > a[p5] * 5):
#     min = a[p5] * 5
# a.append(min)  # 1,2,3,4,5,6,8,9,10