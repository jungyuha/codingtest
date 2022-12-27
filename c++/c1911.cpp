#include <bits/stdc++.h>
using namespace std;
int a,t,cx,res;
long long d;
priority_queue<int,vector<int>,greater<int>> q1;
int main(){

    cin >> a >> t;
    for(int i=0;i<a;i++){
        int a1,a2;
        cin >> a1 >> a2;
        for(int j=a1;j<a2;j++){
            q1.push(j);
        }
    }
    while(!q1.empty()){
        int start = q1.top();
        cout << "start : "<<start<<endl;
        for(int i=0;i<t;i++){
            cx = start + i;
            if(q1.top()==cx){
                cout << "q1.top() : "<<cx<<endl;
                q1.pop();
            }
        }
        res ++;
    }
    cout <<res<< endl;
    return 0;
}