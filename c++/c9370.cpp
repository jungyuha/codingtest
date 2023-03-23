#include <bits/stdc++.h>
using namespace std;

int n,m,t,s,g,h,x[100],mp1[2010][2010],res_[2010];
vector<pair<int,int>> mp2[2010];
void init(){
    int a,b,d;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    for(int i=0;i<m;i++){
        cin >> a >> b >> d;
        mp1[a][b]=d; mp1[b][a]=d;
        mp2[a].push_back({b,d});mp2[b].push_back({a,d});
    }
    for(int i=0;i<t;i++){
        cin >> x[t];
    }
}
void make_mp(){
    queue<int> q1;
    q1.push(s);
    while(!q1.empty()){
        int here=q1.front();q1.pop();
        for(pair<int,int> el : mp2[here]){
            int to = el.first; int here_to_dist=el.second;
            if()
        }
    }
}
void reverse_make_mp(int end_){

}
int main(){

    return 0;
}
