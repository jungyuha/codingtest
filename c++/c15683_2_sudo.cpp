/*
*) 설명
- 맵을 vector<pair<int,int>> 형태로 표현하여 dfs로 구현함 + 맵을 전역변수에 하나로 두고 공유한다.
- 8로 채우고 dfs 끝나면 0으로 원복하는 방식 
4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 5 0 6 0
0 0 0 0 0 0
*) 메모리
int w,h,mp[10][10];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
vector<pair<int,int>> v1; // cctv 위치
*) 시나리오
(func2) int cy,cx,di
    if mp[ny][nx] == 1 :
        // 전역변수 맵 a를 채움
        // 채운 부분을 따로 기록함
        vector<pair<int,int>> _change;
    else if mp[ny][nx] == 2 :
    else if mp[ny][nx] == 3 :
    else if mp[ny][nx] == 4 :
    else if mp[ny][nx] == 5 :
    
    return _change;

(func1) int v1_index;
    if(v1_index == v1.size()){
        // 사각지대 계산
    }
    int ny = v1[index].first; int nx = v1[index].second;
    (4방향 순회)int i=0;i<4;i++
        vector<pair<int,int>> _change = func2(ny,nx,i); // CCTV 공간처리
        func1(v1_index+1);
        for(pair<int,int> el : _change):
            a[el.first, el.second] = 0
(메인)
    v1 입력
    func1(0);

*) 출력
(1) cout << "f2 :" << cy <<","<< cx << "," << di << endl;
(2) cout << "f1 :" << v1_index << endl;
*/