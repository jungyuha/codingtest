#include <bits/stdc++.h>
using namespace std;

int a,b,c,t1=2,t2=6,res;
int mp[1000][8];

void turn(int index,int di){
    queue<int> q;
    cout << "turn :"<<index<<","<<di <<endl;
    for(int k=0;k<8;k++){
        q.push(mp[index][(k+8+(di*(-1)))%8]);
    }
    for(int k=0;k<8;k++){
        mp[index][k]=q.front();
        q.pop();
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<8;j++){
            cout << mp[i][j] ;
        }
        cout << endl;
    }
}
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        for(int j=0;j<8;j++){
            scanf("%1d",&mp[i][j]);
        }
    }
    int c1,c2;
    int vis[1000];
    cin >> c;
    for(int j=0;j<c;j++){
        cin >> c1 >> c2;
        c1--;
        memset(vis,0,sizeof(vis));
        int rd = c2;
        for(int i=c1;i<a;i++){
            int r1=mp[i][t1];
            int r2=mp[i+1][t2];
            cout <<i<< ":r1,r2 :" <<r1<<","<<r2<<endl;
            vis[i]=rd;
            if(i+1<a&&r1+r2==1){
                cout << "rd*=(-1)" <<endl;
                rd*=(-1);
            }
            else{ break;}
        }
        int ld = c2;
        for(int i=c1;i>=0;i--){
            int r1=mp[i][t2];
            int r2=mp[i-1][t1];
            cout <<i<< ": r1,r2 :" <<r1<<","<<r2<<endl;
            vis[i]=ld;
            if(i-1>=0&&r1+r2==1){
                cout << "ld*=(-1)" <<endl;
                rd*=(-1);
            }
            else{ break;}
        }
        for(int i=0;i<a;i++){
            if(vis[i]!=0){
                turn(i,vis[i]);
            }
        }
    }
    for(int i=0;i<a;i++){
        if(mp[i][0]==1) res++;
    }
    cout << res << endl;
    return 0;
}