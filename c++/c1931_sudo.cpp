/*
*) 입력
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

*) 메모리
vector<pair<int,int>> hLst;
int pre_end; // 이전의 끝
int res; // 회의 수
*) 시나리오 1
- 정해진 시간 안에 최대한 많은 회의를 해야함 = 정해진 범위 안에 최대한 많은 요소가 겹치지 않게 쌓여야함 
- 종료시간이 빠른 순으로 정렬한다 => 겹치지 않는 선에서 종료시간이 빠른 순으로 쌓는다.
hLst의 종료시간를 기준으로 오름차순 정렬
(h : 정렬된 hLst 순회)
    if 이전의 끝 <= h의 시작 
        res++;
        pre_end=h의 끝;

*) 시나리오 2 : 모든 경우의 수 
경우의 수(최대): 11!

*)출력
1. hLst
for(pair<int,int> el : hLst){
        cout << "{"<<el.second<<","<<el.first<<"} ,";
    }
    cout <<"\n";
2. (2)
cout << "i("<<i<<") , pre_end :"<<pre_end<<" , hLst[i].second :"<<hLst[i].second<<"\n";
*/