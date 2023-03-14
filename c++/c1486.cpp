#include <bits/stdc++.h>
using namespace std;

int n,m,t,d,mp[30][30],dp[30][30][1000010];
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};
void init(){
    memset(dp,-1,sizeof(dp));
    cin >> n >> m >> t >> d;
    char a;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> a;
            if(a >= 'A' && a <= 'Z'){
                mp[i][j] = int(a -'A');
            }
            else if(a >= 'a' && a <= 'z'){
                mp[i][j] = int(a -'a'+26);
            }
        }
    }
}

int go(int y1_,int x1_,int ti_,int hi_){
    int &res = dp[y1_][x1_][ti_];
    if(res!=-1) return res;
    res = hi_;
    for(int i=0;i<4;i++){
        int ny = y1_ + dy[i]; int nx = x1_ + dx[i]; int val=0;
        if(ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
        if(mp[ny][nx]>hi_){
            val = pow(mp[ny][nx]-hi_,2);
        }
        else{ val = 1; }
        
        if(abs(mp[ny][nx]-hi_)>t || ti_+val > d) {cout << val << " ";continue;}
        res=max(res,go(ny,nx,ti_+val,mp[ny][nx]));
    }
    return res;
}
int main(){
    init();
    cout << go(0,0,0,mp[0][0]) << endl;
    return 0;
}
//N과 M은 25보다 작거나 같은 자연수이다. 둘째 줄부터 N개의 줄에 지도가 주어진다. T는 52보다 작거나 같은 자연수이고, D는 1,000,000보다 작거나 같은 자연수이다.