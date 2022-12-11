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
        if(temp == s.top().first)
            cnt = s.top().second+1;
        else
            cnt = 1;
        
    (인접 카운팅)res++; 
    s.push(temp)

    (반복(1개의 temp당) : stack이 빌 때까지 AND 제일 최근에 들어온 애가 temp보다 크면 안된다.)
        (제일 최근 들어온 애의 cnt를 결과값에 더한다.) ret += s.top().second; 
        if (제일 최근 들어온 애와 temp값이 같다면) s.top().first == temp
            (temp의 cnt를 1개 더 카운트한다.) cnt = s.top().second + 1;
        else : cnt =1;
        (최근에 들어온 애를 삭제한다.)
    (최근애 들어온 애가 temp보다 큰 경우 인접 부분만 카운트함)
    (stack에 temp를 넣는다.) s.push({temp, cnt});

*) 시나리오 요약
    temp가 입력이 되면
(1개의 temp당)
    if : stack에 이전 입력값이 있으면
        if : 그 이전 입력값이 새로운 입력값보다 작으면 => 다음 애들은 이제 새로운 입력값 이전애들을 못 봄
            ret += (이전 입력값이 볼 수 있었던 애들)
            인접이라 마주볼 수 있음 : ret ++;
        if : 그 이전 입력값이 새로운 입력값보다 크면
            인접이라 마주볼 수 있음 
        if : 그 이전 입력값이 새로운 입력값보다 같으면 
            인접이라 마주볼 수 있음
    stack에 temp를 넣는다.


*/