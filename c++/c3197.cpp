#include <bits/stdc++.h>
using namespace std;

queue <pair<int,int>> q;
int level= 0;
pair<int,int> ap,bp; 
vector<pair<int,int>> pLst; 
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
char mp1[1500][1500];
int melted[1500][1500];
int vis[1500][1500];
int a , b ,res;
int main(){

    cin >> a >> b ;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp1[i][j];
            if(mp1[i][j] == 'L'){
                pLst.push_back({i,j});
            }
            if(mp1[i][j] == 'X'){
                q.push({i,j});
            }
        }
    }
    ap = pLst[0]; bp = pLst[1];
    bool meet=false;

    while(!meet){
        level++;
        meet=false;
        queue<pair<int,int>> temp;
        while(q.size()){
            int qy = q.front().first;
            int qx = q.front().second;
            bool xx = true;
            for(int i=0;i<4;i++){
                int nqy = qy+dy[i];
                int nqx = qx+dx[i];
                if(nqy < 0 || nqx<0 || nqy >=a || nqx >=b) continue;
                if(mp1[nqy][nqx]!='X'||(melted[nqy][nqx] < level && melted[nqy][nqx] >0)){
                    melted[qy][qx]=level;
                    xx=false; // 녹아버림
                    break;
                }
            }
            if(xx){ temp.push({qy,qx});}
            q.pop();
        }
        q=temp;

        queue <pair<int,int>> oq; // 오리 순회용
        oq.push({ap.first,ap.second});
        while(oq.size()){
            int qy = oq.front().first;
            int qx = oq.front().second;  // q의 위치
            for(int i=0;i<4;i++){
                int nqy = qy+dy[i];
                int nqx = qx+dx[i];
                if(nqy < 0 || nqx<0 || nqy >=a || nqx >=b||(mp1[nqy][nqx]=='X'&& melted[nqy][nqx]==0)||vis[nqy][nqx]==1) continue;
                if(nqy == bp.first && nqx == bp.second){
                    res = level-1;
                    meet = true;
                    break;
                }
                if(mp1[nqy][nqx]!='X'||(melted[nqy][nqx] < level && melted[nqy][nqx] >0)){
                    oq.push({nqy,nqx});
                    vis[nqy][nqx]=1;
                }
            }
            if(meet) break;
            oq.pop();
        }
        fill(&vis[0][0],&vis[0][0]+1500*1500,0);
    }
    cout << res << "!! \n";
    return 0;
}