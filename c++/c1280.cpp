#include <bits/stdc++.h>
using namespace std;

int m_sum[200010]; // 구간합 정보
int cx[200010]; // 각 나무의 좌표
int INF = 1000000007;
int n;
int get_sum(int idx){
    int n_idx = idx;
    int res=0;

    while(n_idx>0){
        res = res + m_sum[n_idx];
        n_idx = n_idx - (n_idx&-n_idx);
    }
    cout << "res : "<< res << ","<<idx << "/ ";
    return res;
}
void init(){
    cin >> n ;
    cin >> cx[1];
    int prev = cx[1]; 
    for(int i=2;i<=n;i++){
        int curr;
        cin >> curr;
        cx[i]=curr-prev;
        prev=curr;
    }
    cout << "!! \n";
    for(int i=1;i<=n;i++){
        cout << cx[i] << ",";
    }
    cout << endl;
    for(int i=1;i<=n;i++){
        int idx=i;
        while(idx<=n){
            m_sum[idx]=m_sum[idx]+cx[i];
            idx = idx + (idx&-idx);
        }
    }
    for(int i=1;i<=n;i++){
        cout << get_sum(i) <<",";
    }
    cout << endl;
}

int get_cost(int idx){
    int n_idx = idx;
    int res=0;

   for(int j=1;j<idx;j++){
        res+=abs(get_sum(idx)-get_sum(j));
        cout <<res << endl;
   }
    return res;
}
int main(){
    init();
    //cout <<endl<< get_cost(4);
    int result=1;
    for(int i=2;i<=n;i++){
        result*=(get_cost(i)%INF);
    }
    cout << result%INF << endl;
}
/*
5
3
4
5
6
7
*/
