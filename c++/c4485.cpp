#include <bits/stdc++.h>
using namespace std;

int n,mp[130][130],res[130][130];
const int dx[4] ={0,1,0,-1};
const int dy[4] ={-1,0,1,0};
const int INF = 987654321;
struct Data{
    int y; int x;   // 위치
    int val;    // 도둑루피
};
struct cmp{
    bool operator()(Data &a , Data &b){
        return a.val < b.val;
    }
};
void init(){
    fill(&mp[0][0],&mp[0][0]+130*130,0);
    fill(&res[0][0],&res[0][0]+130*130,INF);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    res[0][0]=mp[0][0];
}
void make_dijkstra(){
    priority_queue <Data,vector<Data>,cmp> q1;
    Data d ; d.x=0; d.y=0; d.val=mp[0][0];
    q1.push(d);

    while(!q1.empty()){
        int cy = q1.top().y;
        int cx = q1.top().x;
        int val_ = q1.top().val;
        q1.pop();
        if(res[cy][cx]!=val_) continue;
        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
            if(res[ny][nx] > res[cy][cx]+mp[ny][nx]){
                res[ny][nx] = res[cy][cx]+mp[ny][nx];
                Data d1 ; d1.x=nx; d1.y=ny; d1.val=res[ny][nx];
                q1.push(d1);
            }
        }
    }
}
int main(){
    vector<int> res_;
    while(1){
        cin >> n;
        if(n==0) break;
        init();
        make_dijkstra();
        // cout << endl;
        // cout << res[n-1][n-1] <<" ";
        res_.push_back(res[n-1][n-1]);
    }
    for(int i=1;i<=res_.size();i++){
        cout << "Problem "<< i<<": "<<res_[i-1]<<endl;
    }

    return 0;
}