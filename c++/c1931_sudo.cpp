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
*) 
hLst의 second를 기준으로 오름차순 정렬
(h : 정렬된 hLst 순회)
    if 이전의 끝 <= h의 시작 
        res++;
        pre_end=h의 끝;


*/