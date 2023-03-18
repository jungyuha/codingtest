#include <bits/stdc++.h>
using namespace std;

int n,m,s,d,res[510],res_sec[510];
const int INF = 987654321;
queue <int> q;
vector<pair<int,int>> mp1[510];
bool init(){

    fill(res,res+510,INF);fill(res_sec,res_sec+510,INF);

    cin >> n >> m;
    if(n==0 && m==0) return false;
    cin >> s >> d;
    res[s]=0;

    int u,v,p;
    for(int i=0;i<m;i++){
        cin >> u >> v >> p;
        mp1[u].push_back({v,p});
        if(u==s) {res[v]=p; q.push(v);}

    }
    return true;
}
void make_mp(){
    
    int i=1;
    while(!q.empty()){
        //cout << i << endl; i++;
        int cur = q.front();q.pop();
        for(pair<int,int> el : mp1[cur]){
            cout << el.first << "," << el.second;
            cout << ", cur :"<<cur << ",";
            int aa = res[cur];  cout << "aa : " << res[cur] << ", ";
            int aa2 = res[el.first]; cout << "aa2 : " << res[el.first] << ", ";
            int aa3 = el.second; cout << "aa3 : " << el.second << endl;

            if(aa+aa3<aa2){
                cout << "hi:"<<aa+aa3<<","<<aa2<<":"<<el.first<<endl;
                res_sec[el.first]=res[el.first];
                res[el.first]=aa+aa3;
                q.push(el.first);
            }
        }
    }

}
int main(){

    init();
    make_mp();

    for(int i=0;i<510;i++){
        if(res[i]!=INF) cout << "res["<<i<<"] : "<< res[i] << endl;
    }
    return 0;
}

/*
입력은 여러 개의 테스트 케이스로 이루어져 있다. 각 테스트 케이스의 첫째 줄에는 장소의 수 N (2 ≤ N ≤ 500)과 도로의 수 M (1 ≤ M ≤ 104)가 주어진다. 장소는 0부터 N-1번까지 번호가 매겨져 있다.
둘째 줄에는 시작점 S와 도착점 D가 주어진다. (S ≠ D; 0 ≤ S, D < N) 다음 M개 줄에는 도로의 정보 U, V, P가 주어진다.
(U ≠ V ; 0 ≤ U, V < N; 1 ≤ P ≤ 103) 이 뜻은 U에서 V로 가는 도로의 길이가 P라는 뜻이다. U에서 V로 가는 도로는 최대 한 개이다. 또, U에서 V로 가는 도로와 V에서 U로 가는 도로는 다른 도로이다. 
입력의 마지막 줄에는 0이 두 개 주어진다
*/