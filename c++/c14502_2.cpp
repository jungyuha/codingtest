#include <bits/stdc++.h>
using namespace std;

int n,m,max_;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int mp1[10][10];
int vis[10][10];
vector<pair<int,int>> pList;

void dfs(int cy,int cx){
    vis[cy][cx]=1;
    int nx,ny;
    for(int i=0;i<4;i++){
        nx = cx + dx[i];
        ny = cy + dy[i];
        if(nx < 0 || ny <0 || nx >= m || ny >= n || vis[ny][nx] == 1 || mp1[ny][nx] != 0 ) continue;
        dfs(ny,nx);
    }
}
void solve(){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp1[i][j]==2){
                dfs(i,j);
            }
        }
    }  
    int res=0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mp1[i][j]==0 && vis[i][j] == 0){
                res++;
            }
        }
    }     
    max_ = max(res,max_);
}
int main(){

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int k;
            cin >> k;
            if(k==0){
                pList.push_back({i,j});
            }
            mp1[i][j]=k;
        }
    }

    for(int i=0;i<pList.size();i++){
        int a1 = pList[i].first;
        int b1 =pList[i].second;
        for(int j=i+1;j<pList.size();j++){
            int a2 = pList[j].first;
            int b2 =pList[j].second;
            for(int k=j+1;k<pList.size();k++){
                int a3 = pList[k].first;
                int b3 =pList[k].second;
                mp1[a1][b1]=mp1[a2][b2]=mp1[a3][b3]=1;
                solve();
                mp1[a1][b1]=mp1[a2][b2]=mp1[a3][b3]=0;
            }
        }
    }

    cout << max_ << "\n";
    
    return 0;
}