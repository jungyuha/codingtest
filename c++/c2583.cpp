/*
5 7 3
0 2 4 4
1 1 2 5
4 0 6 2
*/
#include <bits/stdc++.h>
using namespace std;

int a,b,c,res,sum;
// a : y높이 , b : x너비 , c : 직사각형 총개수  , res : 결과값 , sum : 각 넓이
int mp[100][100];
int visited[100][100];
vector<int> sumList; // 각 넓이
const int dx[] = {0,1,0,-1};
const int dy[] = {-1,0,1,0};

void dfs(int cx , int cy){
    // cx , cy : 현재 위치
    visited[cy][cx] =1;
    sum +=1;
    int nx,ny;
    for(int i =0;i<4;i++){
        // 범위 , 방문 현황 체크
        ny = cy + dy[i];
        nx = cx + dx[i];
        if(nx < 0 || ny < 0 || nx >= b || ny >= a || visited[ny][nx] == 1) continue;
        dfs(nx,ny);
    }
}
int main(){
    cin >> a >> b >> c;

    for(int i =0;i<c;i++){
        int x1,x2,y1,y2;

        cin >> x1 >> y1;
        cin >> x2 >> y2;

        for(int j=y1;j<y2;j++){
            for(int k=x1;k<x2;k++){
                mp[j][k]=1;
                visited[j][k]=1;
            }
        }
    }
    
    for(int i = 0 ;i <a ; i++){
        for(int j = 0;j<b;j++){
            if(visited[i][j]!=0) continue;
            dfs(j,i);
            res ++;
            sumList.push_back(sum);
            sum = 0;
        }
    }
    sort(sumList.begin(),sumList.end());
    cout << res << "\n";
    for(int el : sumList){
        cout << el << " ";
    }
    return 0;
}