#include <bits/stdc++.h>
using namespace std;

int a ,b ,c; // 3 5 10
int res; // 인구이동 날짜
bool endYn = false ; // 인구이동 종료 여부
int mp1[50][50];
int vis[50][50];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

void dfs(vector<pair<int,int>> &union_ , int cx , int cy){
    vis[cy][cx] =1;
    union_.push_back({cy,cx});
    for(int k=0;k<4;k++){
        int nx = cx + dx[k];
        int ny = cy + dy[k];
        if(nx < 0 || nx >= a || ny < 0 || ny >= a || vis[ny][nx] == 1) continue;
        if(abs(mp1[ny][nx]-mp1[cy][cx]) >= b && abs(mp1[ny][nx]-mp1[cy][cx]) <= c){
            dfs(union_,nx,ny);
        }
    }
}
int main(){
    cin >> a >> b >> c;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> mp1[i][j];
        }
    }

    while(!endYn){
        vector<vector<pair<int,int>>> unionLst;
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(vis[i][j]==1) continue;
                vector<pair<int,int>> union_;
                dfs(union_,j,i);
                unionLst.push_back(union_);
            }
        }
        int unionCnt = 0;
        for(vector<pair<int,int>> union_ : unionLst){
            int avg=0,sum=0,cnt=0;
            if(union_.size()>1) {
                unionCnt++;
                cnt = union_.size();
                for(pair<int,int> el : union_){
                    sum+=mp1[el.first][el.second];
                }
                avg = sum / cnt;
                for(pair<int,int> el : union_){
                    mp1[el.first][el.second] = avg;
                }
            }
        }
        fill(&vis[0][0],&vis[0][0]+50*50,0);
        if(unionCnt>0){
            res++;
        }
        else{
            endYn = true;
        }
    }
    cout << res << "\n";
    return 0;
}
/*
[수도코드]
1. 입력
3 5 10
10 15 20
20 30 25
40 22 10

*) mp1[50][50]
10 15 20 ..
20 30 25
40 22 10
..
*) vis1[0][0]
0 0 0 ..
0 0 0
0 0 0
..
*) unionLst : vector<vector<pair<int,int>>>
vector<pair<int,int>> => unionLst[0] : {{y,x},{y,x},{y,x}}
vector<pair<int,int>> => unionLst[1] : {{y,x},{y,x},{y,x}}

int a ,b ,c; // 3 5 10
int res; // 인구이동 날짜
bool endYn = false ; // 인구이동 종료 여부

endYn = true가 될때까지 반복 => vector<vector<pair<int,int>>> unionLst;
    (1순회1) mp1 {10(선,0,0) 15 20 20 30 25 40 22 10} => vector<pair<int,int>> union_; // 연합 생성 , int cx => 현재 위치(순회)
        if 현재 위치(순회) 방문 경험X 
            dfs(union , cx ,cy)
                방문처리 => vis[cy][cx] = 1
                union 추가 => union.push_back(cx)
                (1순회2) {상(선,0),우,하,좌} => 새로운 위치 int nx
                    if 새로운 위치 범위초과 X && 새로운 위치 방문 경험 X
                        if 현재위치와 새로운 위치 => 차이값 c 이하인지
                            dfs(nx,ny)
        unionLst.push_back(union); // 연합 리스트에 추가
    int unionCnt=0;(진짜 연합의수 , 연합 내 요소가 1개면 연합이 아님 ,이게 0이면 끝난것이다.)
    (2순회1) unionLst [{{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,1}}(선,union) , {{2,0}} , {{2,2}}] => int avg=0,sum=0,cnt=0;
        if (선,union).size() > 1  =>  union내의 인자 갯수가 2개 이상인지 체크(unionCnt)
            unionCnt++;(연합 수 체크)
            cnt = (선,union).size();
            (2순회2)union [{0,0}(선),{0,1},{0,2},{1,0},{1,1},{1,2},{2,1}] => (선,union) 인구 이동 평균 계산
                sum += mp1[first][second];
            avg = sum / cnt; => 평균 계산
            (2순회2)union [{0,0}(선),{0,1},{0,2},{1,0},{1,1},{1,2},{2,1}] => (선,union) 인구 이동
                mp1[first][second] = avg;
    memset(vis,0,sizeof(vis)) => 방문 초기화
    if(unionCnt > 0) => 연합이 있어서 인구이동을 했다면
        res++; (인구이동 날짜 증가)
    else
        endYn = true ;=> 인구이동 완전 끝
*/