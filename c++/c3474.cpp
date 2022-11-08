#include <bits/stdc++.h>
using namespace std;
//cout << " " << "\n";
int t , n;
int main(){
    cin >> t;
    while(t>0){
        cin >> n;
        int n2_sum = 0, n5_sum = 0;
        while(n > 0){
            int n2=n,n5=n;
            while(n2%2==0){
                n2_sum++;
                n2 = n2/2;
            }
            while(n5%5==0){
                n5_sum++;
                n5 = n5/5;
            }
            n--;
        }
        if(n2_sum < n5_sum) {
            cout << n2_sum << "\n";
        }
        else{
            cout << n5_sum << "\n";
        }
        t--;
    }
    return 0;
}
