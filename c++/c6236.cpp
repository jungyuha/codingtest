#include <bits/stdc++.h>
using namespace std;

int n,m,mp[100000],start_=-1,end_,mid,res;

void go(int s , int e){
    //(1) 
    while (s<=e){
        mid = (s+e)/2;
        // (1)
        int temp = mid,m_cnt =1;
        for(int i=0;i<n;i++){
            // (2)
            if(temp-mp[i]<0){
                // (3)
                m_cnt++;
                temp = mid;
                i--;
            }
            else{
                temp -= mp[i];
            }
        }
        if(m_cnt == m) res = min(res,mid);
        if(m_cnt > m){
            s = mid +1;
        }
        else if(m_cnt <= m){ 
            e = mid -1;
        }
    }
}
int main(){
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> mp[i];
        end_ += mp[i]; start_ = max(start_,mp[i]);
    }
    go(start_,end_);

    cout << res << endl;
    return 0;
}