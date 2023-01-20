#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
const int dx[] = {1,0};
const int dy[] = {0,1};
int n,m,c,t1,t2,mp[50],dp[5050][50];
// int go(int idx){
//     // (1) 
//     if(prc == m){ return mp[idx][0];} // (2)
//     if(prc > m) {  return 0;} //(3)
//     if(dp[prc]!=-1) return dp[prc];
//     int res=INF;
//     for(int i=0;i<n;i++){
//         res=max(res,go(prc+mp[i][1],i));
//     }
//     res+=mp[idx][0];
//     dp[prc]=res;
//     return res;
// }
int main(){
        memset(dp,-1,sizeof(dp));
        scanf("%d %d %d",&n,&m,&c);

        for(int i=0;i<c;i++){
            scanf("%d %d",&t1,&t2);
            mp[i]=t1*100+t2;
        }
        int ret=INF;
        for(int i=0;i<c;i++){
            go(mp[i]));
        }
        cout <<ret<<endl;
    return 0;
}