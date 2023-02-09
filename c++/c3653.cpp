#include <bits/stdc++.h>
using namespace std;
/*
첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스의 개수는 100개를 넘지 않는다.
각 테스트 케이스의 첫째 줄에는 상근이가 가지고 있는 영화의 수 n과 보려고 하는 영화의 수 m이 주어진다. (1 ≤ n, m ≤ 100,000) 둘째 줄에는 보려고 하는 영화의 번호가 순서대로 주어진다.
영화의 번호는 1부터 n까지 이며, 가장 처음에 영화가 쌓여진 순서는 1부터 증가하는 순서이다. 가장 위에 있는 영화의 번호는 1이다. 
3 1
3 
*/
int n,m,mp[100001],index_[100001],tree[200010],arr_[200010],st_,end_;
void update_penwick(int index,int value){
    while(index<=end_){
        tree[index] += value;
        index = index + (index & -index);
    }
}
void make_penwick(){
    for(int i=1;i<=200010;i++){
        update_penwick(i,arr_[i]);
    }
}
int make_sum(int index){
    int res = 0;
    while(index>=st_){
        res += tree[index];
        index = index - (index & -index);
    }
    return res;
}
int main(){
    cin >> n >> m ;
    st_=100001;
    end_=st_+n-1;
    for(int i=1;i<=m;i++){
        cin >> mp[i];
    }
    // 영화 n개
    // index_[cd번호]=cd위치(=트리인덱스-st_)
    // tree[트리인덱스]=cd위치 펜윅트리값(구간합)
    // arr_[트리인덱스]=cd존재(1,0)
    fill(arr_+st_,arr_+st_+n,1);
    cout <<"1:"<< arr_[100001] << endl;
    make_penwick();
    cout <<"1:"<< tree[100001] << endl;
    for(int i=1;i<=n;i++){
        index_[i] = i-1;    // cd 위치 초기화
    }
    for(int i=st_;i<=end_;i++){
        cout << tree[i] << endl;
    }
    cout <<  (st_-1+3) << endl;
    // for(int i=1;i<=n;i++){
    //     cout << index_[i] << " ";
    // }
    for(int i=1;i<=m;i++){
        int cur=index_[mp[i]]+st_;//해당 CD의 현재 트리 인덱스
        // 현재 위치에서 물러난다.
        update_penwick(cur,-1);
        // 맨 위로 이동한다.
        st_--;
        update_penwick(st_,1);
        // 위치 이동
        index_[mp[i]]=0;
    }
    cout << st_ << endl;
    cout <<"1:"<< end_ << endl;
    for(int i=st_;i<=end_;i++){
        cout << tree[i] << endl;
    }
    return 0;
}