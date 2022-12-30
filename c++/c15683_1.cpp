#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int a,b,mp[8][8],vis[8][8],tot,res=9999;
void go(int type,int cx , int cy,int tp[8][8],int index){
    // (1)
    if(index == tot){
        int m_res=0;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                //(2)
                if(tp[i][j]==0){
                    m_res++;
                }
            }
            //(3)
        }
        res = min(res,m_res);
        return ;
    }
    //(3)
    // type : 1 (방향 1개씩 4번)
    if (type==1){
        for (int i=0;i<4;i++){
            // 1. 방향 선정
            int nx = cx + dx[i]; int ny = cy + dy[i];
            if(nx<0 || nx >= b || ny >=a || ny < 0) continue;
            // 2. CCTV 처리
            int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
            while(nx>=0 && nx < b && ny >=0 && ny < a){
                if(ttp[ny][nx]==6) break;
                if(ttp[ny][nx]==0) ttp[ny][nx]=9;
                nx += dx[i]; ny += dy[i];
            }
            vis[cy][cx]=1;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0){
                        go(ttp[i][j],j,i,ttp,index+1);
                    }
                }
            }
            if(index+1 == tot){
                go(0,0,0,ttp,tot);
            }
            vis[cy][cx]=0;
        } 
    }   
        // type : 2 (방향 2개씩 2번)
    else if (type==2){
        for (int i=0;i<2;i++){
            // 1. 방향 선정
            int nx1 = cx + dx[i]; int ny1 = cy + dy[i];
            int nx2 = cx + dx[i+2]; int ny2 = cy + dy[i+2];
            // 2. CCTV 처리
            int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
            while(nx1>=0 && nx1 < b && ny1 >=0 && ny1 < a){
                if(ttp[ny1][nx1]==6) break;
                ttp[ny1][nx1]=9;
                nx1 += dx[i]; ny1 += dy[i];
            }
            while(nx2>=0 && nx2 < b && ny2 >=0 && ny2 < a){
                if(ttp[ny2][nx2]==6) break;
                ttp[ny2][nx2]=9;
                nx2 += dx[i+2]; ny2 += dy[i+2];
            }
            vis[cy][cx]=1;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0){
                        go(ttp[i][j],j,i,ttp,index+1);
                    }
                }
            }
            if(index+1 == tot){
                go(0,0,0,ttp,tot);
            }
            vis[cy][cx]=0;
        } 
    } 
    // type : 3 (직각 방향 2개씩 4번)
    else if (type==3){
        for (int i=0;i<4;i++){ // 맨 첫번째 방향
            int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
            // 1. 방향 선정
            for(int j=0;j<2;j++){
                int nx = cx+dx[(i+j)%4]; int ny=cy+dy[(i+j)%4];
                // 2. CCTV 처리
                while(nx>=0 && nx < b && ny >=0 && ny < a){
                    if(ttp[ny][nx]==6) break;
                    ttp[ny][nx]=9;
                    nx += dx[(i+j)%4]; ny += dy[(i+j)%4];
                }
            }
            vis[cy][cx]=1;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0){
                        go(ttp[i][j],j,i,ttp,index+1);
                    }
                }
            }
            if(index+1 == tot){
                go(0,0,0,ttp,tot);
            }
            vis[cy][cx]=0;
        } 
    } 
    // type : 4 (직각 방향 3개씩 4번)
    else if (type==4){
        for (int i=0;i<4;i++){ // 맨 첫번째 방향
            int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
            // 1. 방향 선정
            for(int j=0;j<3;j++){
                int nx = cx+dx[(i+j)%4]; int ny=cy+dy[(i+j)%4];
                // 2. CCTV 처리
                while(nx>=0 && nx < b && ny >=0 && ny < a){
                    if(ttp[ny][nx]==6) break;
                    ttp[ny][nx]=9;
                    nx += dx[(i+j)%4]; ny += dy[(i+j)%4];
                }
            }
            vis[cy][cx]=1;
            for(int i=0;i<a;i++){
                for(int j=0;j<b;j++){
                    if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0){
                        go(ttp[i][j],j,i,ttp,index+1);
                    }
                }
            }
            if(index+1 == tot){
                go(0,0,0,ttp,tot);
            }
            vis[cy][cx]=0;
        } 
    }
    else if (type==5){
        int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
        for (int i=0;i<4;i++){
            // 1. 방향 선정
            int nx = cx + dx[i]; int ny = cy + dy[i];
            // 2. CCTV 처리
            while(nx>=0 && nx < b && ny >=0 && ny < a){
                if(ttp[ny][nx]==6) break;
                if(ttp[ny][nx]==0) ttp[ny][nx]=9;
                nx += dx[i]; ny += dy[i];
            }
        } 
        vis[cy][cx]=1;
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0){
                    go(ttp[i][j],j,i,ttp,index+1);
                }
            }
        }
        if(index+1 == tot){
            go(0,0,0,ttp,tot);
        }
        vis[cy][cx]=0;
    }      
}
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp[i][j] ;
            if(mp[i][j] > 0 && mp[i][j] < 6){
                tot++;
            }
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            vis[i][j]=1;
            if(mp[i][j] > 0 && mp[i][j] != 6){
                go(mp[i][j],j,i,mp,0);
            }
            vis[i][j]=0;
        }
    }
    cout << "res : "<<res<<endl;
    return 0;
}