#include<bits/stdc++.h>
using namespace std;

int a,b,max_sum,sum;
int res1,res2,res3;
int mp1[50][50];
int vis[50][50];
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
void dfs(int cx,int cy){
    sum++;
    for(int i=0;i<4;i++){
        int nx = cx+dx[i]; int ny = cy+dy[i];
        if(nx<0||ny<0||nx>=a||ny>=b||vis[ny][nx]==1) continue;
        if(mp1[cy][cx]&(1<<i)) continue;
        vis[ny][nx]=1;
        dfs(nx,ny);
    }
}
void go(){
    int cnt=0;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            sum=0;
            if(vis[i][j]==1) continue;
            vis[i][j]=1;
            dfs(j,i);
            vis[i][j]=0;
            max_sum=max(max_sum,sum);
            cnt++;
        }
    }
    res1 = cnt;
    res2 = max_sum;
    memset(vis,0,sizeof(vis));
}
int main(){
    cin >> a >> b;
    for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cin >> mp1[i][j];
        }
    }
    go();
    max_sum=0;
    for(int i=0;i<b;i++){//y
        for(int j=0;j<a;j++){//x
            for(int k=0;k<4;k++){
                int nx = j+dx[k]; int ny = i+dy[k];
                if(nx<0||ny<0||nx>=a||ny>=b) continue;
                if (mp1[i][j]&(1<<k)){
                    mp1[i][j]&=(~(1<<k));
                    if(k==0){mp1[ny][nx]&=(~(1<<2));}  
                    else if(k==1){mp1[ny][nx]&=(~(1<<3));}
                    else if(k==2){mp1[ny][nx]&=(~(1<<0));}
                    else if(k==3){mp1[ny][nx]&=(~(1<<1));}
                    sum=0;
                    vis[ny][nx]=1;
                    dfs(nx,ny);
                    memset(vis,0,sizeof(vis));
                    max_sum = max(max_sum,sum);
                    mp1[i][j]|=(1<<k);
                    if(k==0){mp1[ny][nx]|=((1<<2));}
                    else if(k==1){mp1[ny][nx]|=((1<<3));}
                    else if(k==2){mp1[ny][nx]|=((1<<0));}
                    else if(k==3){mp1[ny][nx]|=((1<<1));}
                }
            }
        }
    }
    res3 = max_sum;
    
    cout << res1 << "\n" << res2 << "\n"<< res3 << "\n";

    return 0;
}