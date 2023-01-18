#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int t,dp[1000010][2];
int go(int n){
    if(n==1) return 0;
    if(n<0) return 987654321;
    if(dp[n][0]!=-1) return dp[n][0];

    int res=INF,mid=0,res2=0;
    if(n%3 == 0) {
        mid = go(n/3)+1;
        if(res > mid){ res = mid; res2=n/3;}
    }
    if(n%2 == 0) {
        mid = go(n/2)+1;
        if(res > mid){ res = mid; res2=n/2;}
    }
    mid = go(n-1)+1;
    if(res > mid){ res = mid; res2=n-1;}
    dp[n][0]=res;
    dp[n][1]=res2;
    return res;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> t;
    int ret=go(t);
    cout <<ret<<endl;

    int temp = t;
    cout << t << " ";
    while(1){
        cout << dp[temp][1] << " ";
        temp = dp[temp][1];
        if(temp==1) break;
    }
    return 0;
}