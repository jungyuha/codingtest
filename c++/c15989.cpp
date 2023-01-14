#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,p,n,mp[10000][4],res[10000];
int main() {

    mp[0][1] =1; mp[0][2] =1; mp[0][3] =1;
    for(int i=1;i<=10000;i++){
        for(int j=1;j<=3;j++){
            if(i-j>=0){
                for(int jj=1;jj<=j;jj++){
                    mp[i][j]+=mp[i-j][jj]; 
                    res[i]+=mp[i-j][jj];
                    if(i==j) jj=j+1;
                }
                // (1)
  
            }
        }
    }

    cin >> t;
    while(t){
        cin >> p;
        // (2)
        int sum_=0;
        for(int i=1;i<=3;i++){
            sum_+=mp[p][i];
        }
        cout << sum_ << endl;
        t--;
    }

    return 0;
}