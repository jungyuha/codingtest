#include <bits/stdc++.h>
using namespace std;

int a,b; // a : 5 , b : 17
queue <pair<int,int>> q;
vector<int> res;
int level;

int main(){
    cin >> a >> b;
    q.push({0,a});
    int level = 999999;
    while(q.size()){
        if(q.front().first>level) break; 
        //cout <<"lvl:"<<q.front().first<<", q.front() : " << q.front().second <<",q.size():"<<q.size()<<"\n";
        if(q.front().second==b){
            if(res.size()==0) level = q.front().first;
            res.push_back(q.front().first);
        }
        
        for(int i=0;i<3;i++){
            if(i==0 && q.front().second>0){
                q.push({q.front().first+1,q.front().second-1});
            }
            else if(i==1 && q.front().second <= b){
                q.push({q.front().first+1,q.front().second+1});
            }
            else if(i==2 && q.front().second*2 -1 <= b){
                q.push({q.front().first+1,q.front().second*2});
            }
        }
        //cout <<"push q.size():"<<q.size()<<"\n";
        q.pop();
        //cout <<"pop q.size():"<<q.size()<<"\n";
    }
    cout << res.size();
   return 0;
}