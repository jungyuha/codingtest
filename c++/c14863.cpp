#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
typedef long long ll;
int n,k;
pair<int,int> mp[110][2];
int dp[110][1000000000];

int go(int idx,int m_res){// idx : 0 m_res : 0 n = 1 , 도시의 갯수 n+1 =2
    int res=0;
    if(m_res>k) return INF;
    if(idx==n) return 0;
    if(dp[idx][m_res] > 0) return dp[idx][m_res];
    dp[idx][m_res]= max(go(idx+1,m_res+mp[idx][0].first)+res+mp[idx][0].second,go(idx+1,m_res+mp[idx][1].first)+res+mp[idx][1].second);
    return dp[idx][m_res];
}
int main(){

    cin >> n >> k;
    int a,b,c,d;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c >> d;
        mp[i][0] ={a,b};
        mp[i][1] ={c,d};
    }
    cout << go(0,0);
    return 0;
}