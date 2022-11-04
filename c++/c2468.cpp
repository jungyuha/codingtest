#include <bits/stdc++.h>
using namespace std;

int a,b,c,ret,length;
int max_ = -1;
int maxret = -1;
// a: 너비 , b : 입력 높이 값 , ret , length : 잠김 높이 , max_ : 입력 높이 최대값, maxret :  안전 영역 최대 개수
int mp[101][101];   // 입력받는 맵
int mp2[101][101]; // 1(안넘침),0(넘침)만 있는 맵
int visited[101][101]; // 방문 여부 맵
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

void dfs(int ax,int ay){
    // ax , ay : 현재 위치    
    visited[ay][ax]=1;
    int nx , ny ; // 다음 위치
    
    for(int i = 0; i<4;i++){
        nx = ax + dx[i];
        ny = ay + dy[i];
        if(nx < 1 || ny < 1 || nx > a || ny > a || visited[ny][nx] == 1 || mp2[ny][nx] == 0) continue;
        dfs(nx,ny);
    }

}
int main(){
    cin >> a;
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
            cin >> b;
            mp[i][j] = b;
            if(max_ < b){
                max_ = b;
            }
        }
    }
    length = max_ - 1;
    while (max_--){
        fill(&mp2[0][0],&mp2[0][0]+101*101,0);
        fill(&visited[0][0],&visited[0][0]+101*101,0);
        for(int i=1;i<=a;i++){
            for(int j=1;j<=a;j++){
                if(mp[i][j] >= length){
                    mp2[i][j] = 1;
                }
            }
         } 
        for(int i=1;i<=a;i++){
            for(int j=1;j<=a;j++){
                if(mp2[i][j] == 1 && visited[i][j] == 0){
                    dfs(j,i);
                    ret++;
                }
            }
        }
        if(ret > maxret) {
            maxret = ret;
        }
        ret = 0;
        length --;
    }
    return 0;
}