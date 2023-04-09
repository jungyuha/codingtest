
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n,m,h;
vector<pair<int,int>> hor[1010],ver[1010]; // 구멍 정보
int adj[1010][1010][4];
int val_[1010][1010];
queue <pair<int,int>> q1; // 높이가 바뀐 칸 (행 , 열) 
void init(){
    cin >> n >> m >> h; //2 3 5

   int a;
    for(int i=0;i<=n;i++){ // 가로줄
        for(int j=0;j<m;j++){ //세로칸
            cin >> a;
            if(a==-1) continue;
            hor[i].push_back({j,a});
            q1.push({i,j}); // 행 , 열
            adj[i][j][0]=a;
            if(i-1 >= 0) { 
                q1.push({i-1,j}); // 행 , 열
                adj[i-1][j][2]=a;
            }
        }
    }
    for(int i=0;i<n;i++){ // 가로칸
        for(int j=0;j<=m;j++){ // 세로줄
            cin >> a;
            if(a==-1) continue;
            ver[j].push_back({i,a});
            q1.push({i,j});
            adj[i][j][3]=a;
            if(j-1 >= 0) { q1.push({i,j-1}); adj[i][j-1][1]=a;}
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            val_[i][j]=h;
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
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout <<i<<"행 "<< j << "열 => " << adj[i][j][0] << ", " <<adj[i][j][1] << ", " <<adj[i][j][2] << ", " <<adj[i][j][3]<< endl;
        }
    }
}
int main(){
    init();
    while(!q1.empty()){
        int cy = q1.front().first; int cx = q1.front().second;
        q1.pop();
        for(int k=0;k<4;k++){
            int d = adj[cy][cx][k];
            if(d == 0) continue;
        }
    }
}