#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
vector<vector<char>> mp1;
int a,b,min_=INF;
bool resYn = false;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};

void func1(int cy,int cx, int fy,int fx , int s){
    if(mp1[cy][cx]!='#' && (cx==0||cx==b-1||cy==0||cy==a-1)){
        if(min_>s) min_ = s+1;
        resYn = true;
        return ;
    } 
    for(int i=0;i<4;i++){
        int nfx = fx + dx[i];
        int nfy = fy + dy[i];
        if(nfx<0||nfx>=b||nfy<0||nfy>=a||mp1[nfy][nfx]=='#'||mp1[nfy][nfx]=='F'||mp1[nfy][nfx]=='J') continue;
        mp1[nfy][nfx] = 'F';
cout << s << " :F 번짐  22 \n";
for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
        cout << mp1[i][j];
    }
    cout << "\n";
}
            for(int j=0;j<4;j++){
                int nx = cx + dx[j];
                int ny = cy + dy[j];
                if(nx<0 || ny<0 || nx >= b || ny >= a ||(mp1[ny][nx]=='F')||mp1[ny][nx]=='#') continue;
                mp1[cy][cx]='.';
                mp1[ny][nx]='J';
cout << s <<":" <<cy <<","<<cx <<"=>" <<ny <<","<<nx << " :F번지고 다시 J이동 시작 33 \n";
for(int i=0;i<a;i++){
for(int j=0;j<b;j++){
    cout << mp1[i][j];
}
cout << "\n";
}
                func1(ny,nx,nfy,nfx,s+1);
                mp1[cy][cx]='J';
                mp1[ny][nx]='.';
            }
        mp1[nfy][nfx] = '.';
    }
}
int main(){
    cin >> a >> b ;
    int cx=INF, cy =INF ,fx = INF,fy =INF;
    for(int i=0;i<a;i++){
        vector<char> vc;
        for(int j=0;j<b;j++){
            char c;
            cin >> c;
            vc.push_back(c);
            if(c == 'J') {cy = i; cx = j; }
            if(c == 'F') {fy = i; fx = j;}
        }
        mp1.push_back(vc);
    }
    func1(cy,cx,fy,fx,0);
    cout <<"end :" << min_;
 
    return 0;
}