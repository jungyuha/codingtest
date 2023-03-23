#include <bits/stdc++.h>
using namespace std;

int n,m,x,mp[1010][1010];
const int INF = 987654321;
vector<pair<int,int>> adj[10010];
int a=1000000000;
void init(){
    cin >> n >> m >> x;
    int a,b,c;
    fill(&mp[0][0],&mp[0][0]+1010*1010,INF);
    for(int i=1;i<=n;i++){
        mp[i][i]=0;
    }
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        mp[a][b]=c;
    }
}
void floydWarshall(){
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(mp[i][j]>mp[i][k]+mp[k][j]){
                    mp[i][j] = mp[i][k]+mp[k][j];
                }
            }
        }
    }
}
int main(){
    init();
    floydWarshall();
    int res=0;
    for(int i=1;i<=n;i++){
        res=max(res,mp[i][x]+mp[x][i]);
    }
    cout << res << endl;
    return 0;
}