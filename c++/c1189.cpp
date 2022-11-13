#include <bits/stdc++.h>
using namespace std;

int a,b,tot,cnt,res; // 3,4,6
char mp[5][5];
int vis[5][5];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

void dfs(int cx,int cy){
    cnt++;
    if(cy == 0 && cx == b-1){
        if(cnt==tot) res++;
        cnt--;
        return ;
    }
    vis[cy][cx]=1;
    int nx,ny;
    for(int i=0;i<4;i++){
        nx = cx + dx[i];
        ny = cy + dy[i];

        if(nx<0||ny<0||nx>=b||ny>=a||vis[ny][nx]==1||mp[ny][nx]=='T') continue;
        dfs(nx,ny);
    }
    vis[cy][cx]=0;
    cnt--;
}
int main(){

    cin >> a >> b >> tot;
    for (int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp[i][j];
        }
    }
    dfs(0,a-1);
    
    cout << res << "\n";
    return 0;
}