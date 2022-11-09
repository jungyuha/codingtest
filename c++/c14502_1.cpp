#include <bits/stdc++.h>
using namespace std;

int n,m,max_,cnt;
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
vector<char> mp[8];
vector<int> visited[8];
vector<int> visited2[8];
vector<string> test;

void dfs2(int cx,int cy){
    visited2[cy][cx]=1;
    for(int k=0;k<4;k++){
        int nx = cx+dx[k];
        int ny = cy+dy[k];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n || mp[ny][nx]=='1' || mp[ny][nx]=='2' || visited2[ny][nx]==1) continue;
        dfs2(nx,ny);
    }
}
/*
7 7      
2 0 0 0 1 1 0
0 0 1 0 1 2 0
0 1 1 0 1 0 0
0 1 0 0 0 0 0
0 0 0 0 0 1 1
0 1 0 0 0 0 0
0 1 0 0 0 0 0
*/
void dfs1(int level){
    if(level==3){
        int res=0;
        cnt++;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){                
                if(mp[i][j]=='2'){
                    dfs2(j,i);
                }                
            }
        } 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){               
                if(mp[i][j]=='0' && visited2[i][j] == 0){
                    res++;
                }           
                if(res>max_) max_ = res;  
            }
        }
        for(int i = 0 ; i < n ; i++){
            fill(&visited2[i][0],&visited2[i][0]+8,0);
        }               
        res = 0;
        return;
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
             if(mp[i][j]=='0' && visited[i][j] == 0){
                mp[i][j]='1';
                visited[i][j] = 1;
                test.push_back("(i:"+to_string(i)+",j:"+to_string(j)+")");
                dfs1(level+1);
                test.pop_back();
                mp[i][j]='0';
                visited[i][j] = 0;
             }
            
        }
    }
}

int main(){

    cin >> n >> m;

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            char c; 
            cin >> c;
            mp[i].push_back(c);
            visited[i].push_back(0);
            visited2[i].push_back(0);
        }
    }
    dfs1(0);
    cout << max_ ;
    
    return 0;
}