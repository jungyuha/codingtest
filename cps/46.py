# 46. 멀티태스킹(카카오 먹방 문제 변형)
# 현수의 컴퓨터는 멀티태스킹이 가능하다. 처리해야 할 작업이 N개 들어오면 현수의 컴퓨터는
# 작업을 1부터 N까지의 번호를 부여하고 처리를 다음과 같이 한다.
# 1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다.
#     즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.
# 2) 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다.
# 3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
# 그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었다.
#     전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 다시 시작해야 하는지 알아내는 프로그램을 작성하세요.
# ▣ 입력설명
# 첫 번째 줄에 작업의 개수 N(1<=N<=2,000)이 주어지고 그 다음 N줄에 걸쳐 각 작업을 처리하는데 걸리는 시간이 초단위로 주어진다.
#     한 작업을 처리하는데 필요한 시간은 1,000를 넘지 않는다.
# 마지막 줄에 정전이 발생한 시간 K(1<=K<=2,000,000)가 주어진다.
# ▣ 출력설명
# 첫 번째 줄에 몇 번 작업부터 다시 시작해야 하는지 작업 번호를 출력한다.
#     만약 더 이상 처리할 작업이 없다면 -1를 출력한다.
# ▣ 입력예제 1
3
1
2
3
5
# ▣ 출력예제 1
# 3
# <입출력 설명>
# • 0~1초 동안에 1번 작업을 처리한다.남은 시간은 [0, 2, 3] 이다.
# • 1~2초 동안 2번 작업을 처리한다. 남은 시간은 [0, 1, 3] 이다.
# • 2~3초 동안 3번 작업을 처리한다. 남은 시간은 [0, 1, 2] 이다.

import sys

n = int(sys.stdin.readline()) # 작업의 갯수
a = [-1] # 각 작업 일량
tot = 0 # 전체 일량
p = 0 # 현재 위치
cnt = 0 # 경과초
for i in range (1,n+1):
    a.append(int(sys.stdin.readline()))
    tot = tot + a[i]
k = int(sys.stdin.readline()) # 정전이 일어나는 초

if(k >= tot):
    print('-1')
    sys.exit()

while(1):
    p = p+1
    if(p > n) :
        p = 1
    if(a[p] == 0):
        continue
    a[p] = a[p] -1
    cnt = cnt + 1
    if(cnt == k):
        break
while(1):
    p=p+1
    if(p > n):
        p = 1
    if(a[p] != 0):
        break
print(p)



