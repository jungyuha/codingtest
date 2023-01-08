#include <bits/stdc++.h>
using namespace std;

int n;
double mp[10000],max_=-1;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",&mp[i]);
    }
    max_=mp[0];
    for(int i=1;i<n;i++){
        if(mp[i]<1) continue;
        for(int j=0;j<=i;j++){
            double m_res=1;
            int st=j,ed=i;
            for(int k=st;k<=ed;k++){
                m_res *= mp[k];
            }
            max_=max(max_,m_res);
        }
    }
    cout << max_ << endl ;
 
    return 0;
}