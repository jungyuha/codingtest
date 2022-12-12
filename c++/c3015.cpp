#include <bits/stdc++.h>
using namespace std;

int a,b,res;
vector<int> aLst;
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> b;
        aLst.push_back(b);
    }

    for(int i=0;i<a;i++){
        int cur = aLst[i],mid_max=-1;
        for(int j=i+1;j<a;j++){
            int next = aLst[j];
            if(mid_max==-1 || ( max(mid_max,next)==next)){
                res++;
                mid_max=next;
            }
            if(cur < next) {break;}
        }
    }

    cout << res << "\n";
    return 0;
}