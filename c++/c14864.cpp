#include <bits/stdc++.h>
using namespace std;

int n,m,mp1[5010],mp2[5010],res_[5010];
vector<pair<int,int>> vc1;
queue<int> q1;
void init(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        mp2[i]=i+1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        vc1.push_back({a,b});
        mp1[a]++;
    }
}
int main(){
    init();
    for(int i=0;i<n;i++){
        int k =0,j=0;
        while(1){
            if(mp2[j]==-1) {j++; continue;}
            if(k==mp1[j]){
                mp1[j]=-1;
                res[i]=mp2[]
            }
            j++;k++;
        }  
    }
    return 0;
}