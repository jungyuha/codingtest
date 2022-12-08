#include <bits/stdc++.h>
using namespace std;

int a ,b,cnt,tot;
vector<int> adj[1001];
int vis[1024];
void dfs(int index){
    for(int el : adj[index]){
        if(vis[el]==1) continue;
        vis[el]=1;
        cnt++;
        dfs(el);
    }
}
int main(){
    scanf("%d",&tot);
    for(int k=0;k<tot;k++){
        scanf("%d",&a);scanf("%d",&b);
        for(int i=0;i<b;i++){
            int c,d;
            scanf("%d %d",&c,&d);
            adj[c].push_back(d);
            adj[d].push_back(c);
        }
        vis[1]=1;
        dfs(1);

        cout<<"\n";
        if(b == cnt){cout << "tree";}
        else{cout <<"graph";}
    }

    return 0;
}