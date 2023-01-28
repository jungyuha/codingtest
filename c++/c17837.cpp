#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,1,-1,0,0};
const int dy[]={0,0,0,-1,1};
bool res = false;
int n,k,d,mp[15][15],cnt;
int kLst[11][3];  // 말의 정보 kLst[1][0]=1;(1번말 이동방향 오른쪽) kLst[1][1]=2;(1번말 y축) kLst[1][2]=1;(1번말 x축)
vector<int> vis[15][15];// 말의 현황(지도) vis[1][2]={1}; 1행 2열에 1번말
// 지도 현황 보기
void showVis(){
    cout <<"현황==============" << endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(vis[i][j].size()>0){
                cout <<"("; for(int el :vis[i][j]){ cout <<el<<" "; }cout <<") ";
            }
            else{
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
//이동 가능 체크
bool moveCheck(int nx, int ny){
    if(nx<1 || ny <1 || nx > n || ny > n) {return false;}
    else return true;
}
int nextMove(int kIdx){
    int d = kLst[kIdx][0];// 방향
    int nx = kLst[kIdx][2]+dx[d];int ny = kLst[kIdx][1]+dy[d]; // 새로운 위치
    if(!moveCheck(nx,ny)){ return 2; }
    else { return mp[ny][nx]; }
}
void move0(int kIdx,int cy,int cx){   //흰색 , 말번호를 받음,말의 이동 전 위치
// 그 칸으로 이동한다.
//이동하려는 칸에 말이 이미 있는 경우에는 가장 위에 A번 말을 올려놓는다.
// A번 말의 위에 다른 말이 있는 경우에는 A번 말과 위에 있는 모든 말이 이동한다. 예를 들어, A, B, C로 쌓여있고, 이동하려는 칸에 D, E가 있는 경우에는 A번 말이 이동한 후에는 D, E, A, B, C가 된다
    int d = kLst[kIdx][0];// 방향
    int nx = cx+dx[d];int ny = cy+dy[d]; // 새로운 위치
    vector<int> prev;int idx;
    for(idx=0;idx<vis[cy][cx].size();idx++){ //현재 위치의 리스트 순회
        if(vis[cy][cx][idx]!=kIdx){
            prev.push_back(vis[cy][cx][idx]);
        }
        else { break; }
    }
    for(int i=idx;i<vis[cy][cx].size();i++){ //현재 위치의 리스트 순회
        vis[ny][nx].push_back(vis[cy][cx][i]);
        kLst[vis[cy][cx][i]][1]=ny; kLst[vis[cy][cx][i]][2]=nx;
    }
    vis[cy][cx]=prev;

    if(vis[cy][cx].size() >= 4 || vis[ny][nx].size() >= 4){
        res = true;
    }
}
void move1(int kIdx,int cy,int cx){   //빨강색 , 말번호를 받음,말의 이동 전 위치
// 이동한 후에 A번 말과 그 위에 있는 모든 말의 쌓여있는 순서를 반대로 바꾼다.
// A, B, C가 이동하고, 이동하려는 칸에 말이 없는 경우에는 C, B, A가 된다.
// A, D, F, G가 이동하고, 이동하려는 칸에 말이 E, C, B로 있는 경우에는 E, C, B, G, F, D, A가 된다.
    int d = kLst[kIdx][0];// 방향
    int nx = cx+dx[d];int ny = cy+dy[d]; // 새로운 위치
    for(int idx=vis[cy][cx].size()-1;idx>=0;idx--){ //현재 위치의 리스트 순회, 나 부터 바꾸는거임
        vis[ny][nx].push_back(vis[cy][cx][idx]);
        kLst[vis[cy][cx][idx]][1]=ny; kLst[vis[cy][cx][idx]][2]=nx;vis[cy][cx].pop_back();
        if(vis[cy][cx][idx]==kIdx) break;
    }

    if(vis[cy][cx].size() >= 4 || vis[ny][nx].size() >= 4){
        res = true;
    }
}
void move2(int kIdx,int cy,int cx){   //파랑색 , 말번호를 받음,말의 이동 전 위치
// A번 말의 이동 방향을 반대로 하고 한 칸 이동한다.
    int d = kLst[kIdx][0];// 방향
    if(d==1){kLst[kIdx][0]=2;} else if(d==2){kLst[kIdx][0]=1;} else if(d==3){kLst[kIdx][0]=4;} else if(d==4){kLst[kIdx][0]=3;};
    d = kLst[kIdx][0];
    int nx = cx+dx[d];int ny = cy+dy[d]; // 새로운 위치
// 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히 있는다.
//체스판을 벗어나는 경우에는 파란색과 같은 경우이다.
    if(mp[ny][nx]==2||!moveCheck(nx,ny)) {return ;}
    else{
        int b=nextMove(kIdx);
        //showVis();
        if(b==0){move0(kIdx,kLst[kIdx][1],kLst[kIdx][2]);}
        else if(b==1){move1(kIdx,kLst[kIdx][1],kLst[kIdx][2]);}
        //showVis();
    }

}
int main(){

    cin >> n >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> mp[i][j];
        }
    }
    int y,x,c;
    for(int i=1;i<=k;i++){
        cin >> y >> x >> c;
        vis[y][x].push_back(i); kLst[i][0]=c;
        kLst[i][1]=y; kLst[i][2]=x;
    }
    while(cnt<1000 && !res){
        cnt++;
        for(int i=1;i<=k;i++){
            int b=nextMove(i);
            //showVis();
            if(b==0){move0(i,kLst[i][1],kLst[i][2]);}
            else if(b==1){move1(i,kLst[i][1],kLst[i][2]);}
            else if(b==2){move2(i,kLst[i][1],kLst[i][2]);}
            //showVis();
        }
    }
    if (res){
        cout << cnt << endl;
    }
    else{
        cout << "-1" << endl;
    }

    return 0;
}