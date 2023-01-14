#include <bits/stdc++.h>
using namespace std;

int mp[1000][2][30],arr[1000],res;
int t,w,a;

int go(int n,int p ,int m){
   // (1)
   if(n<0 || m <0) {
    // (2)
    return -987654321;
   }
   if(n == 0){
        //(3)
        if(p==0){
            // (4)
            return mp[n][p][m] = 0;
        }
        else if(p==1){
            // (5)
            return mp[n][p][m] = -987654321;
        }
    }
    if(mp[n][p][m] == -1){
        // (6
        return mp[n][p][m] = max(go(n-1,p,m),go(n-1,(p^1),m-1))+(arr[n]==p+1 ? 1:0);
    }
    // (7)
    return mp[n][p][m];
}
int main(){

    memset(mp,-1,sizeof(mp));
    cin >> t >> w;
    for(int i=1;i<=t;i++){
        cin >> a;
        arr[i] = a;
    }
    // (8)
    int res = max(go(t,0,w),go(t-1,1,w-1));
    cout << "res :"<<res;
    return 0;
}