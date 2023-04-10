#include <bits/stdc++.h>
using namespace std;
const int dx[]={1,1,0};
const int dy[]={0,1,1};
int n,mp[16][16],dp[16*16][3];
int go(int p1,int p2){
    cout <<"p1 :" <<p1 <<",p2:"<<p2<< ",cx : "<<(p2-1)%n <<",cy :"<<((p2-1)/n)<< endl;
    int cx2 =(p2-1)%n,cy2=((p2-1)/n),sp1=0,sp2=0,res=0,type=-1;
    if(p2 == n*n){
        cout <<"도착 ! p2:"<<p2<< ",cx2 : "<<cx2 <<",cy2 :"<<cy2<< endl;
        return 1;
    }
    int st=0,ed=3;
    if(p2-p1 == 1) {// 0,1
        type=0;
        ed = 2;    
    } 
    else if(p2 - p1 == n+1) {type=1;} // 0,1,2
    else if(p2 - p1 == n) {st=1;type=2;} // 1,2

    if(dp[p2][type]!=-1){
        cout <<"!!"<<endl;
        return dp[p2][type];
    }

    for(int i=st;i<ed;i++){
        int nx2 = cx2 + dx[i];
        int ny2 = cy2 + dy[i];
        cout <<"    22 p2:("<<i<<")"<<p2<< ",nx2 : "<<nx2 <<",ny :"<<ny2<<","<<(ny2)*n+nx2+1<< endl;
        if(nx2>=n || ny2 >= n) continue;
        sp2 = nx2 + (ny2)*n +1;
        if(i==0){
            cout <<" mp[((p1-1)/n)][((p1-1)%n)+1]:"<<((p1-1)/n)<< ",nx2 : "<<((p1-1)%n)+1 <<",ny :"<<mp[((p1-1)/n)][((p1-1)%n)+1]<< endl;
            if(mp[((p2-1)/n)][((p2-1)%n)+1]==1) continue;
            sp1=sp2-1;
        }
        else if(i==1){
            if(mp[((p2-1)/n)][((p2-1)%n)+1]==1) continue;
            if(mp[((p2-1)/n)+1][((p2-1)%n)]==1) continue;
            if(mp[((p2-1)/n)+1][((p2-1)%n)+1]==1) continue;
            sp1=sp2-1-n;
        }
        else if(i==2){
            if(mp[((p2-1)/n)+1][((p2-1)%n)]==1) continue;
            sp1=sp2-n;
        }

        res+=go(sp1,sp2);
    }
    cout <<"        33 p2:"<<p2<< ",return  : "<<res << endl;
    dp[p2][type]=res;
    return res;
}
int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    go(1,2);
    return 0;
}