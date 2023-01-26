#include <bits/stdc++.h>
using namespace std;

const int INF = 98654321;
int vis[10][10],mp[10][10],mp2[10][10],res=INF;
int paper[6]={0,5,5,5,5,5};
vector<pair<int,int>> pLst;
void showVis(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}
void showMp(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << mp2[i][j] << " ";
        }
        cout << endl;
    }
}
void showPaper(){
    for(int i=1;i<6;i++){
        cout << paper[i] << " ";
    }
    cout << endl;
}
void draw (int cy , int cx ,int k,int d){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            vis[cy+i][cx+j]=d;
        }
    }
}
bool drawCheck(int cy , int cx , int k){
    bool yn = true;
    if(paper[k]==0) { return false; }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(vis[cy+i][cx+j]==1 || mp[cy+i][cx+j]==0 || cy+i < 0 || cx+j <0 || cy+i >= 10 || cx+j >= 10) {
                yn = false;
                break;
            }
        }
    }
    return yn;
}
int dfs(int idx,int cnt){
    vector<int> temp;
    if(idx==pLst.size()){
        // 방문 가능할 점이 이제 없거나
        res = min(res,cnt);
        return 0;
    }
    if(cnt>=res){
        // 더 이상 셀 필요 없음 => 백트래킹 부분 : 여기를 놓치면 완전 탐색이 되서 시간초과됨 
        return INF;
    }
    int ret=0;
    for(int i=5;i>0;i--){
        if(drawCheck(pLst[idx].first,pLst[idx].second,i)){
            // 색칠 성공하면
            draw(pLst[idx].first,pLst
            [idx].second,i,1);
            paper[i]--;
            int new_idx=idx+1; // 여기가 문제였다.......위에서 선언해서 다른 회차끼리 공유하고 있었음 ㅡㅡ
            while(new_idx<pLst.size()){
                if(new_idx == 1) showVis();
                if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
                new_idx++;
            }
            ret = 1;
            ret += dfs(new_idx,cnt+1);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
            
            // 방문 마치면 다시 원복
            draw(pLst[idx].first,pLst[idx].second,i,0);
            paper[i]++; 
        }
        else{
            // 색칠 실패하면
            ret = INF;
        }
        temp.push_back(ret);
    }
    sort(temp.begin(),temp.end());
    return temp[0];
}

int main(){
    int c;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> c;
            mp[i][j]=c;mp2[i][j]=c;
            if(c==1) pLst.push_back({i,j}); // 행,열
        }
    }
    int res1 = dfs(0,0); // dfs를 리턴으로도 구현하고 전역변수로도 구현함!!
    // cout << res1 << endl;
    cout << res << endl;
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0
0 1 1 1  0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 1 1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/