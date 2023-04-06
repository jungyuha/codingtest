#include <bits/stdc++.h>
using namespace std;

int n,m,mp1[5010],mp2[5010],res_[5010];
vector<pair<int,int>> vc1;
void init(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        mp2[i]=i+1;
    }
    for(int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        vc1.push_back({a,b});
        mp1[a-1]++;
    }
}
bool check(){
    bool res_2 = true;
    for(pair<int,int> el : vc1){
        int a = el.first-1; int b = el.second-1;
        if(res_[a] < res_[b]){
            res_2 = false;
            break;
        }
    }
    return res_2;
}
int main(){
    init();
    for(int i=0;i<n;i++){
        int k =0,j=0;
        while(1){
            //cout <<  "k :: "<<k<<",j ::"<<j<<",mp1[j] ::"<<mp1[j]<<",mp2[j] ::"<<mp2[j]<<endl;
            if(mp2[j]==-1) {j++; continue;}
            if(k==mp1[i]){
                res_[i]=mp2[j];
                mp2[j]=-1;
                break;
            }
            j++;k++;
        }  
    }
    
    if(check()){
        for(int i=0;i<n;i++){
            cout << res_[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << "-1";
    }

    return 0;
}