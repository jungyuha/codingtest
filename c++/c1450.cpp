#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c,mp[35],dp[35][1000000000];
ll go(int idx,ll m_sum){
     
    // idx : 0 ,m_sum :0,n : 1 , c : 10 , mp[1]: 10
    // idx : 1 ,m_sum :10,n : 1 , c : 10 , mp[1]: 10
    // idx : 1 ,m_sum :0,n : 1 , c : 10 , mp[1]: 10
    ll res = 0;
    if(m_sum > c) return 0;
    if(idx==n) {cout << "idx : " << idx << ",m_sum :"<<m_sum << endl; return 1;}
    if(dp[idx][m_sum]>0) return dp[idx][m_sum];
    res += go(idx+1,m_sum+mp[idx+1]);
    res += go(idx+1,m_sum);

    dp[idx][m_sum]= res;
    return res;
}
int main(){

    cin >> n >> c ;
    for(int i=1;i<=n;i++){
        cin >> mp[i];
    }
    cout << go(0,0);
    return 0;
}