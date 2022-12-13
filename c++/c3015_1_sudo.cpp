/*
*) 입력
7
2
4
1
2
2
5
1

7
2
1
4
2
2
5
1

*) 메모리
typedef long long ll;  
ll n, ret, temp;
stack<pair<ll, ll>> s; 

*) 시나리오
(반복 : n) int i=0;i<n;i++
    int temp 입력
    (temp와 연속된 같은 값 갯수) int cnt =1;
    while : s.size() && temp >= s.top().first (새로운 temp값이 최신값보다 크거나 같은 경우)
        res = res + s.top().second;
        if(temp == s.top().first) (새로운 temp값이 최신값과 같은 경우)
            cnt = s.top().second+1; (다음 얘보다 큰 값을 가진 요소가 들어와서 얘를 허물 때 그 앞에 있는 같은 값의 애들은 이미 지워진 상태 & 누적값만 있는 상태이므로)
        else
            cnt = 1;
        s.pop(); (자기보다 작거나 같은 애는 무조건 지우므로 추후에 존재할 수가 없음)
    if(s.size()) :
        temp값이 더 작은 경우 인접 카운팅)res++; 
    s.push(temp) (스택에 새로운 temp값을 넣는다.)

*) 시나리오 요약
    temp가 입력이 되면
(1개의 temp당)
    if : stack에 값이 있으면
        if : 그 이전 입력값이 새로운 입력값보다 작으면 => 다음 애들은 이제 새로운 입력값 이전애들을 못 봄
            while(스택이 빌 때까지 & temp보다 작은 애들이 있는 동안):
                ret += (인접 cnt)
                if temp 앞의 요소보다 작은 애들 :
                    스택에서 지움
                if temp 앞의 요소와 같은 애들 :
                    누적 cnt 계산
                    스택에서 지움
        if : 그 이전 입력값이 새로운 입력값보다 크면
            ret += 1
        스택.push(temp)
    stack에 temp를 넣는다.


*/