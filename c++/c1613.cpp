#include <bits/stdc++.h>
using namespace std;

int n,k,s,mp[410][410];
vector<pair<int,int>> adj[410];
vector<int> res[410];
void init(){
    cin >> n >> k;
    int from,to;
    for(int i=1;i<=k;i++){
        cin >> from >> to;
        adj[from].push_back({to,1});
    }
}
void make_mp(){
    for(int i=1;i<=n;i++){
        queue <int> q1;
        q1.push(i);    
        while(!q1.empty()){
            int cur = q1.front();q1.pop();
            for(pair<int,int> el : adj[cur]){
                mp[i][el.first]=1;
                res[i].push_back(el.first);
                q1.push(el.first);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout << i <<" : " ;
    //     for(int j=1;j<=n;j++){
    //         if(mp[i][j] == 1) cout << j <<",";
    //     }
    //     cout << endl;
    // }
}
int main(){
    init();
    make_mp();
    cin >> s; int a,b,res; queue<int> q;
    for(int i=0;i<s;i++){
        cin >> a >> b;
        if(mp[a][b]==1){res=-1;}
        else if(mp[b][a]==1){res=1;}
        else{res=0;}
        q.push(res);
    }
    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}