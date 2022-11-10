#include <bits/stdc++.h>
using namespace std;

int n,m,c,a;
vector<pair<int,int>> cList;
vector<pair<int,int>> nextList;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int mp[100][100];
int pre_deleted[100][100];
int main(){

    cin >> n >> m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> c;
            if(c==1) cList.push_back({i,j});
            mp[i][j] = c;
        }
    }

    /*
6 5
0 0 0 0 0
0 1 1 0 0
0 0 1 1 0
0 1 1 1 0
0 1 1 1 0
0 0 0 0 0
    */
    vector<int> cntList; // cnt : 가생이수 , a: 남아잇는 애들
    int res;
    //1개의 맵
    int tot = cList.size();
    a = tot;
    while(a>0){
    int cnt=0;
    for(int j = 0 ;j< tot;j++){ // 1칸
        int x,y;
        bool side = false;
//        cout << "y : " << cList[j].first << ", x : " << cList[j].second <<"\n";
        for(int i=0;i<4;i++){
            y = cList[j].first+dy[i];
            x = cList[j].second+dx[i];
            if(y<0 || y>=100 || x<0 || x>=100 || pre_deleted[cList[j].first][cList[j].second] == 1) continue;
            if(mp[y][x]==0 || pre_deleted[y][x] == 1) {
                // cout << "mp[y][x] : " << mp[y][x]  << "\n"; 
                // cout << "deleted[y][x] : " <<pre_deleted[y][x]  << "\n"; 
                cnt ++;
                nextList.push_back({cList[j].first,cList[j].second});
                // cout << "0 => y : " << cList[j].first << ", x : " << cList[j].second <<" cnt : "<< cnt << "\n";             
                break;
                }
        }
    }
     cout << "cnt : "<<cnt ;
     cout << "a : "<<a-cnt << "\n";
    cntList.push_back(cnt);
    a=a-cnt;
    while(!nextList.empty()){
        pre_deleted[nextList.back().first][nextList.back().second] = 1 ;
        nextList.pop_back();
    }
    for(int i =0;i<15;i++){
        for(int j=0;j<15;j++){
            cout<<pre_deleted[i][j] << " ";
        }
        cout << "\n";
    }
   // 맵 순회 끝
    }
    cout << cntList.size() << "\n";
    //cout << aList.back() << "\n";
    }