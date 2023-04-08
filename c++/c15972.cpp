
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n,m,h,val_[1010][1010];
vector<pair<int,int>> hor[1010],ver[1010]; // 구멍 정보
vector<tuple<int,int,int>> adj[1010][1010];
priority_queue <pair<int,int>> q1; // 높이가 바뀐 칸 (행 , 열) 
void init(){
    cin >> n >> m >> h; //2 3 5
   //fill(val_,val_+1010*1010,h);

   int a;
    for(int i=0;i<=n;i++){ // 가로줄
        for(int j=0;j<m;j++){ //세로칸
            cin >> a;
            if(a==-1) continue;
            hor[i].push_back({j,a});
            q1.push({i,j}); // 행 , 열
            if(i-1 >= 0) q1.push({i-1,j}); // 행 , 열
        }
    }
    for(int i=0;i<n;i++){ // 가로칸
        for(int j=0;j<=m;j++){ // 세로줄
            cin >> a;
            if(a==-1) continue;
            ver[j].push_back({i,a});
            q1.push({i,j});
            if(j-1 >= 0) q1.push({i,j-1});
        }
    }

    for(int i=0;i<=n;i++){ // 가로줄
        cout <<"----------가로줄 정보---------- :: "<< i << endl;
        for(pair<int,int> el : hor[i]){
            cout <<"    "<<i<<"번째 가로줄 : "<< el.first << "열 => " << el.second <<endl;
        }
    }
    for(int i=0;i<=m;i++){  // 세로줄
        cout <<"----------세로줄 정보---------- :: "<< i << endl;
        for(pair<int,int> el : ver[i]){
            cout <<"    "<<i<<"번째 세로줄 : "<< el.first << "행 => " << el.second <<endl;
        }        
    }
}
int main(){
    init();
    
}