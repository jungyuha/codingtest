#include <bits/stdc++.h>
using namespace std;

vector<int> adj[10];
int mp1[1024];
int a,b,end_,level;
//cout << << "\n";
void funcA(int s,int e,int lvl){
    if(s>e) return;
    int mid=(s+e)/2;
    adj[lvl].push_back(mp1[mid]);
    if(s==e) return;
    funcA(s,mid-1,lvl+1);
    funcA(mid+1,e,lvl+1);
}
int main(){
    cin >> level;
    end_ = pow(2,level)-1;
    for(int i=0;i<end_;i++){
        cin >> mp1[i];
    }
   funcA(0,end_,0);

   for(int i=0;i<level;i++){
    for(int el : adj[i]){
        cout << el << " ";
    }
    cout << "\n";
   }
    
    return 0;
}