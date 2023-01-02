#include <bits/stdc++.h>
using namespace std;

int a,lastIndex,mp[1000],rnk[1000],prevLst[1000];
vector<int> realLst;
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> mp[i];
    }
    memset(rnk,1,a);
    memset(prevLst,-1,a);

    for(int i=0;i<a;i++){
        for(int j=0;j<i;j++){
            if(mp[i]>mp[j]){
                if(rnk[j]+1 <= rnk[i]) continue;
                rnk[i] = rnk[j]+1;
                prevLst[i]=j;
                lastIndex=i;
            }
        }
    }
    int p=lastIndex;
    while(p!=-1){
        realLst.push_back(mp[p]);
        p=prevLst[p];
    }

    while(!realLst.empty()){
        cout << realLst.back() << " ";
        realLst.pop_back();
    }
    cout << endl;
    return 0;
}