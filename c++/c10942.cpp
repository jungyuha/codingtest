#include <bits/stdc++.h>
using namespace std;

int mp[2005],n,m,a,b;
bool dp[2005][2005];
bool check(int s, int e){
    if(s>e || s<1 || e>n) return false;
    bool res= true;
    int ss = s ; int ee = e;
    while(ss<=ee){
        if(mp[ss]!=mp[ee]) {res = false;}
        ss++;ee--;
    }
    return res;
}
void go(int idx){
    for(int i=1;i<=idx;i++){
        dp[i][idx] = check(i,idx);
    }
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> mp[i];
        go(i);
    }
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }
    return 0;
}