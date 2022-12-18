#include <bits/stdc++.h>
using namespace std;

int a,d,t,res;
vector<pair<int,int>> lst;
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        cin >> d >> t;
        lst.push_back({d,t});
    }
    sort(lst.begin(),lst.end());
    for(int i=0;i<a;i++){
        int start=lst[i].first;
        if(lst[i].first<=res){
            start=res;
        }
        res=start+lst[i].second;
        //(1)
        cout << "start :"<<start <<"res : "<<res <<endl;
    }
    cout << res << endl;
    return 0;
}