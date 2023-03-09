#include <bits/stdc++.h>
using namespace std;

int m_sum[200010]; // 구간합 정보
int cx[200010]; // 각 나무의 좌표
int n;
void init(){
    cin >> n ;
    for(int i=1;i<=n;i++){
        cin >> cx[i];
    }
    for(int i=1;i<=n;i++){
        int idx=i;
        while(idx<=n){
            m_sum[idx]=m_sum[idx]+cx[i];
            idx = idx + (idx&-idx);
        }
    }
    for(int i=1;i<=n;i++){
        cout << m_sum[i] <<",";
    }
    cout << endl;
}
int get_sum(int idx){
    int n_idx = idx;
    int res=0;

    while(n_idx>0){
        res = res + m_sum[n_idx];
        n_idx = n_idx - (n_idx&-n_idx);
    }
    return res;
}
int main(){
    init();
    cout <<endl<< get_sum(3);
}