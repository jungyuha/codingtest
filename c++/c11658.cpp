#include <bits/stdc++.h>
using namespace std;

int n,m,mp[1100000],tree_[1100000];
int w, x1_, y1_, x2_, y2_;
int a;
void tree_update(int idx,int val){
    while(idx <= (n*n)+n+1){
        tree_[idx] += val;
        idx = idx + (idx & -idx);
    }
}
int get_sum(int idx){
    int res=0,k=idx;
    while(idx >= n+1){
        res+=tree_[idx];
        idx = idx  - (idx & -idx);
    }
    return res;
}
void init(){
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a;
            mp[(n*i)+j]=a;
            tree_update((n*i)+j,a);
        }
    }
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
        }
        else if(w==0){
            cin >> x1_ >> y1_ >> x2_ ; 
            tree_update((n*x1_)+y1_,x2_-mp[(n*x1_)+y1_]);
        }
        m--;
    }
    return 0;
}