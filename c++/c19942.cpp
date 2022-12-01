#include <bits/stdc++.h>
using namespace std;

int n ,a,b,c,d,min_=9999;
int mp1[13][5];
vector<int> res;
int main(){

    cin >> n;
    cin >> a >> b >>c >>d;
    
    for(int i =0;i<n;i++){
        for(int j=0;j<5;j++){
            cin >> mp1[i][j];
        }  
    }

    for(int i=1;i<=pow(2,n);i++){
        int a_sum=0,b_sum=0,c_sum=0,d_sum=0,cost=0;
        vector<int> res_t;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                res_t.push_back(j+1);
                a_sum+=mp1[j][0];
                b_sum+=mp1[j][1];
                c_sum+=mp1[j][2];
                d_sum+=mp1[j][3];
                cost+=mp1[j][4];
                if(a_sum<a||b_sum<b||c_sum<c||d_sum<d) continue;
                if(min_>cost) {
                    min_=cost;
                    res = res_t;
                }
            }
        }
    }

    cout <<min_ <<"\n";
    for(int el:res){
        cout << el << " ";
    }
    return 0;
}