#include<bits/stdc++.h>
using namespace std;

int n,m,vis[15];
long long dp[105];
int mp[10];
void init(){ 
    //fill(dp,dp+105,INF);
    memset(dp, 0x7f , sizeof(dp));
    mp[2]=1; mp[3]=7; mp[4]=4; mp[5]=2; mp[6]=0; mp[7]=8;
    dp[2]=1; dp[3]=7; dp[4]=4; dp[5]=2; dp[6]=6; dp[7]=8;dp[8]=10;
}
string makeMin(int n){
    int a = n/2;
    int b = n%2;
    string k="";
    // n = 6 , a = 3 => 111
    // n = 5 , a = 1 => 17
    if(b==1) { a--;k+="7"; }
    for(int i=1;i<=a;i++){
        k+="1";
    }
    return k;
}
int main(){
    init();
    for(int i=9;i<=100;i++){ // 성냥 갯수
        for(int j=2;j<=7;j++){
            dp[i]=min(dp[i],dp[i-j]*10+mp[j]);
       
        }
        //cout << "dp["<<i<<"]:"<<dp[i]<<endl;
    }

    // 입력 받음
    cin >> n;
    while(n){
        cin >> m;
        cout << dp[m] <<" " << makeMin(m) << endl;
        n--;
    }
    
    return 0;
}
