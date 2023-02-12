#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int d[20001];
int v,e,k;
vector<pair<int,int>> adj[20001];
priority_queue <pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // <출발점 ~ 정점까지의 거리,정점번호>
int main(){
    fill(d,d+20000,INF);
    cin >> v >> e >> k;
    d[k]=0;
    pq.push(make_pair(0,k));
    int a,b,c;
    for(int i=1;i<=e;i++){
        cin >> a >> b >> c; // 출발점 : a , 도착점 : b, 거리 : c
        adj[a].push_back(make_pair(c,b)); //ajd[출발점]=(도착점,거리)
    }
   // pq[(0,1)]
    // 거리 : 0  점 : 1
    while(!pq.empty()){
        int here_dist=pq.top().first; // 출발점 ~ 정점까지의 거리
        int here=pq.top().second; // 해당 정점
        pq.pop();
        if(here_dist != d[here]) continue;
        for(int i=0;i<adj[here].size();i++){ // here : 1,there : 2 , 3
            int there = adj[here][i].second; // 연결된 다음 정점
            int there_dist = adj[here][i].first; // 해당정점 ~ 다음 정점까지의 거리 ( here ~ there )
            // 정점까지의 거리가 지금 계산한 거리보다 더 크면 새로운 값(더 작은 값)으로 갱신한다.
            if(there_dist+here_dist < d[there]){
                d[there] = there_dist+here_dist;
                pq.push(make_pair(d[there],there));
            }
        }
    }

    for(int i=1;i<=v;i++){
        cout << d[i] << ",";
    }
    cout << endl;
    return 0;
    

}
