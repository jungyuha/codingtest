#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int INF = 987654321;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int n,m,vis[55][55],dp[55][55];
char mp[55][55],c;

int go(int cx,int cy){
    if(cx<0||cx>=m||cy<0||cy>=n||mp[cy][cx]=='H') return 0;
    if(dp[cy][cx] != -1 ) return dp[cy][cx];
    if(vis[cy][cx]==1 && dp[cy][cx]==-1) return INF;
    int res=-987654321;
    vis[cy][cx] = 1;
    for(int i=0;i<4;i++){
        int nx = cx ;
        int ny = cy ;
        for(int j=0;j<mp[cy][cx]-'0';j++){
            nx += dx[i];
            ny += dy[i];
        }
        res=max(res,go(nx,ny)+1);
    }
    dp[cy][cx]=res;
    // (1)
    vis[cy][cx] = 0;
    return res;
}
int main() {
    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            mp[i][j]=c;
        }
    }

    memset(dp,-1,sizeof(dp));

    int ret = go(0,0);
    if(ret>=INF){cout <<"-1";}
    else{cout << ret;}
    return 0;
}