#include <bits/stdc++.h>
using namespace std;

int n,m,t,s,g,h,x[100],mp1[2010][2010],res_[2010];
vector<pair<int,int>> mp2[2010];
const int INF = 987654321;
queue<int> res_q;
void init(){
    int a,b,d;
    cin >> n >> m >> t;
    cin >> s >> g >> h;
    fill(res_,res_+2010,INF);
    res_[s]=0;
    for(int i=0;i<m;i++){
        cin >> a >> b >> d;
        mp1[a][b]=d; mp1[b][a]=d;
        mp2[a].push_back({b,d});mp2[b].push_back({a,d});
    }
    for(int i=0;i<t;i++){
        cin >> x[i] ;
    }
}
void make_mp(){
    queue<int> q1;
    q1.push(s);
    while(!q1.empty()){
        int here=q1.front();q1.pop();
        for(pair<int,int> el : mp2[here]){
            int to = el.first; int here_to_dist=el.second;
            if(res_[to] > res_[here]+here_to_dist){
                res_[to]= res_[here]+here_to_dist;
                q1.push(to);
            }
        }
    }
}
void reverse_make_mp(int end_){
    queue<pair<int,int>> q1;
    q1.push({end_,0});
    while(!q1.empty()){
        int here=q1.front().first;int res_m=q1.front().second; q1.pop();
        if(here == s && res_m==1 ){
            
            res_q.push(end_);
            return;
        }
        for(pair<int,int> el : mp2[here]){
            
            int to = el.first; int here_to_dist=el.second;
            if(res_[to] == res_[here]-here_to_dist){
                if((to==g && here==h)||(to==h && here==g)){ res_m = 1; }
                q1.push({to,res_m});
            }
        }
    } 
}
int main(){
    init();
    make_mp();
    // for(int i=1;i<=n;i++){
    //     cout << res_[i] <<" ";
    // }
    for(int i=0;i<t;i++){
        reverse_make_mp(x[i]);
    }
    while(!res_q.empty()){
        cout << res_q.front() << " ";
        res_q.pop();
    }
    return 0;
}