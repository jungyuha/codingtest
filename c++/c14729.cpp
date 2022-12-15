#include <bits/stdc++.h>
using namespace std;

priority_queue<double> pq; // 우선순위 큐
vector<double> res;
int n,top;
double a;
int main(){
    cin >> n;
    for(int i=0;i<7;i++){
        cin >> a;
        pq.push(a);
        n--;
    }
    // (1)
    while(n){
        cin >> a;
        if(a<pq.top()){
            cout << "n : "<<n<<","<<"top:"<<pq.top();
            pq.pop();
            pq.push(a);
        }
        n--;
    }
    while(!pq.empty()){
        res.push_back(pq.top());
        pq.pop();
    }
    sort(res.begin(),res.end());
    for(double el : res){
        cout << el <<"\n";
    }
    return 0;
}  