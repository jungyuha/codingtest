/*
*) 입력
4
1 3
2 5
3 5
6 7

*) 메모리
vector<pair<int,int>> lst;
vector<pair<int,int>> lineLst;
int a,res;

*) 시나리오1
(a번 입력 받음) i=0;i<a;i++
    cin >> p1 >> p2 ;
    lst.push({p1,p2});
    (line : lineLst 순회)
        int p3 = line.first; line의 시작점
        int p4 = line.second; line의 끝점
        if (p3 <= p1 && p1 <= p4) || (p3 <= p2 && p2 <= p4): 만약 새로운 점의 시작점이 해당 라인 안에 있다면 또는 만약 새로운 점의 끝점이 해당 라인 안에 있다면
            p1,p2,p3,p4 정렬
            p1 = 제일 작은 수;
            p2 = 제일 큰 수;
        line.first =  p1;
        line.seond = p2;
(line : lineLst 순회)
    res +=(line.second -line.first +1);

*) 시나리오2
int a;
vector<pair<int,int>> lst; 
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq; // 우선순위큐 (시작점이 작은 순으로)
(a번 입력 받음) i=0;i<a;i++
    cin >> p1 >> p2 ;
    pq.push({p1,p2});
    (pq 순회)
        if 시작점이 이전의 끝 점보다 작을 때
            if 끝점이 이전의 끝 점보다 클 때
                이전이 끝 점 = 현재 끝 점
        else 시작점이 이전의 끝 점보다 클 때
            lst에 새로운 선을 추가한다.
            


*/