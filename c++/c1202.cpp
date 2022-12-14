#include <bits/stdc++.h>
using namespace std;

int a,b,res;
vector<pair<int,int>> aLst; // 보석
vector<int> bLst; // 가방
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        int w,v;
        cin >> w >> v;
        aLst.push_back({w,v});
    }
    for(int i=0;i<b;i++){
        int w;
        cin >> w ;
        bLst.push_back(w);
    }
    sort(bLst.begin(),bLst.end());
    sort(aLst.begin(),aLst.end());
    // (1)
    for(int i=0;i<b;i++){
        // (2) 
        int max_=0,max_index=-1;
        for(int j=0;j<a;j++){
             // (3)
            if(aLst[j].first>bLst[i]) break;
             // (4) 
            if(aLst[j].second <0) continue;
            // (5)
            if(aLst[j].second > max_){
                max_ = aLst[j].second;
                max_index = j;
            }
        }
        // (6)
        if(max_index>-1) {
            aLst[max_index].second =-1;
            // (7)
            }
        res+=max_;
    }
    cout <<res<<"\n";
    return 0;
}