
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n,m,mp[4010][4010],res1[4010],vis[4010];
double res2[4010];
vector<int> adj[4010];
void init(){
    cin >> n >> m;
    int a,b,d;
    fill(res1,res1+4010,INF);fill(res2,res2+4010,INF);
    //memset(dp,-1,sizeof(dp));
    res1[1]=0; res2[1]=0;
    for(int i=0;i<m;i++){
        cin >> a >> b >> d;
        mp[a][b]=d;mp[b][a]=d;
        adj[a].push_back(b);adj[b].push_back(a);
    }
}
void make_map_fox(){
    queue<int> q1;
    q1.push(1);
    int st=1;
    while(!q1.empty()){
        int cur = q1.front();q1.pop();
        for(int el : adj[cur]){
            int to = el;
            if(res1[cur]+mp[cur][to]<res1[to]){
                res1[to] = res1[cur]+mp[cur][to];
                q1.push(to);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout << res1[i] << " ";
    }
    cout << endl;
}
int dfs_map_wolf(int before,int cur_,int end_,int flag,double res){
    cout<< before << " , " << cur_ << " , "<< end_ << " , "<< flag << " , "<< res << " \n ";
    
    if(cur_==end_){
        return res;
    }

    int new_res = INF;
    double cur_val = pow(2,flag);
    for(int el : adj[cur_]){
        int to = el;
        if(vis[to]==1) continue;
        vis[to]=1;
        new_res= min(new_res,dfs_map_wolf(cur_,to,end_,(-1)*flag,res+(cur_val*(double)mp[cur_][to])));
        vis[to]=0;
    }
    return new_res;
}
int main(){
    init();
    vis[1]=1;
    for(int i=1;i<=n;i++){
        res2[i]=dfs_map_wolf(0,1,i,-1,0);
    }
    for(int i=1;i<=n;i++){
        cout << res1[i] << "," << res2[i] << endl;
    }
}
/*
5 6
1 2 3
1 3 2
2 3 2
2 4 4
3 5 4
4 5 3
*/