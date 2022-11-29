#include <bits/stdc++.h>
using namespace std;

int a;
int mp1[10][10]; // 꽃밭
int vis[10][10]; // 방문체크
vector<tuple<int,int,int>> fl ; // 가능한 꽃 리스트 {y,x,비용}
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int result = -1;
bool cmp(tuple<int,int,int> a ,tuple<int,int,int> b){
    return get<2>(a) < get<2>(b);
}
void comb(int start,int level,int res){
    if(level==3){
        if(result==-1) result = res;
        return ;
    }
    if(result)
    for(int i=start;i<fl.size();i++){
        bool visYn = false;
        if(vis[get<0>(fl[i])][get<1>(fl[i])]==1) continue;
        for(int a=0;a<4;a++){
            int nx = get<1>(fl[i]) + dx[a];
            int ny = get<0>(fl[i]) + dy[a];
            if(vis[ny][nx]==1) {
                visYn = true;
                break;
            }
        }
        if(visYn) continue;
        vis[get<0>(fl[i])][get<1>(fl[i])]=1;
        for(int a=0;a<4;a++){
            int nx = get<1>(fl[i]) + dx[a];
            int ny = get<0>(fl[i]) + dy[a];
            vis[ny][nx]=1;
        }
        comb(start+1,level+1,res+get<2>(fl[i]));
        vis[get<0>(fl[i])][get<1>(fl[i])]=0;
        for(int a=0;a<4;a++){
            int nx = get<1>(fl[i]) + dx[a];
            int ny = get<0>(fl[i]) + dy[a];
            vis[ny][nx]=0;
        }
        if(result >0) return;
    }
}
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> mp1[i][j];
        }
    }
    for(int i=1;i<a-1;i++){
        for(int j=1;j<a-1;j++){
            int width=mp1[i][j];
            for(int k=0;k<4;k++){
                int ny = i + dy[k];
                int nx = j + dx[k];
                width +=mp1[ny][nx];
            }
            fl.push_back(make_tuple(i,j,width));
        }
    }
    sort(fl.begin(),fl.end(),cmp);
    comb(0,0,0);

    cout << result ;
    return 0;
}

/*
*) 출력
1. mp1
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout << mp1[i][j];
        }
        cout <<"\n";
    }
2. 꽃봉우리
for(int i=1;i<a-1;i++){
        for(int j=1;j<a-1;j++){
            cout << mp1[i][j];
        }
        cout <<"\n";
    }
3. 후보군
cout <<"fl.sise() : "<< fl.size()<<"\n";
for(int i=0;i<fl.size();i++){
        cout << "x : "<<get<0>(fl[i])<<",y:"<<get<1>(fl[i])<<",width:"<<get<2>(fl[i])<<"\n";
    }
*/