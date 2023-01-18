#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n,k,mp[101],dp[10010];
int go(int cur){
    if(cur==k){return 0;}
    if(cur>k){return INF;}
    if(dp[cur]!=-1) return dp[cur];
    int res = INF,res2=-1,mid=0;
    for(int i=0;i<n;i++){
        mid=go(cur+mp[i])+1;
        if(res>mid){ res = mid; res2=i; }
    }
    if(res2!=-1){
        dp[cur]=res;
    }
    return res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    int ret = go(0);
    if(ret>=INF) ret = -1;
    cout << ret << endl;
    return 0;
}
/*
2 5
1 3
1 1 3
*/