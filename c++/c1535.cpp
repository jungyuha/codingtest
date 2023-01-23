#include <bits/stdc++.h>
using namespace std;

const int INF=-987654321;
const int AA = (1<<20);
int n,mp[21][2],dp[21][AA];
int go(int idx,int vis,int cur,int cnt){
    //cout << "go idx:"<<idx<<",vis :"<<vis <<",cur:"<<cur<<",cnt:"<<cnt<<endl;
    int m_res=0;

    if(cur <= 0) return 0;
    if(dp[idx][vis]!=-1) return dp[idx][vis];
    if(cnt == n){
        //cout << "return(cnt == n) :"<<mp[idx][1]<<",idx:"<<idx<<",vis :"<<vis <<",cur:"<<cur<<",cnt:"<<cnt<<endl;
        return mp[idx][1];
    }
    for(int i=1;i<=n;i++){
        if(vis&(1<<i)) continue;
        m_res = max(m_res,go(i,vis|(1<<i),cur-mp[i][0],cnt+1));
    }
    m_res+=mp[idx][1];
    //cout << "return(m_res) :"<<m_res<<",idx:"<<idx<<",vis :"<<vis <<",cur:"<<cur<<",cnt:"<<cnt<<endl;
    dp[idx][vis] = m_res;
    return m_res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n); 

    for(int i =0;i<2;i++){
        for(int j =1;j<=n;j++){
            cin >> mp[j][i];
        }
    }

    cout << go(0,0,100,0);
    return 0;
}