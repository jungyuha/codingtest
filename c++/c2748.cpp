#include <bits/stdc++.h>
using namespace std;

int mp[90],res;

int go(int n){
    if(mp[n]!=-1){
        return mp[n];
    }
    return go(n-1)+go(n-2);
}
int main(){
    memset(mp,-1,sizeof(mp));
    mp[0]=0;mp[1]=1; mp[2]=1;

    int a ;
    cin >> a;

    res = go(a);

    cout << res << endl;
    return 0;
}