#include <bits/stdc++.h>
using namespace std;

char mp1[20][20];
int ap[26];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int a,b,max_=-1;
void dfs(int cx,int cy,int level){
    bool endYn = true; 
    for(int i=0;i<4;i++){
        int nqy = cy+dy[i];
        int nqx = cx+dx[i];
        if(nqx < 0 || nqy < 0 || nqx >= b || nqy >= a ||  ap[mp1[nqy][nqx]-'A'] > 0) continue;
        ap[mp1[nqy][nqx]-'A'] = 1;
        dfs(nqx,nqy,level+1);
        ap[mp1[nqy][nqx]-'A'] = 0;
    }
    if(endYn){
        if(max_<level)  max_ = level;
    }
}
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp1[i][j];
        }
    }
    ap[mp1[0][0]-'A']=1;
    dfs(0,0,1);

    cout << max_ << "\n";
    return 0;
}