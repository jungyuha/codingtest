#include <bits/stdc++.h>
using namespace std;
/*
3
555
464
*/
const int INF = 987654321;
int n,pwd[110],cur[110],dp[110][10][10][10];
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
    int result= c+(ds)*d;
    if(result > 9){
        result%=10;
    }
    else if(result < 0){
        result +=10;
    }
    return result;
}
int go(int r,int c1,int c2,int c3,int k){
    int &res = dp[r][c1][c2][c3];
    int n1=c1,n2=c2,n3=c3;
    if(r >= n) {return k;} // 뒤로 넘겼다는 건 == 바로 앞의 수가 pwd와 일치했다는 뜻
    if(res!=-1) { return res;}
    //if(k==15) { return 0;}
    //cout << "r :" <<r <<","<<c1<<c2<<c3<<","<<pwd[r];
    res=INF;
if(k==1) cout << "r!! :" <<r <<",k:"<<k<<","<<c1<<c2<<c3<<",pwd[r]:"<<pwd[r]<<endl;
    if(c1==pwd[r]) {r++; n1 = c2; n2=c3;n3=cur[r+2];} 
    // 첫번째 자리
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(1,i,n1),n2,n3,k+1));
    }
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(-1,i,n1),n2,n3,k+1));
    }
    // 첫번째 + 두번째 자리
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(1,i,n1),make_num(1,i,n2),n3,k+1));
    }
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(-1,i,n1),make_num(-1,i,n2),n3,k+1));
    }
    // 첫번째 + 두번째 +세번째 자리
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(1,i,n1),make_num(1,i,n2),make_num(1,i,n3),k+1));
    }
    for(int i=1;i<=3;i++){
        res = min(res,go(r,make_num(-1,i,n1),make_num(-1,i,n2),make_num(-1,i,n3),k+1));
    }
    return res;
}
int main(){
    init();
    cout << go(0,cur[0],cur[1],cur[2],0) << endl;
    return 0;
}