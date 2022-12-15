/*
*) 입력
8
20.000
70.000
50.000
30.000
70.000
30.000
60.000
70.000

*) 메모리
priority_queue<double> pq; // 우선순위 큐
int top;
double a;
*) 시나리오
cin >> n;

(7번 입력받는다 : 반복) i=0;i<7;i++
    cin >> a;
    pq.push(a);
while(n-7): // n-7번 입력 받는다.
    cin >> a;
    if a <= pq.top() : pq의 최대값보다 작은 애가 오면 최대값을 밀어내고 작은 애가 들어간다.
        pq.pop();
        pq.push(a);

*) 출력
(1) pq
    cout <<"\n";    
    while(!pq.empty()){
        cout << pq.top() <<",";
        pq.pop();
    }
    cout <<"\n";
*/