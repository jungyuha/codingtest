#include <bits/stdc++.h>
using namespace std;

const int dx[]={1,1,0};
const int dy[]={0,1,1};
int n,mp[16][16];
int go(int here){
    cout << "cx : "<<here/10 <<",cy :"<<here -(here/10)*10<< endl;
    return 0;
}
int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    int cx =1,cy=0,sp=0;
    for(int i=0;i<3;i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx>=n || ny >= n) continue;
        sp = 10*nx + ny;
        go(sp);
    }
    return 0;
}