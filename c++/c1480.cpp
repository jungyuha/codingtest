#include<bits/stdc++.h>
using namespace std;

const int INF = -987654321;
int n,m,c,d,mp[15],vis[15],dp[15][1<<15][5000];
// mp[15] : (0) 2 3 1 4 .. 보석의 무게
int test(int b_idx,int vis,int m_res){ 
    int res = INF;
    if(b_idx>m){
        // cout <<"담기 끝,구슬 => ";
        // for(int i=1;i<=n;i++){
        //     if((1<<i)&vis){cout << i<<",";}
        // }
        cout << endl;
        return 0;
    }
    if(dp[b_idx][vis][m_res]>0) return dp[b_idx][vis][m_res];
    //1. a(x)
        res=max(res,test(b_idx+1,vis,0));
    //2. a(A)
        for(int i=1;i<=n;i++){
            if(vis&(1<<i)) continue;
            if(m_res+mp[i]<=c) { res=max(res,test(b_idx,vis|(1<<i),m_res+mp[i]) + 1);}
        }
    dp[b_idx][vis][m_res]=res;
    return res;
}
/*
// 1 : X / 2: 1
*/
int main(){
    cin >> n >> m >> c; // 보석 가방 한도
    for(int i=1;i<=n;i++){
        cin >> mp[i];
    }
    cout << test(1,1,0) <<endl;
    return 0;
}
/*
첫째 줄에 보석의 개수 N, 가방의 개수 M, 가방의 최대 한도 C가 주어진다. N은 1보다 크거나 같고, 13보다 작거나 같은 자연수이고,
M은 1보다 크거나 같고, 10보다 작거나 같은 자연수이다. C는 1보다 크고, 20보다 작거나 같은 자연수이다. 둘째 줄에 보석의 무게가 하나씩 주어진다.
보석의 무게는 1보다 크거나 같고, 20보다 작거나 같은 자연수이다.
2 1 3
1 5
*/