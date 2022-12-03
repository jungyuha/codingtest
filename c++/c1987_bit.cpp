#include<bits/stdc++.h>
using namespace std;

int a,b,ret;
char mp1[20][20];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
void dfs(int cy,int cx ,int num,int cnt){
    ret = max(ret,cnt);
    for(int i=0;i<4;i++){
        int nx = cx +dx[i];
        int ny = cy +dy[i];
        if(nx<0||ny<0||nx>=b||ny>=a) continue;
        if(num&(1<<(int)(mp1[ny][nx]-'A'))) continue;
        int next = 1<<(int)(mp1[ny][nx]-'A');
        dfs(ny,nx,num|next,cnt+1);
    }
}
int main(){

    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp1[i][j];
        }
    }

    dfs(0,0,(int)(1<<mp1[0][0]-'A'),1);

    if(ret>0) {cout << ret;}
    else{cout <<"-1";}

    return 0;
}