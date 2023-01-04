#include <bits/stdc++.h>
using namespace std;

int n,m,tot,s=-1,e,mid,res=999999;
int mp[100000];
void go(int tot){
    e = tot;
    
    while(s<=e){
        mid = (s+e)/2;
        // (1) 
        int m_sum=0,m_cnt=0,m_max=0;
        // (3-1) 
        for(int i=0;i<n;i++){
            // (3-2) 
            m_sum+=mp[i];
            if(m_sum>mid){
                m_sum-=mp[i]; i--; m_cnt++;
                // (3-3)
                m_max=max(m_max,m_sum);
                // (2)
                // (3-4)
                m_sum=0;
            }
        }
        if(m_sum>0) {
            m_cnt++; 
            // (2)
            //(3-4)
            m_max=max(m_max,m_sum);
        }
        // (4) 
        if(m_cnt==m){
            res = min(res,m_max);
        }
        if(m_cnt>m){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
}
int main(){
    cin >> n >> m ;
    for(int i=0;i<n;i++){
        cin >> mp[i];
        tot+=mp[i];
        s = max(s,mp[i]);
    }

    go(tot);
    cout << res << endl;
    return 0;
}