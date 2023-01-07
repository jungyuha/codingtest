#include <bits/stdc++.h>
using namespace std;

int s,c,st=1,ed=987654321,mid,tot,res=-1,lst[1000000];
int main(){

    cin >> s >> c;
    for(int i=0;i<s;i++){
        cin >> lst[i];
        ed = min(ed,lst[i]);
        tot+=lst[i];
    }
    while(st <= ed){
        mid = (st+ed)/2;
        // (1)
        int m_res=0;
        for(int i=0;i<s;i++){
            m_res+=(lst[i]/mid);
            cout << lst[i]/mid << ", ";
        }
        // (2)
        if(m_res==c){
            res=max(res,mid);
        }
        if(m_res>=c){
            st=mid+1;
        }
        else{
            ed=mid-1;
        }
    }
    // (3)
    res = tot - (res*c);
    // (4)
    return 0;
}