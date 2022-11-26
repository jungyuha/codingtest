#include <bits/stdc++.h>
using namespace std;

int a;
int vis[11];
char op[20];
vector<string> res;
// cout << << << << << << "\n";
void funcA(int cx,int cp,string pp){
    if(cx==a){
        res.push_back(pp);
        return;
    }
    for(int np = 9 ; np >= 0 ; np--){
        if(vis[np]>0) continue;
        if(op[cx]=='<' && cp >= np)
            continue;
        else if(op[cx]=='>' && cp <= np)
            continue;
        vis[np]=1;
        funcA(cx+1,np,pp+to_string(np));
        vis[np]=0;
    }
}
int main(){
    cin >> a;
    for(int i = 0;i<a;i++){
        cin >> op[i];
    }
    for(int i = 9;i>=0;i--){
        vis[i]=1;
        funcA(0,i,to_string(i));
        vis[i]=0;
    }
    cout << res[0] << "\n";
    cout << res.back() << "\n";
    return 0;
}