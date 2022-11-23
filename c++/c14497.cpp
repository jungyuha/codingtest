#include <bits/stdc++.h>
using namespace std;

int m , n , level = 0; // 5 7
pair<int,int> a; // 주난
pair<int,int> b; // 도둑
char mp1[300][300];
int vis[300][300];
queue <pair<int,int>> q;
const int dx[] ={0,1,0,-1};
const int dy[] ={-1,0,1,0};
int main(){
    //cout << " " << << "," << '\n';
    cin >> m >> n ;
    cin >> a.first >> a.second >> b.first >> b.second;

    cout << a.first << a.second << b.first << b.second;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> mp1[i][j];
        }
    }
    q.push({a.first-1,a.second-1});
    while(vis[b.first][b.second]==0){
        level++;
        cout << "level " << level << ", q.size :" << q.size() << '\n';
        queue <pair<int,int>> qq;
        while(q.size()){
            int qx = q.front().second;
            int qy = q.front().first;
            
            for(int i=0;i<4;i++){
                int nqx = qx + dx[i];
                int nqy = qy + dy[i];
                cout << "qx " << qx << "qy " << qy<< "nqx " << nqx << "nqy " << nqy <<"mp1[nqy][nqx] :" <<mp1[nqy][nqx] << '\n';
                if(nqx<0 || nqy<0 || nqx >=n || nqy >=m || vis[nqy][nqx] > 0) continue;
                if(mp1[nqy][nqx]=='1'){
                    qq.push({nqy,nqx});
                }
                else{
                    q.push({nqy,nqx});
                    vis[nqy][nqx]=level;
                }
            }
            q.pop();
        }
        cout << "level " << level << ", qq.size :" << qq.size() << '\n';
        q = qq;
    }
    cout << vis[b.first][b.second];
    return 0;
}