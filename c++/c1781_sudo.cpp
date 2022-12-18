/*
*) 입력
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
*) 메모리
int a,d,c;
vector<pair<int,int>> lst;
priority_queue<int,vector<int>,greater<int>> pq; // 우선순위 큐

*) 시나리오
lst를 d로 오름차순하여 정렬
(lst 순회)i=0;i<a;i++
    pq에 lst[i].second를 담는다.
    res에 lst[i].second를 더한다.
    if pq의 크기가 lst[i].first보다 크면
        res에 pq.top()을 뺀다.
        pq.pop()

*) 출력
(1)
    for(int i=0;i<a;i++){
        cout << "1 {"<< lst[i].first <<","<< lst[i].second<<"} " ; 
    }
(2)
    cout << "i:" <<i << "size:" <<pq.size() << ",{"<< lst[i].first <<","<< lst[i].second<<"} \n" ; 
(3)
    cout << ", res:" <<res<< endl ;
*/