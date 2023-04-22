#include <bits/stdc++.h>
using namespace std;

int arr_[10],vis[10],tot_;
void init(){
    for(int i=0;i<9;i++){
        cin >> arr_[i];
        tot_+=arr_[i];
    }
    sort(arr_,arr_+9);
}   

int main(){
    init();

    int a,b,res_;
    for(int i=0;i<9;i++){
        a=i;
        for(int j=0;j<9;j++){
            b=j;
            if(a==b) continue;
            res_=tot_-arr_[i]-arr_[j];
            if(res_==100){
                for(int k=0;k<9;k++){
                    if(k != a && k != b) cout << arr_[k] << endl;
                } 
                return 0;
            }
        }
    }
    return 0;
}