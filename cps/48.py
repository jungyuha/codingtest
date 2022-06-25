# 48. 각 행의 평균과 가장 가까운 값
# <그림 1>과 같이 9×9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고, 그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요.
# 평균은 소수점 첫째 자리에서 반 올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.
# ▣ 입력설명
# 첫 째 줄부터 아홉 번째 줄까지 한 줄에 아홉 개씩 자연수가 주어진다. 주어지는 자연수는 100보다 작다.
# ▣ 출력설명
# 첫째 줄에 첫 번째 줄부터 각 줄에 각행의 평균과 그 행에서 평균과 가장 가까운 수를 출력한다.
# ▣ 입력예제
# 3 23 85 34 17 74 25 52 65
# 10 7 39 42 88 52 14 72 63
# 87 42 18 78 53 45 18 84 53
# 34 28 64 85 12 16 75 36 55
# 21 77 45 35 28 75 90 76 1
# 25 87 65 15 28 11 37 28 74
# 65 27 75 41 7 89 78 64 39
# 47 47 70 45 23 65 3 41 44
# 87 13 82 38 50 12 48 29 80
# ▣ 출력예제
# 42 34
# 43 42
# 53 53
# 45 36
# 50 45
# 41 37
# 54 64
# 43 44
# 49 50

import sys

a=[]
res_list=[]

for i in range(0, 9):
    sum = 0
    a.append(list(map(int,sys.stdin.readline().split())))   # a : 입력받을 2차원 배열
    #print(a[i])
    for el in a[i]: # 한줄씩 입력받아 sum , avg 계산
        sum = sum + el
    avg = int((sum / 9.0)+0.5)
    #print("sum : %d ,avg : %d" % (sum, avg))
    min = 9999
    res = 0
    for el in a[i]: # 입력받은 한줄씩 min 계산
        if min > abs(el - avg):
            min = abs(el - avg)
            res = el
        elif(min > abs(el-avg)):
            if(el > res):
                res = el
    #print("sum : %d ,avg : %d , res : %d " % (sum, avg, res))
    res_list.append([avg,res])
for el in res_list:
    print("%d %d" %(el[0], el[1]))


