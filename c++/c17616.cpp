#include <bits/stdc++.h>
using namespace std;

int n,m,x,a,b;
vector<int> front_[100010],back_[100010];
int vis[100010];
void init(){
    cin >> n >> m >> x;

    for(int i=0;i<m;i++){
        cin >> a >> b ;
        front_[b].push_back(a);
        back_[a].push_back(b);
    }
    queue<int> q1 , q2;
    for(int i=1;i<=n;i++){
        for(int el : front_[i]){ q1.push(el); }
        for(int el : back_[i]){ q2.push(el); }
        while(!q1.empty()){
            int pop_=q1.front(); q1.pop();
            for(int el : front_[pop_]){
                front_[i].push_back(el);
                q1.push(el);
            }
        }
        while(!q2.empty()){
            int pop_=q2.front(); q2.pop();
            for(int el : back_[pop_]){
                back_[i].push_back(el);
                q2.push(el);
            }
        }
    }
    // for(int i=1;i<=n;i++){
    //     cout<<"i::"<<i <<"=>  ";
    //     for(int el : front_[i]){
    //         cout << el << " ";
    //     }
    //     cout << endl ;
    // }
    // cout <<  " backend____ \n";
    // for(int i=1;i<=n;i++){
    //     cout<<"i::"<<i <<"=>  ";
    //     for(int el : back_[i]){
    //         cout << el << " ";
    //     }
    //     cout << endl ;
    // }   
}
int main(){
    init();
    int ff = 1; int bb = n;
    for(int el : front_[x]){
        if(vis[el]==0) { ff++; vis[el]=1;} 
    }
    fill(vis,vis+100010,0);
    for(int el : back_[x]){
        if(vis[el]==0) { bb--; vis[el]=1;} 
    }
    cout << ff << " " << bb << endl;
    return 0;
}