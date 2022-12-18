/*
*) 입력 {d,t}
3
2 1 
8 3
5 7

*) 메모리
int a,d,t,res;
vector<pair<int,int>> lst;

*) 시나리오
lst를 d를 기준으로 오름차순 정렬한다.
(lst순회)i=0;i<a;i++
    int start=lst[i].first;
    if(lst[i].first<=res){
        start = res+1;
    }
    res=start+lst[i].second;


*) 출력
(1)

*/