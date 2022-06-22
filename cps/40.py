# 교집합(투포인터 알고리즘)
# 두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.
# ▣ 입력설명
# 첫 번째 줄에 집합 A의 크기 N(1<=N<=30,000)이 주어집니다.
# 두 번째 줄에 N개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다. 세 번째 줄에 집합 B의 크기 M(1<=M<=30,000)이 주어집니다.
# 네 번째 줄에 M개의 원소가 주어집니다. 원소가 중복되어 주어지지 않습니다. 각 집합의 원소는 int형 변수의 크기를 넘지 않습니다.
# ▣ 출력설명
# 두 집합의 교집합을 오름차순 정렬하여 출력합니다.
# ▣ 입력예제 1
# 5
# 2 7 10 5 3
# 5
# 3 10 5 17 12
# ▣ 출력예제 1
# 3 5 10
import sys
num_a = int(sys.stdin.readline())
#print(num_a)
p_a = 0
list_a = []
graph = []
graph=list(map(int, sys.stdin.readline().split()))
list_a = list(map(int, sys.stdin.readline().split()))
list_a.sort()
#print(list_a)

num_b = int(sys.stdin.readline().rstrip())
#print(num_b)
p_b = 0
list_b = list(map(int,sys.stdin.readline().split()))
list_b.sort()
#print(list_b)

result_list = []

while p_a < num_a and p_b < num_b:
    if list_a[p_a]<list_b[p_b] :
        p_a = p_a + 1
    elif list_a[p_a]>list_b[p_b] :
        p_b = p_b + 1
    elif list_a[p_a] == list_b[p_b] :
        result_list.append(list_a[p_a])
        p_b = p_b + 1

print(result_list)
