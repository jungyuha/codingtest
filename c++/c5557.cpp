
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mp[110],dp[110][1000];
ll go(int idx,int m_sum){
    // idx : 1 , size : 1 (n-1)
    ll res = 0;
    if(m_sum<0 || m_sum>20) return 0;
    if(idx==n-1){
        if(m_sum==mp[n]) { return 1; }
        else { return 0;}
    }
    if(dp[idx][m_sum] != -1) return dp[idx][m_sum];
    res += go(idx+1,m_sum+mp[idx+1]);
    res += go(idx+1,m_sum-mp[idx+1]);
    dp[idx][m_sum]=res;
    return res;
}
int main(){
​
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> mp[i];
    }
    memset(dp,-1,sizeof(dp));
​
    cout << go(1,mp[1]);
    return 0;
}