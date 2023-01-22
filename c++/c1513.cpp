#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1,0};
const int dy[] = {0,1};
int x,y,c,t1,t2,mp[50][50],dp[50][50][50][50];
int go(int cy,int cx,int prev,int cnt){
    //cout << "go ["<<cy<<"]["<<cx <<"],prev:"<<prev<<",cnt:"<<cnt<<endl;
    int m_res=0;

    if(cnt < 0) return 0;
    if(cy>y || cx>x) return 0;
    if(dp[cy][cx][cnt][prev]!=-1) return dp[cy][cx][cnt][prev];
    if(cy==y && cx ==x){
        if(cnt ==1 && mp[cy][cx] >= prev){
            // (1) 
            return 1;
        }
        else if(cnt == 0 && mp[cy][cx] == 0){
            // (2)
            return 1;
        }
        else{
            // (3)
            return 0;
        }
    }

    if(mp[cy][cx] > 0 && mp[cy][cx]>= prev){
        m_res=go(cy+dy[0],cx+dx[0],mp[cy][cx]+1,cnt-1)+go(cy+dy[1],cx+dx[1],mp[cy][cx]+1,cnt-1);
    }
    else if(mp[cy][cx] == 0){
        m_res = go(cy+dy[0],cx+dx[0],prev,cnt)+go(cy+dy[1],cx+dx[1],prev,cnt);
    }

    // (4)
    dp[cy][cx][cnt][prev] = m_res;
    return m_res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d %d %d",&x,&y,&c); // x : 가로 , y : 세로
    x--; y--;

    for(int i=1;i<=c;i++){
        scanf("%d %d",&t1,&t2); // 열, 행
        mp[t2-1][t1-1]=i;
    }

    for(int i =0;i<=c;i++){
        int ret = go(0,0,1,i);  // 행 , 열 , 오락실 순서 , 방문할 오락실 수       
        cout <<ret<<" ";
    }

    return 0;
}