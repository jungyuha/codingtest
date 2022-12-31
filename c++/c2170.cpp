#include <bits/stdc++.h>
using namespace std;

int a,end_=-1,res;
vector<pair<int,int>> lst;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
int main(){

    cin >> a;

    for(int i=0;i<a;i++){
        int b,c;
        cin >> b >> c;
        pq.push({b,c});
    }
    while(!pq.empty()){
        if(pq.top().first <= end_){
            if(pq.top().second > end_){
                lst.back().second = pq.top().second;
            }
        }
        else{
            lst.push_back({pq.top().first,pq.top().second});
            end_ = pq.top().second;
        }
        pq.pop();
    }
    // while(!pq.empty()){
    //     cout << "(" <<  pq.top().first << "," << pq.top().second <<") ";
    //     pq.pop();
    // }
    // cout << endl;

    for(int i=0;i<lst.size();i++){
        //cout << "(" <<  lst[i].first << "," << lst[i].second <<") ";
        res+=(lst[i].second-lst[i].first);
    }
    cout << res << endl;
    return 0;
}