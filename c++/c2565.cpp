#include <bits/stdc++.h>
using namespace std;  

int n,vis[100];
vector<pair<int,int>> lst;
int main() {   
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int a , b;
        scanf("%d %d",&a,&b);
        lst.push_back({a,b});
    }
    sort(lst.begin(),lst.end());
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << lst[i].second << " ";
    // }
    // cout << endl;
    int len =0;
    for(int i=0;i<n;i++){
        //lst[i].second
        int *lower_bnd = lower_bound(vis,vis+len,lst[i].second);
        if(*lower_bnd==0) {
            len ++;
        } 
        *lower_bnd = lst[i].second;
    }
    // cout << endl;
    // for(int i=0;i<len;i++){
    //     cout << vis[i] << endl;
    // }

    cout << len << endl;
    return 0;

} 