/*
*) 입력
2 1
5 10
100 100
11

3 2
1 65
5 23
2 99
10
2

*) 메모리
int a , b ,res; // a 보석갯수 b 가방갯수
vector<pair<int,int>> aLst; // 보석
vector<int> bLst; // 가방

*) 시나리오1 
보석의 가격이 큰 순으로 정렬

*) 시나리오2(채택함)
가방의 무게가 작은 순으로 정렬(가방 수용 무게가 커질 수록 선택 범위가 넓어짐) && 그 각 무게 안에서 최대가격의 보석을 하나씩 고르기

*) 시나리오3 : 모든 경우의 수
최대 경우의 수 : a(p)b

*) 시나리오2(채택함) : 가방의 무게가 작은 순으로 정렬(가방 수용 무게가 커질 수록 선택 범위가 넓어짐) && 그 각 무게 안에서 최대가격의 보석을 하나씩 고르기
bLst 가방 오름차순 정렬
aLst 보석 내림차순 정렬
(b : bLst 가방 순회)
    (a : aLst 보석 순회)
        if b < a || a == -1 : continue 보석이 더 크면 가방이 못 담음 || 이미 담은 보석이면 가방이 못 담음
        res += a;   가방이 담을 수 있으니 보석의 무게를 더한다.
        a의 값을 -1로 바꿈

*) 출력
(1) 가방 , 보석
for(int i=0;i<b;i++){
        cout << bLst[i] << "," ;
    }
    cout <<"\n";
for(int i=0;i<a;i++){
        cout <<"{"<< aLst[i].first <<","<< aLst[i].second  << "}," ;
    }
    cout <<"\n"; 
(2) cout << "i("<<i<<") / " ;  
cout <<"1 ("<< aLst[j].first<<","<<bLst[i]<<") /" ;
cout <<"2 ("<< aLst[j].second<<") /" ; 
cout <<"3 ("<< aLst[j].second<<","<<max_<<") /" ;
cout << "4 ("<<max_index<<") / " ;
cout <<"5 ("<< max_<<") \n" ;
*/