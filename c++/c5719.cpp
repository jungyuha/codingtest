#include <bits/stdc++.h>
using namespace std;

int n,m,s,d,res[510];
const int INF = 987654321;
int mp1[510][510];
queue<int> res_q;
bool init(){
    fill(&mp1[0][0],&mp1[0][0]+510*510,-1);
    cin >> n >> m;
    if(n==0 && m==0) return false;
    cin >> s >> d;
    
    int u,v,p;
    for(int i=0;i<m;i++){
        cin >> u >> v >> p;
        mp1[u][v]=p;
    }
    return true;
} 
void make_mp(){
    queue <int> q;
    fill(res,res+510,INF);
    res[s]=0;
    q.push(s);
    while(!q.empty()){
        int cur = q.front();q.pop();
        for(int i=0;i<n;i++){
            if(mp1[cur][i]==-1) continue;
            int a_to_b = res[cur];
            int a_to_c = res[i];
            int b_to_c = mp1[cur][i];
            if(a_to_b + b_to_c <= a_to_c){
                res[i] = a_to_b + b_to_c;
                q.push(i);
            }
        }
    }
}
void erase_edge(int end_){
    queue <int> q2;
    q2.push(end_);
    
    while(!q2.empty()){
        int end_m=q2.front();q2.pop();
        for(int i=0;i<n;i++){
            if(res[i]+mp1[i][end_m] == res[end_m] && mp1[i][end_m]!=-1){
                mp1[i][end_m]=-1;
                q2.push(i);
            }
        }
    }
}
int main(){
    while(init()){
        make_mp();
        erase_edge(d);
        make_mp();

        if(res[d]==INF) { res_q.push(-1); }
        else{ res_q.push(res[d]); }
    }
    
    while(!res_q.empty()){
        cout << res_q.front() << endl;
        res_q.pop();
    }
    return 0;
}
