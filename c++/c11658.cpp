#include <bits/stdc++.h>
using namespace std;

int n,m,tree_[1100000];
int w, x1_, y1_, x2_, y2_;
int a;
void tree_update(int idx,int val){
    cout << "idx :: "<<idx<<endl;
    while(idx <= (n*n)+n+1){
        //cout << "bef : [" << idx <<"] : "<<tree_[idx]<<endl;
        //cout << "   val : [" << val <<"]"<<endl;
        tree_[idx] += val;
        //cout << "aft :[" << idx <<"] : "<<tree_[idx]<<endl;
        idx = idx + (idx & -idx);
    }
}
int get_sum(int idx){
    //cout << "idx :: "<<idx;
    int res=0;
    while(idx >= n+1){
        res+=tree_[idx];
        idx = idx  - (idx & -idx);
    }
    //cout << ", res :: "<<res<<endl;
    return res;
}
void init(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a;
            //cout << "   tree_update : [" << mp[i][j] <<"]"<<endl;
            tree_update((n*i)+j,a);
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout << tree_[(n*i)+j] << " ";
    //     }
    // }
}
int main(){
    init();
    while(m){
        cin >> w ;
        if(w==1){
            cin >> x1_ >> y1_ >> x2_ >> y2_ ;
            int res=0;
            for(int i=x1_;i<=x2_;i++){ // 행
                int start_idx=(n*i)+y1_-1;
                int end_idx=(n*i)+y2_;
                res+=get_sum(end_idx)-get_sum(start_idx);
            }
            cout << "res :: "<<res<<endl;
        }
        else if(w==0){
            cin >> x1_ >> y1_ >> x2_ ; cout << "x1 :: "<<x1_<<","<<y1_<<","<<x2_<<endl;

            tree_update((n*x1_)+y1_,x2_);
        }
        m--;
    }


    return 0;
}
/*
첫째 줄에 표의 크기 N과 수행해야 하는 연산의 수 M이 주어진다.
(1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 표에 채워져있는 수가 1행부터 차례대로 주어진다.
다음 M개의 줄에는 네 개의 정수 w, x, y, c 또는 다섯 개의 정수 w, x1, y1, x2, y2가 주어진다.
w = 0인 경우는 (x, y)를 c (1 ≤ c ≤ 1,000)로 바꾸는 연산이고, w = 1인 경우는 (x1, y1)부터 (x2, y2)의 합을 구해 출력하는 연산이다.
(1 ≤ x1 ≤ x2 ≤ N, 1 ≤ y1 ≤ y2 ≤ N) 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다.
*/