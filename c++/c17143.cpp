#include <bits/stdc++.h>
using namespace std;
struct shark{
    int r,c,s,d,z,m;
}sh[10001];
int mp[101][101];
int h,w,m,res;
const int dx[]={0,0,0,1,-1};
const int dy[]={0,-1,1,0,0};
vector<shark> _change;

void del(){
    memset(mp,0,sizeof(mp));
    // 상어 잡아먹힘
    while(!_change.empty()){
        int ny = _change.back().r; int nx = _change.back().c;
        if(mp[ny][nx]>0){ // 1명은 잡아먹힘
            int index1 = _change.back().m;
            int index2 = mp[ny][nx];
            if(sh[index2].z < sh[index1].z){
                mp[ny][nx] = index1;
            }
        }
        else{
            mp[ny][nx] = _change.back().m;
        }
        _change.pop_back();
    }
}
void move(int index){
    // 상어 이동 테스트
    int ny = sh[index].r; int nx = sh[index].c;
    // (2-1)
    for(int i=0;i<sh[index].s;i++){
        if(nx + dx[sh[index].d]<=0 || nx + dx[sh[index].d] > w ) {
            sh[index].d = (7-sh[index].d);
        }
        if(ny + dy[sh[index].d] <=0 || ny + dy[sh[index].d] > h){
            sh[index].d = (3-sh[index].d);
        }
       nx += dx[sh[index].d]; ny += dy[sh[index].d];
    }
    // (2-2)
    sh[index].r=ny ; sh[index].c=nx;sh[index].m=index;
    _change.push_back(sh[index]);
}
int main(){
    cin >> h >> w >> m;
    for(int i=1;i<=m;i++){
        cin >> sh[i].r >> sh[i].c >> sh[i].s >> sh[i].d >> sh[i].z;
        mp[sh[i].r][sh[i].c]=i;
    }
    // (1)
    for(int i=1;i<=w;i++){ // 인간 이동
        // 가로 1칸 이동
        for(int j=1;j<=h;j++){
            if(mp[j][i]>0){
                res += sh[mp[j][i]].z;
                mp[j][i]=0;
                break;
            }
        }
        //상어 이동
        for(int a=1;a<=h;a++){
            for(int b=1;b<=w;b++){
                if(mp[a][b]>0){
                    move(mp[a][b]);
                }
            }
        }
        del();
    // (1)      
    }
    cout << res << endl;
    return 0;
}