#include <bits/stdc++.h>
using namespace std;

const int INF=987654321;
int mp[16][16];
int n;
int go(int here,int vis){
    cout << "here : "<<here<<endl;
    if(vis==(1<<n)-1){
        // if(mp[here][0]!=0 )cout << "end! ";
        // cout << endl;
        return (mp[here][0]!=0) ? mp[here][0] : INF ;
    }
    for(int i=0;i<n;i++){
        cout << "("<<here<<")"<<i<<endl;
        if(vis&(1<<i)) continue;
        if(mp[here][i]==0) continue; 
        go(i,vis|(1<<i));
    }
}
int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }

    go(0,1);
    return 0;
}