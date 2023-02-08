#include <bits/stdc++.h>
using namespace std;
int mp[1000000],n,m,k, tree[1000000];
void update_tree(int index,int value){
    while(index<=n){
        tree[index]+=value;
        index = index + (index&-index);
    }
}
void make_penwickTree(){
    for(int i =1;i<=n;i++){
        update_tree(i,mp[i]);
    }
}
int make_sum(int index){
    int sum = 0;
    while(index >= 1){
        sum += tree[index];
        index = index - (index&-index);
    }
    return sum ;
}
int main(){

    cin >> n >> m >> k ;
    for(int i=1;i<=n;i++){
        cin >> mp[i];
    }
    make_penwickTree();
    // for(int i=1;i<=n;i++){
    //     cout << tree[i] <<" ";
    // }
    // cout << endl;

    // for(int i=1;i<=n;i++){
    //     cout << sum_[i] <<" ";
    // }
    // cout << endl;
    int a,b,c;
    for(int i=0;i<m+k;i++){
        scanf("%d %d %d",&a,&b,&c);
        if(a ==1){
            int new_ = c - mp[b];
            update_tree(b,new_);
        }
        else if(a==2){
            cout << make_sum(c)-make_sum(b-1)<< endl;
        }
    }
    return 0;
}