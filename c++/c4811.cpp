#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,w,h; // dp[w][h][hw]
ll dp[35][65][2];
ll go(int w_,int h_,int hw){
    if(w_ < 0 || h_ < 0 ) return 0;
    if(w_== 0 && h_ == 0) return 1;
    if(dp[w_][h_][hw]!=-1) return dp[w_][h_][hw];

    ll res = go(w_,h_-1,0) + go(w_-1,h_+1,1);
    dp[w_][h_][hw]= res;

    return res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    while(1){
        cin >> n;
        if(n==0) break;
        cout << go(n,0,0)<<endl;
    }
    return 0;
}