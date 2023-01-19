#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
int n,m,t1,t2,c,p,mp[5010][2],dp[10010];
int go(int prc,int idx){
    // (1) 
    if(prc == m){ return mp[idx][0];} // (2)
    if(prc > m) {  return 0;} //(3)
    if(dp[prc]!=-1) return dp[prc];
    int res=INF;
    for(int i=0;i<n;i++){
        res=max(res,go(prc+mp[i][1],i));
    }
    res+=mp[idx][0];
    dp[prc]=res;
    return res;
}
int main(){
    while(1){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d.%d",&n,&t1,&t2);

        if(n==0 && t1 ==0 && t2 ==0 ) break;
        m=t1*100+t2;
        
        for(int i=0;i<n;i++){
            scanf("%d %d.%d",&mp[i][0],&t1,&t2);
            mp[i][1]=t1*100+t2;
        }
        int ret=INF;
        for(int i=0;i<n;i++){
            ret=max(ret,go(mp[i][1],i));
        }
        cout <<ret<<endl;
    }
    return 0;
}