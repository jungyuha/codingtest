#include <bits/stdc++.h>
using namespace std;

priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
int mp[100][100];
int vis[100][100];
int a,b,c,tot,dx,dy;
int cx,cy ; // 뱀의 머리 위치
queue<pair<int,int>> sn; // 뱀의 몸
int main(){
    cin >> a >> b;
// (1)
    for(int i=0;i<b;i++){
        int y,x;
        cin >>y >> x;
        mp[y-1][x-1]=1; // 사과
    }
    cin >> c;
    for(int i=0;i<c;i++){
        int d; char cc;
        cin >> d >>cc;
        pq.push({d,cc});
    }
    // (2)
    sn.push({0,0});
    dx=1;
    while(tot<=(a*a)){
        tot++;
        cx=cx+dx; cy =cy+dy;
        if(cx>=a||cy>=a||cx<0||cy<0||vis[cy][cx]==1) {
            // (3) 
            break;
        }
        sn.push({cy,cx});
        // (4)
        vis[cy][cx]=1;
        if(mp[cy][cx]!=1){
            vis[sn.front().first][sn.front().second]=0;
            // (5)
            sn.pop();
        }
        if(tot==pq.top().first){
            // (6) 
            if(pq.top().second=='L'){
                if(dx==1){
                    dx=0;dy=-1;
                }
                else if(dy==1){
                    dx=1;dy=0;
                }
                else if(dx==-1){
                    dx=0;dy=1;
                }
                else if(dy==-1){
                    dx=-1;dy=0;
                }
            }
            else if(pq.top().second=='D'){
                if(dx==1){
                    dx=0;dy=1;
                }
                else if(dy==1){
                    dx=-1;dy=0;
                }
                else if(dx==-1){
                    dx=0;dy=-1;
                }
                else if(dy==-1){
                    dx=1;dy=0;
                }                
            }
             //(7) 
            pq.pop();
        }
    }
    cout <<tot<<endl;
}