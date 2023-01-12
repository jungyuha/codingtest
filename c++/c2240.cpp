#include <bits/stdc++.h>
using namespace std;

int mp[1000][2][30],arr[1000],res;
int t,w,a;

int go(int n,int p ,int m){
    int &ret = mp[n][p][m];
   // cout << "n: "<<n<< ",p: "<<p<< ",m: "<<m<<",mp[n][p][m]:"<<ret<<endl;
    if(n==0){
        ret = 0;
        cout << "1 n: "<<n<< ",p: "<<p<< ",m: "<<m<<",mp[n][p][m]:"<<ret<<endl;
        return ret ;
    }
    if(m<0){
        ret = -999;
        cout << "2 n: "<<n<< ",p: "<<p<< ",m: "<<m<<",mp[n][p][m]:"<<ret<<endl;
        return ret ;
    }
    if(mp[n][p][m]==-1){
        ret= max(go(n-1,p,m),go(n-1,(p^1),m-1))+(arr[n] == p ?1:0);
        cout << "3 n: "<<n<< ",p: "<<p<< ",m: "<<m<<",mp[n][p][m]:"<<ret<<endl;
        return ret;
    }
    cout << "4 n: "<<n<< ",p: "<<p<< ",m: "<<m<<",mp[n][p][m]:"<<ret<<endl;
    return ret;
}
int main(){

    memset(mp,-1,sizeof(mp));
    mp[0][0][0]=0;
    mp[0][0][1]=-999;
    mp[0][1][0]=-999;
    mp[0][1][1]=-999;
    cin >> t >> w;
    for(int i=1;i<=t;i++){
        cin >> a;
        arr[i] = a-1;
    }
    cout << endl;
    for(int i=0;i<w;i++){
        res = max(go(t,0,i),go(t,1,i-1));
    }
    
    
    return 0;
}