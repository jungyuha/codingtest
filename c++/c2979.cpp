#include <bits/stdc++.h>
using namespace std;

int a,b,c,time_[110];
void init(){
    int t1,t2;
    cin >> a >> b >> c;
    
    for(int i=0;i<3;i++){
        cin >> t1 >> t2;
        for(int k=t1;k<t2;k++){
            time_[k]++;
        }
    }
}
int main(){
    init();
    int res=0;
    for(int i=1;i<=105;i++){
        if(time_[i]==1){
            res += a;
        }
        else if(time_[i]==2){
            res += 2*b;
        }
        else if(time_[i]==3){
            res += 3*c;
        }
    }
    cout <<res << endl;
    return 0;
}