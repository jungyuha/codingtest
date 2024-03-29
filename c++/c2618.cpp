#include <bits/stdc++.h>
using namespace std;

int n,w;
vector<pair<int,int>> lst; // 행 열 
pair<int,int> cp[2];
vector<int> res;
int tot;
int main(){
    cin >> n >> w;
    int a,b;
    for(int i=0;i<w;i++){
        cin >> a >> b;
        lst.push_back({a,b});
    }
    cp[0].first=1;cp[0].second=1;
    cp[1].first=n;cp[1].second=n;

    for(pair<int,int> el : lst){
        //1. 각 경찰차로부터의 거리 계산
        int d1 = abs(el.first-cp[0].first)+abs(el.second-cp[0].second);
        int d2 = abs(el.first-cp[1].first)+abs(el.second-cp[1].second);

        if(d1 <= d2){
            res.push_back(1);
            cp[0].first=el.first;cp[0].second=el.second;
            tot+=d1;
        }
        else{
            res.push_back(2);
            cp[1].first=el.first;cp[1].second=el.second;
            tot+=d2;
        }
    }
    cout << tot << endl;
    for(int el : res){
        cout << el << endl;
    }
    return 0;
}