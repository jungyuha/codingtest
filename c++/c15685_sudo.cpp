/*
*) 입력
4
3 3 0 1
4 2 1 3
4 2 2 1
2 7 3 4

3
3 3 0 1
4 2 1 3
4 2 2 1

10
5 5 0 0
5 6 0 0
5 7 0 0
5 8 0 0
5 9 0 0
6 5 0 0
6 6 0 0
6 7 0 0
6 8 0 0
6 9 0 0

*) 메모리
mp[100][100]; // 간선 리스트
vis[100][100];
const int di[4]={0,1,2,3}; // 우,상,좌,하
*) 시나리오
(메인)
    커브입력
    (커브당 순회)
        0세대
        int last=0,fx,fy;
        vector<int> lst;
        lst.push(0새댜);
        (세대 순회) 1세대~
            (lst 순회) int i = last ; i>=0
                lst 방향에 따라:
                    fx , fy에 이어 붙이기
                fx = nx , fy = ny
    (vis 순회)
        정사각형 세기

*) 출력


*/