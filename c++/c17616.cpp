#include <bits/stdc++.h>
using namespace std;

int n,m,x,a,b;
vector<int> front_[100010],back_[100010];
int res1[100010],res2[100010];
void init(){
    cin >> n >> m >> x;
    fill(res1,res1+100010,1);fill(res2,res2+100010,n);

    for(int i=0;i<m;i++){
        cin >> a >> b ;
        front_[b].push_back(a);
        back_[a].push_back(b);
    }
    queue<int> q1 , q2;
    for(int i=1;i<=n;i++){
        int f_vis[100010],b_vis[100010];
        for(int el : front_[i]){ q1.push(el); f_vis[el]=1;}
        for(int el : back_[i]){ q2.push(el); b_vis[el]=1;}
        while(!q1.empty()){
            int pop_=q1.front(); q1.pop();
            for(int el : front_[pop_]){
                front_[i].push_back(el);
                q1.push(el);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"i::"<<i <<"=>  ";
        for(int el : front_[i]){
            cout << el << " ";
        }
        cout << endl ;
    }
}
int main(){
    init();
    return 0;
}