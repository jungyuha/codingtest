#include <bits/stdc++.h>
using namespace std;

int n,m,k,mp[1000000];
int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> mp[i];
    }
    sort(mp,mp+n);

    cin >> m;
    while(m){
        cin >> k;
        if(k == mp[lower_bound(mp,mp+n,k)-mp]){
            cout << "1" <<endl;
        }
        else{
            cout << "0" <<endl;
        }
    }

    return 0;
}