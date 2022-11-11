#include <bits/stdc++.h>
using namespace std;
/*
5
-1 0 0 1 1
2
*/
int n,a,m,cnt,max_;
vector<vector<int>> lst;

void dfs(int index){
    if(lst[index].size()==0){
            cnt++;
            return;
    }
    for(int el : lst[index]){
        if(el == m) continue;
        dfs(el);
    }
}
int main(){

    cin >> n ;
    for(int i=0;i<n;i++){
        vector<int> vc;
        lst.push_back(vc);
    }
    for(int i=0;i<n;i++){
        cin >> a;
        if(a!=-1) lst[a].push_back(i);
    }
    cin >> m ;
    
    if(m!=0) dfs(0);

    cout << cnt << "\n";
    return 0;
}