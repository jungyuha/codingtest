#include <bits/stdc++.h>
using namespace std;

int t,a,b,aLst[20000],bLst[20000];
vector<int> resLst;
int main(){

    cin >> t ;
    while (t){
        cin >> a >> b;
        for(int i=0;i<a;i++){
            cin >> aLst[i];
        } 
        for(int i=0;i<b;i++){
            cin >> bLst[i];
        } 
        sort(aLst,aLst+a);
        sort(bLst,bLst+b);
        // (1)
        int res =0;
        for(int i=0;i<a;i++){
            int m_cnt = lower_bound(bLst,bLst+b,aLst[i])- bLst;
            if(m_cnt>0) {res+=m_cnt;}
            // (2)
        }
        resLst.push_back(res);
    t--;
    }
    for(int el : resLst){
        cout << el << endl;
    }
    return 0;
}