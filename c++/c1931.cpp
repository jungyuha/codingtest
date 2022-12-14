#include <bits/stdc++.h>
using namespace std;
int a,res,pre_end;
vector<pair<int,int>> hLst;
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        int from,to;
        cin >> from >> to;
        hLst.push_back({to,from});
    }
    sort(hLst.begin(),hLst.end());

    for(int i=0;i<a;i++){ // (2)
        if(pre_end > hLst[i].second) continue;
        pre_end = hLst[i].first;
        res++;
    }
    cout <<res<<"\n";
    return 0;
}