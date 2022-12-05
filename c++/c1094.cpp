#include <bits/stdc++.h>
using namespace std;

int a,res;
int main(){
    cin >> a;
    for(int i=0;i<7;i++){
        if(a & (1<<i)){
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}
