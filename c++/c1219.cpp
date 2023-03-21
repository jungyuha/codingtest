#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n,st,ed,m,val_[55],res_1[55];
vector<pair<int,int>> mp1[55];

void init(){
    cin >> n >> st >> ed >> m ;
    int a,b,c;
    fill(res_1,res_1+55,INF);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        mp1[a].push_back({b,c});
        //mp1[a][b]=c;
    }
    for(int i=0;i<n;i++){
        cin >> val_[i];
    }
    res_1[st]=0;
}
void check(){
    cout <<"hi" <<endl;
    for(int i=0;i<n;i++){
        cout <<"1 " <<endl;
        for(int here=0;here<n;here++){
            for(pair<int,int> el : mp1[here]){
                int to = el.first; int cost = el.second;
                if(res_1[here]+cost < res_1[to]){
                    res_1[to]=res_1[here]+cost;
                }
            }
        }
    }
}
int main(){
    init();
    check();

    for(int i=0;i<n;i++){
        cout << res_1[i]<<" ";
    }
    return 0;
}