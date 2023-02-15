#include <bits/stdc++.h>
using namespace std;

int n,visited[55];
int mp[55][3],dp[1005][1005];

int go(int str_,int int_){
	if(dp[str_][int_] != -1) return dp[str_][int_];
    int pnt_ = 0;
    int ret = 0;
    vector<int> vis;
    for(int i=0;i<n;i++){
        if(str_>=mp[i][0] || int_ >= mp[i][1]){
            ret++;
            if(visited[i]==0){
                visited[i]=1;
                vis.push_back(i);
                pnt_+=mp[i][2];
            }
        }
    } 
    dp[str_][int_] = ret;
    for(int i=0;i<=pnt_;i++){
        ret=max(ret,go(str_+i,int_+pnt_-i));
    }
    for(int el : vis){
        visited[el]=0;
    }
    dp[str_][int_]=ret;
    return ret;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cin >> n;
    int a,b,c;
    for(int i=0;i<n;i++){
        cin >> a >> b >> c;
        mp[i][0]=a;mp[i][1]=b; mp[i][2]=c;
    }
    cout <<go(1,1) << endl;
    return 0;
}