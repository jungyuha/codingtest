#include <bits/stdc++.h>
using namespace std;

int m,n;
int mp[100][100];
int vis[100][100];
vector<pair<int,int>> lst;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
vector<int> resList;
int res;

void dfs(int cy,int cx){
    vis[cy][cx]=1;
    int nx , ny ;
    
    for(int i=0;i<4;i++){
        nx = cx + dx[i];
        ny = cy + dy[i];

        if(mp[ny][nx]==1) {
            vis[ny][nx]=2;
            res++;
        }
        
        if(nx<0||nx>=n||ny<0||ny>=m||vis[ny][nx]==1||mp[ny][nx]==1) continue;

        dfs(ny,nx);
    }
}
int main(){
    cin >> m >> n;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }

   dfs(0,0);
   cout << res<< "\n";
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << vis[i][j];
        }
        
    }
    return 0;
}