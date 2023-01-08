#include <bits/stdc++.h>
using namespace std;

int n,m,mp[10000];
long long st,ed,mid,res=60000000001;
void go(){
    st=0; ed=60000000000;   
    while(st<=ed){
        long long m_res=m;
        mid = (st+ed)/2;
        // (1)

        for(int i=0;i<m;i++){
            // (2) 
            // (3) 
            m_res+=(mid/mp[i]);
        }
        // (4) 
        if(m_res>=n){
            res=min(res,mid);
            ed=mid-1;
        }
        else if(m_res<n){
            st=mid+1;
        }
    }
    
}
int main(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> mp[i];
    }
    if(n<=m){
        cout << n << endl;
        return 0;
    }
    go();

    int m_res = m;
    for(int i=0;i<m;i++){
        m_res+=((res-1)/mp[i]);
    }
    for(int i=0;i<m;i++){
        if(res%mp[i] == 0) m_res++;
        if(m_res==n) {
            cout << i+1 << endl;
            return 0;
        }
    }
    
    return 0;
}