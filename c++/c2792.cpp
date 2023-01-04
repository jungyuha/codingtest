#include <bits/stdc++.h>
using namespace std;

int n,m,max_,s,e,mid,res=9999999;
int mp[300000];

void go(int t1){
 s= 1; e = t1;

 while(s<=e){
    mid = (s+e)/2;
    int m_cnt =0;
    for(int i=0;i<m;i++){
        m_cnt+=(mp[i]/mid);
        if(mp[i]%mid > 0) m_cnt++;
    }
    if(m_cnt <= n) res = min(res,mid);
    if(m_cnt > n){
        s = mid+1;
    }
    else{
        e = mid-1;
    }
 }
}
int main(){

    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> mp[i];
        max_ = max(max_,mp[i]);
    }
    go(max_);
    cout << res << endl;
    return 0;
}