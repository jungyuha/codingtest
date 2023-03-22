#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
int n,st,ed,m,val_[55],res_1[55],cycle[55];
vector<pair<int,int>> mp1[55];

void init(){
    cin >> n >> st >> ed >> m ;
    int a,b,c;
    fill(res_1,res_1+55,INF);
    for(int i=0;i<m;i++){
        cin >> a >> b >> c;
        mp1[a].push_back({b,(-1)*c});
    }
    for(int i=0;i<n;i++){
        cin >> val_[i];
    }
    res_1[st]=val_[st];
}
void check(){
    for(int i=0;i<n;i++){
        for(int here=0;here<n;here++){
            for(pair<int,int> el : mp1[here]){
                int to = el.first; int cost = el.second;
                if(res_1[here]+cost+val_[to] > res_1[to]){
                    cout <<"i:"<<i<< ",here :"<<here <<",to :"<<to<<","<<res_1[here]<<"+"<<cost<<"+"<<val_[to] <<endl;
                    if(i>n-2 && n > 1) { cout << "?" ; cycle[to] = 1; }
                    res_1[to]=res_1[here]+cost+val_[to];
                }
            }
        }
    }
}
int main(){
    init();
    check();

    // for(int i=0;i<n;i++){
    //     cout << res_1[i]<<" ";
    // }
    // cout << endl;
    //  for(int i=0;i<n;i++){
    //     if(cycle[i]==1)cout << i<<" !! ";
    // }

    if(cycle[ed]==1){cout << "gee" ;}
    else if(res_1[ed]==INF){cout <<"gg";}
    else{cout << res_1[ed];}
    cout << endl;
    return 0;
}