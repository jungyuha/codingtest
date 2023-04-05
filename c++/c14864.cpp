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
        mp1[a-1]++;
    }
}
int main(){
    init();
    cout <<  "111 \n";
    for(int i=0;i<n;i++){
        //mp1[i]
        int k =0,j=0;
        while(k<10){
            cout <<  "k :: "<<k<<",j ::"<<j<<",mp1[j] ::"<<mp1[j]<<",mp2[j] ::"<<mp2[j]<<endl;
            if(mp2[j]==-1) {j++; continue;}
            if(k==mp1[i]){
                res_[i]=mp2[j];
                mp2[j]=-1;
                break;
            }
            j++;k++;
        }  
        cout <<  "222 \n";
    }
    
    for(int i=0;i<n;i++){
        cout << res_[i] << " ";
    }
    cout << endl;
    return 0;
}