#include <bits/stdc++.h>
using namespace std;

int a,res=-99999;
vector <int> lst;
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        int b;
        cin >> b;
        lst.push_back(b);
    }

    for(int i=1;i<=a;i++){
        // (1)
        for(int j=0;j<a;j++){
            if(j+i > a) break;
            int tot = 0;
            // (2)
            for(int k=j;k<j+i;k++){
                // (3)
                tot += lst[k];
            }
            res = max(res,tot);
            // (4)
        }
    }
    cout << res << endl ;
    return 0;
}