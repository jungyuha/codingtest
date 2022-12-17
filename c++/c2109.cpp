#include <bits/stdc++.h>
using namespace std;

int a,v,d,max_d,res;
vector<pair<int,int>>lst;
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> v >> d;
        lst.push_back({d,v});
        max_d=max(max_d,d);
    }
    sort(lst.begin(),lst.end());
    // (1)
    for(int dd=1;dd<=max_d;dd++){
        int midx=-1,max_=-1;
        for(int j=0;j<a;j++){
            // (2)
            if(lst[j].second==-1 || dd>lst[j].first) continue;
            if(dd<lst[j].first) break;
            if(lst[j].second>max_){
                max_=lst[j].second;
                midx=j;
                // (3)
            }
        }
        // (4)
        if(midx>-1){
            res+=max_;
            lst[midx].second=-1;
        }
    }
    cout << "res:"<<res;
    return 0;
}