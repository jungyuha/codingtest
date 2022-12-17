/*
*) 입력
7
20 1
2 1
100 2
8 2
10 3
5 20
50 10

*) 메모리
int a,v,d,max_d,res;
vector<pair<int,int>>lst;
*) 시나리오
날짜순으로 오름차순 정렬한다
같은 날짜 범위 안에서의 가장 값어치가 큰 강의를 선택
선택한 강의는 방문처리를 한다.

(dd:max_d 순회)
    int midx=-1;
    int max_=-1;
    (dd<=lst의 d lst 순회) : j=0;j<a;j++ 
        if(lst 방문처리 || dd > lst의 d) continue; // 이미 강연을 했거나 날짜가 지난 강연은 패스한다.
        if(dd < lst의 d) break;
        if(lst의 v>max_){
            max_=v;
            midx=j;
    if midx > -1 :
        res+=max_;
        lst[midx].second = -1;
    

*) 출력
(1)
    for(int i=0;i<a;i++){
        cout << lst[i].first<<","<<lst[i].second<<"\n";
    }
(2)
cout << "0 " << lst[j].first<<","<<lst[j].second<<"\n";
(3)
cout << " 1 dd : " <<dd<<",midx : "<<midx<<",max_ : "<<max_<<"\n";
(4)
cout << "2 dd : " <<dd<<",midx : "<<midx<<",max_ : "<<max_<<"\n";
*/