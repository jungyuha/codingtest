#include <bits/stdc++.h>
using namespace std;

int n,k,w,v,mp[110][2],dp[100010],vis[101];
int go(int wsum,int idx){
    // (1) 
    if(wsum == k){ return mp[idx][1];} // (2)
    if(wsum > k) {  return 0;} //(3)
    if(dp[wsum]!=-1) return dp[wsum];
    int res=0;
    for(int i=0;i<n;i++){
        if(vis[i]==1) continue;
        vis[i]=1;
        res=max(res,go(wsum+mp[i][0],i));
        vis[i]=0;
    }
    res+=mp[idx][1];
    dp[wsum]=res;
    return res;
}
int main(){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d",&n,&k);

        for(int i=0;i<n;i++){
            scanf("%d %d",&mp[i][0],&mp[i][1]);
        }
        int ret=0;
        for(int i=0;i<n;i++){
            vis[i]=1;
            ret=max(ret,go(mp[i][0],i));
            vis[i]=0;
        }
        cout <<ret<<endl;
    return 0;
}