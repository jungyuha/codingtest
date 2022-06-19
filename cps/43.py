# 43. 뮤직비디오(이분검색 응용)
# 지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다.
# DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지 되어야 한다.
# 순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다.
# 즉, 1번 노래와 5번 노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야 한다.
# 지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는 DVD를 가급적 줄이려고 한다.
# 고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기로 하였다.
# 이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다.
# 그리고 M개의 DVD는 모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.
# ▣ 입력설명
# 첫째 줄에 자연수 N(1≤N≤1,000), M(1≤M≤N)이 주어진다.
# 다음 줄에는 조영필이 라이브에서 부른 순서대로 부른 곡의 길이가 분 단위로(자연수) 주어진다.
# 부른 곡의 길이는 10,000분을 넘지 않는다고 가정하자.
# ▣ 출력설명
# 첫 번째 줄부터 DVD의 최소 용량 크기를 출력하세요.
# 설명 : 3개의 DVD용량이 17분짜리이면 (1, 2, 3, 4, 5) (6, 7), (8, 9) 이렇게 3개의 DVD로 녹음을 할 수 있다.
# 17분 용량보다 작은 용량으로는 3개의 DVD에 모든 영상을 녹화할 수 없다.
# ▣ 입력예제 1
# 9 3
# 1 2 3 4 5 6 7 8 9
# ▣ 출력예제 1
# 17
#    print("lt,rt : %d , %d" % (lt , rt))

import sys

n , m = map(int,sys.stdin.readline().split())
#print("n ,m : %d , %d" %(n,m))
a = list(map(int,sys.stdin.readline().split()))
#print(a)

def Count(s) :
    sum = 0
    cnt = 1

    #print("mid(중간값) : %d" % s)
    for i in range (0,n) :
        #print("i : %d" %i)
        if (sum+a[i]>s):
            #print("%d + %d > %d" % (sum, a[i],s))
            cnt = cnt + 1
            #print("cnt : %d " % cnt)
            sum = a[i]
            #print("sum : %d " % sum)
        else :
            sum = sum + a[i]
            #print("else sum : %d " % sum)
            #print("else cnt : %d " % cnt)
    return cnt

lt = 1
rt = 0
max = -9999
mid = 0
res = 0

for el in a :
    rt = rt + el
    if max < el :
        max = el
#print ("rt(전체합) : %d " %rt)
#print ("max(최대 요소값) : %d "  %max)

while lt <= rt :
    mid = int((lt+rt)/2)
    #print("mid(중간값) : %d " % mid)
    if(mid >= max and Count(mid) <= m) :
        #print ("%d >=  %d" %(mid,max))
        res = mid
        rt = mid -1
        #print ("res , mid , rt : %d %d %d" %(res,mid,rt))
    else :
        lt = mid + 1
        #print("lt: %d" % lt)
print("res : %d " % res)




