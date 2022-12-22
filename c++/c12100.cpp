#include <bits/stdc++.h>
using namespace std;

int a,mp[20][20],t_vis[20][20],max_=-1;
void func1(int index,int k,int ttp[20][20],int vvis[20][20]){
    // (1)
    if(index ==k){ return;}
    //(2)
    // 상하좌우
    for(int i=0;i<4;i++){
        int tp[20][20];memcpy(tp,ttp,sizeof(tp));
        int vis[20][20];memcpy(vis,vvis,sizeof(vis));
        if(i==0){
            // 상 (3)
            for(int cx=0;cx<a;cx++){
                int cy=0,p2=0;
                while(cy<a){
                    if(tp[cy][cx]>0){
                        tp[p2][cx]=tp[cy][cx];
                        if(cy!=p2) {tp[cy][cx] = 0;}
                        if(vis[cy][cx]==1){
                            vis[cy][cx]=0;
                            vis[p2][cx]=1;
                        }
                        if(p2>0 && tp[p2][cx]==tp[p2-1][cx] &&vis[p2-1][cx]==0 && vis[p2][cx]==0){
                            //합치기
                            tp[p2-1][cx]= tp[p2-1][cx] << 1;
                            max_=max(max_,tp[p2-1][cx]);
                            tp[p2][cx]=0; vis[p2-1][cx]=1;
                            p2--;
                        }
                        p2++;
                    }
                    cy++;
                }
            }
        }
        else if(i==1){
            // 하 (3)
            for(int cx=0;cx<a;cx++){
                int cy=a-1,p2=a-1;
                while(cy>=0){
                    if(tp[cy][cx]>0){
                        tp[p2][cx]=tp[cy][cx];
                        if(cy!=p2) {tp[cy][cx] = 0;}
                        if(vis[cy][cx]==1){
                            vis[cy][cx]=0;
                            vis[p2][cx]=1;
                        }
                        if(p2<a-1 && tp[p2][cx]==tp[p2+1][cx] &&vis[p2+1][cx]==0 && vis[p2][cx]==0){
                            //합치기
                            tp[p2+1][cx]= tp[p2+1][cx] << 1;
                            max_=max(max_,tp[p2+1][cx]);
                            tp[p2][cx]=0; vis[p2+1][cx]=1;
                            p2++;
                        }                       
                        p2--;
                    }
                    cy--;
                }
            }
        }
        else if(i==2){
            // 좌 (3)
            for(int cy=0;cy<a;cy++){
                int cx=0,p2=0;
                while(cx<a){
                    if(tp[cy][cx]>0){
                        tp[cy][p2]=tp[cy][cx];
                        if(cx!=p2) {tp[cy][cx] = 0;}
                        if(vis[cy][cx]==1){
                            vis[cy][cx]=0;
                            vis[cy][p2]=1;
                        }
                        if(p2>0 && tp[cy][p2]==tp[cy][p2-1] &&vis[cy][p2-1]==0&&vis[cy][p2]==0){
                            //합치기
                            tp[cy][p2-1]= tp[cy][p2-1] << 1;
                            max_=max(max_,tp[cy][p2-1]);
                            tp[cy][p2]=0; vis[cy][p2-1]=1;
                            p2--;
                        }
                        p2++;
                    }
                    cx++;
                }
            }
        }
        else if(i==3){
            // 우 (3)
            for(int cy=0;cy<a;cy++){
                int cx=a-1,p2=a-1;
                while(cx>=0){
                    if(tp[cy][cx]>0){
                        tp[cy][p2]=tp[cy][cx];
                        if(cx!=p2) {tp[cy][cx] = 0;}
                        if(vis[cy][cx]==1){
                            vis[cy][cx]=0;
                            vis[cy][p2]=1;
                        }
                        if(p2<a-1 && tp[cy][p2]==tp[cy][p2+1] &&vis[cy][p2+1]==0&&vis[cy][p2]==0){
                            //합치기
                            tp[cy][p2+1]= tp[cy][p2+1] << 1;
                            max_=max(max_,tp[cy][p2+1]);
                            tp[cy][p2]=0; vis[cy][p2-1]=1;
                            p2++;
                        }                        
                        p2--;
                    }
                    cx--;
                }
            }
        }
        // (4)
        func1(index+1,k,tp,vis);
    }
    
}
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=1;i<=5;i++){
        func1(0,1,mp,t_vis);
    }
    cout << max_ <<endl;
    return 0;
}