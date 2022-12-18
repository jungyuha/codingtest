#include <bits/stdc++.h>
using namespace std;

int a,d,c,res;
vector<pair<int,int>> lst;
priority_queue<int,vector<int>,greater<int>> pq; 
int main(){
    cin >> a; 
    for(int i=0;i<a;i++){
        cin >> d >> c ;
        lst.push_back({d,c});
    }
    sort(lst.begin(),lst.end());
    // (1)
    for(int i=0;i<a;i++){
        pq.push(lst[i].second);
        res+=lst[i].second;
        //(2)
        if(pq.size()>lst[i].first){
            res-=pq.top(); pq.pop();
             //(3)
        }
    }
    cout <<res<< endl ;             
    return 0;
}