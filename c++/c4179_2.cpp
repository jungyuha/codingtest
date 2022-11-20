#include <bits/stdc++.h>
using namespace std;

int a,b,res;
char mp1[1004][1004];
int fireChecked[1004][1004];
int personChecked[1004][1004];

const int INF = 987654321;
queue<pair<int,int>> q ;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int main(){

    cin >> a >> b;
    int cx , cy ;
    fill(&fireChecked[0][0],&fireChecked[0][0]+1004*1004,INF);

    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp1[i][j];
            if(mp1[i][j]=='F'){
                q.push({i,j});
                fireChecked[i][j]=1;
            }
            if(mp1[i][j]=='J'){
                cy = i; cx = j;
                personChecked[i][j]=1;
            }
        }
    }
    //불의 최단거리 계산
    while(q.size()){
        int fx,fy;
        tie(fy,fx) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nfx = fx + dx[i];
            int nfy = fy + dy[i];
            if(nfx < 0 || nfy < 0 || nfx >= b || nfy >= a) continue;
            if(mp1[nfy][nfx] == '#' || fireChecked[nfy][nfx] !=INF) continue;
            fireChecked[nfy][nfx]=fireChecked[fy][fx]+1;
            q.push({nfy,nfx});
        }
    }
    // 사람의 최단거리 계산
    q.push({cy,cx});
    while(q.size()){
        int x , y;
        tie(y,x)=q.front();
        q.pop();
        if(y==0 || y == a-1 || x == 0 || x == b-1) {
            res = personChecked[y][x];
            break;
        }
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(ny < 0 || nx < 0 || ny >= a || nx >= b || personChecked[ny][nx]||mp1[ny][nx]=='#') continue;
            if(personChecked[y][x]+1>=fireChecked[ny][nx]) continue;
            personChecked[ny][nx] = personChecked[y][x]+1;
            q.push({ny,nx});
        }
    }
    if(res > 0){
        cout << res << "\n";
    }
    else{
        cout << "IMPOSSIBLE"<< "\n";
    }
    return 0;
}