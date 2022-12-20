#include <bits/stdc++.h>
using namespace std;

int mp[50][50],v[50][50];
int air_y[2];
int w,h,t,tot;
const int dx[]={1,0,-1,0};
const int dy[]={0,-1,0,1};
queue <int> q1,q2;
const int dx_a[]={0,1,0,-1};
const int dy_a1[]={-1,0,1,0};
const int dy_a2[]={1,0,-1,0};
int main(){

    cin >> h >> w >> t;
    int idx=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> mp[i][j];
            if(mp[i][j]==-1){
                air_y[idx++]=i;
            }
        }
    }
    while(t){
    memset(v,0,sizeof(v));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mp[i][j] < 5) continue;
            v[i][j] = mp[i][j]/5;
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
                if(v[i][j] <= 0) continue;
                for(int k=0;k<4;k++){
                    int ny = i + dy[k]; int nx = j + dx[k];
                    if(nx<0||ny<0||nx>=w||ny>=h||mp[ny][nx]==-1) continue;
                    mp[ny][nx]+=v[i][j];
                    mp[i][j]-=v[i][j];
                }
            }
    }
    // 공기청정기
    int d1 = 0,d2=0 ,cx = 0, cy = air_y[0];
    while(1){
        int nx = cx + dx_a[d1]; int ny = cy + dy_a1[d1];
        if(nx == 0 && ny == air_y[0]) break;
        if(ny < 0 || nx >= w || ny > air_y[0]){
            d1 ++;
            nx = cx + dx_a[d1]; ny = cy + dy_a1[d1];
        }
        q1.push(mp[ny][nx]);
        cx = nx; cy = ny;
    }
    q1.pop(); q1.push(0);
    d1 = 0,d2=0 ,cx = 0, cy = air_y[0];
    while(1){
        int nx = cx + dx_a[d1]; int ny = cy + dy_a1[d1];
        if(nx == 0 && ny == air_y[0]) break;
        if(ny < 0 || nx >= w || ny > air_y[0]){
            d1 ++;
            nx = cx + dx_a[d1]; ny = cy + dy_a1[d1];
        }
        mp[ny][nx]=q1.front();
        q1.pop();
        cx = nx; cy = ny;
    }
        d1 = 0,d2=0 ,cx = 0, cy = air_y[1];
    while(1){
        int nx = cx + dx_a[d2]; int ny = cy + dy_a2[d2];
        if(nx == 0 && ny == air_y[1]) break;
        if(ny < air_y[1] || nx >= w || ny >= h){
            d2 ++;
            nx = cx + dx_a[d2]; ny = cy + dy_a2[d2];
        }
        q2.push(mp[ny][nx]);
        cx = nx; cy = ny;
    }
    q2.pop(); q2.push(0);

    d1 = 0,d2=0 ,cx = 0, cy = air_y[1];
    while(1){
        int nx = cx + dx_a[d2]; int ny = cy + dy_a2[d2];
        if(nx == 0 && ny == air_y[1]) break;
        if(ny < air_y[1] || nx >= w || ny >= h){
            d2 ++;
            nx = cx + dx_a[d2]; ny = cy + dy_a2[d2];
        }
        mp[ny][nx]=q2.front();
        q2.pop();
        cx = nx; cy = ny;
    }
        t--;
    }
    cout << tot << endl;
    return 0;
}