#include <bits/stdc++.h>
using namespace std;

int a,mp[11],op[4],max_=-9999,min_=9999;
void ops(int index,int m_res){
    if(index == a){
        max_=max(max_,m_res);
        min_=min(min_,m_res);
        return ;
    }
    // (1)
    for(int i=0;i<4;i++){
        if(op[i]>0){
            // (2)
            int next;
            if(i==0){
                // 덧셈
                next = m_res+mp[index];
            }
            else if(i==1){
                // 뺄셈
                next = m_res-mp[index];
            }
            else if(i==2){
                // 곱셈
                next = m_res*mp[index];
            }
            else if(i==3){
                // 나눗셈
                next = m_res/mp[index];
            }   
            op[i]--;
            ops(index+1,next);
            op[i]++;
        }
    }
}
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        cin >> mp[i];
    } 
    for(int i=0;i<4;i++){
        cin >> op[i];
    }
    ops(1,mp[0]);

    cout << max_ << endl;
    cout << min_ << endl;
    return 0;
}