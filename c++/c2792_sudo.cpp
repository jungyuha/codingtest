/*
*) 입력
첫째 줄에 아이들의 수 N과 색상의 수 M이 주어진다. (1 ≤ N ≤ 10^9, 1 ≤ M ≤ 300,000, M ≤ N)
다음 M개 줄에는 구간 [1, 10^9]에 포함되는 양의 정수가 하나씩 주어진다.
K번째 줄에 주어지는 숫자는 K번 색상 보석의 개수이다.
5 2
7
4

7 5
7
1
7
4
4
*) 메모리
int n,m,max,s,e,mid,res;
int mp[300000];
*) 시나리오
max = 나올 수 있는 가장 큰 질투심 계산 : 7 
s =1 ; e = max; 

while s<=e :
    mid = (s+e)/2;
    int m_cnt=0;
    (색상 수 순회)int i=0;i<n;i++
        m_cnt+=(mp[i]/mid);
        if(mp[i]%mid > 0 ) m_cnt++;
    if m_cnt <= n
        res = min(res,mid);
    if m_cnt <= m :
        e = mid-1
    else
        s= mid+1
res 출력
*) 출력

*/