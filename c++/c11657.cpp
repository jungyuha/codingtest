#include <bits/stdc++.h>
using namespace std;
int n,m,a,b,c,dist[600];
const int INF = 987654321;

/*
첫째 줄에 도시의 개수 N (1 ≤ N ≤ 500), 버스 노선의 개수 M (1 ≤ M ≤ 6,000)이 주어진다.
둘째 줄부터 M개의 줄에는 버스 노선의 정보 A, B, C (1 ≤ A, B ≤ N, -10,000 ≤ C ≤ 10,000)가 주어진다. 
*/
int main(){
    bool res = true;
    cin >> n >> m;
    fill(dist,dist+n,INF);
    dist[0]=0; // 0번도시 ~
    vector<pair<int,int>> adj[600];
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1,c));
    }

for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(pair<int,int> el: adj[i]){
            int there=el.first; // 도착지
            int there_dist=el.second; // 거리
            if(dist[i]+there_dist<dist[there]){
                if(k==n-1) res = false;
                dist[there] = dist[i]+there_dist;
            }
        }
    }
}

if(!res){ cout << "-1" << endl;}
else{
    for(int i=1;i<n;i++){
        cout << dist[i] << endl;
    }
}

    return 0;
}