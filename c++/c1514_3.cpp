#include <bits/stdc++.h>
using namespace std;
/*
3
555
464
*/
const int INF = 987654321;
int n,pwd[110],cur[110],dp[110][10][10][10][2];

void init(){
    cin >> n;
    
    for(int i=0;i<n;i++){
        scanf("%1d",&pwd[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%1d",&cur[i]);
    }
    memset(dp,-1,sizeof(dp));
}
int make_num(int d,int ds,int c){
    // d : 방향(1:순/-1:역) , ds : 이동 거리
    int result= c+(ds*d);
    if(result > 9){
        result%=10;
    }
    else if(result < 0){
        result +=10;
    }
    return result;
}
int go(int r,int c1,int c2,int c3,int m,int k){
    int &res = dp[r][c1][c2][c3][m];
    if(r == n) {return 0;} // 뒤로 넘겼다는 건 == 바로 앞의 수가 pwd와 일치했다는 뜻
    if(res!=-1) { return res;}
    //if(k==15) { return 0;}
    int m_=1;
    if(m==1){m_=-1;}
    res=INF;
    //if(k==2) {cout << "r!! :" <<r <<",k:"<<k<<","<<c1<<c2<<c3<<",pwd[r]:"<<pwd[r]<<endl; return 0;}
    if(make_num(1,c1,cur[r])==pwd[r]) {return res=min(go(r+1,c2,c3,0,0,k+1),go(r+1,c2,c3,0,1,k+1));} 
    
    for(int i=1;i<=3;i++){
        
        res = min(res,go(r,make_num(m_,i,c1),c2,c3,m_,k+1)+1);
        res = min(res,go(r,make_num(m_,i,c1),make_num(m_,i,c2),c3,m_,k+1)+1);
        res = min(res,go(r,make_num(m_,i,c1),make_num(m_,i,c2),make_num(m_,i,c3),m_,k+1)+1);
    }
    
    return res;
}
int main(){
    init();
    cout << min(go(0,0,0,0,1,0),go(0,0,0,0,1,0))<<endl;
    return 0;
}