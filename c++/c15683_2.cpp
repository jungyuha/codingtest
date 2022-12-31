#include <bits/stdc++.h>
using namespace std;

int w,h,mp[10][10],res=987654321;
vector<pair<int,int>> v1;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
vector<pair<int,int>> func2 (int cy,int cx,int di){
    // (1) 
    vector<pair<int,int>> _change;
    if(mp[cy][cx]==1){
        int nx = cx + dx[di];int ny = cy + dy[di];
        while(nx>=0 && nx < w && ny >=0 && ny < h && mp[ny][nx] != 6){
            if(mp[ny][nx]==0){
                mp[ny][nx]=9; 
                _change.push_back({ny,nx});
            }
            nx+=dx[di];ny+=dy[di];
        }
    }
    else if(mp[cy][cx]==2){
        for(int i=0;i<4;i+=2){
            int nx = cx+dx[(i+di)%4]; int ny=cy+dy[(i+di)%4];
            // 2. CCTV 처리
            while(nx>=0 && nx < w && ny >=0 && ny < h && mp[ny][nx] != 6){
                if(mp[ny][nx]==0){
                    mp[ny][nx]=9; 
                    _change.push_back({ny,nx});
                }
                nx += dx[(i+di)%4]; ny += dy[(i+di)%4];
            }
        }
    }
    else if(mp[cy][cx]==3){
        for(int i=0;i<2;i++){
            int nx = cx+dx[(i+di)%4]; int ny=cy+dy[(i+di)%4];
            // 2. CCTV 처리
            while(nx>=0 && nx < w && ny >=0 && ny < h && mp[ny][nx] != 6){
                if(mp[ny][nx]==0){
                    mp[ny][nx]=9; 
                    _change.push_back({ny,nx});
                }
                nx += dx[(i+di)%4]; ny += dy[(i+di)%4];
            }
        }
    }
    else if(mp[cy][cx]==4){
        for(int i=0;i<3;i++){
            int nx = cx+dx[(i+di)%4]; int ny=cy+dy[(i+di)%4];
            // 2. CCTV 처리
            while(nx>=0 && nx < w && ny >=0 && ny < h && mp[ny][nx] != 6){
                if(mp[ny][nx]==0){
                    mp[ny][nx]=9; 
                    _change.push_back({ny,nx});
                }
                nx += dx[(i+di)%4]; ny += dy[(i+di)%4];
            }
        }        
    }
    else if(mp[cy][cx]==5){
        for(int i=0;i<4;i++){
            int nx = cx+dx[(i+di)%4]; int ny=cy+dy[(i+di)%4];
            // 2. CCTV 처리
            while(nx>=0 && nx < w && ny >=0 && ny < h && mp[ny][nx] != 6){
                if(mp[ny][nx]==0){
                    mp[ny][nx]=9; 
                    _change.push_back({ny,nx});
                }
                nx += dx[(i+di)%4]; ny += dy[(i+di)%4];
            }
        }        
    }
    return _change;
}
void func1(int v1_index){
    // (2) 
    if(v1_index == v1.size()){
        int m_res=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(mp[i][j] == 0){
                m_res++;
            }
        }
    }
    res = min(res,m_res);
    return ;
    }
    int ny = v1[v1_index].first; int nx = v1[v1_index].second;
    for(int i=0;i<4;i++){
        vector<pair<int,int>> _change = func2(ny,nx,i);
        func1(v1_index+1);
        for(pair<int,int> el : _change){
            if(mp[el.first][el.second]!=0 && mp[el.first][el.second]!=6){
                mp[el.first][el.second] = 0;
            }
        }
    }
    return ;
}
int main(){
    cin >> h >> w;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> mp[i][j];
            if(mp[i][j] != 0 && mp[i][j] != 6) v1.push_back({i,j});
        }
    }
    func1(0);
    cout << res << endl;
    return 0;
}