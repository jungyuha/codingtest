#include <bits/stdc++.h>
using namespace std;

int n,m,k,t,time_[310],res;
vector<pair<int,int>> lst2[305] ; 
int dp[310][310]; // [채우기시작인데스][남은영선이친구인원]
int result_;
void init(){
    cin >> n >> m >> k >> t;
    int a,b;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        for(int i=a;i<b;i++){ // 이 부분 조심 !!!! (마지막 초는 파티장을 나가는 시간으로 계산에서 제외한다.)
            time_[i]++;
        }
    }
    // for(int i=1;i<=n;i++){
    //    cout << time_[i]<<" ";
    //    if(time_[i]>=t) result_++;
    // }
    cout << endl;
    int prev = -1,k=0;
    for(int i=1;i<=n;i++){
        if(time_[i]<t && i-1 != prev && i<=n){
            vector<pair<int,int>> lst;
            prev = i-1 ;
            while(time_[i]<t && i-1 == prev && i<=n){
                lst.push_back({i,t-time_[i]});
                prev = i;
                i++;
            }
            lst2[k]=lst;
            k++;
        }
    }
    // for(pair<int,int> el : lst2[1]){
    //     cout << el.first << ","<<el.second<<endl;
    // }
}
int go(int index,int ps){
    // index : 빈공간 인덱스 , ps : 가능한 영선이의 친구
    if(ps<=0 || index > n){ return 0;}
    int res=-1;
    for(int i=0;i<=ps;i++){
        int res1=0; // t명 채워진 시간 , i는 사람
        for(pair<int,int> el :lst2[index]){
            if(el.second-i<=0) res1++;
        }
        //cout << "res1:"<<res1<<endl;
        res=max(res,go(index+1,ps-i)+res1);
    }
    return res;
}
int main(){
    init();
    cout << go(0,k)+result_;
    return 0;
}