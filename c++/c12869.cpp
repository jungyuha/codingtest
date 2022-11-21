#include <bits/stdc++.h>
using namespace std;

int a,res;
queue <vector<int>> q;

int main(){
vector<int> dd[6] = {
    {9,3,1},{9,1,3},{3,1,9},{3,9,1},{1,3,9},{1,9,3}
};

    cin >> a;
    vector<int> vc;
    vc.push_back(0);
    for(int i=0;i<a;i++){
        int c;
        cin >> c;
        vc.push_back(c);
    }
    //for(int el : vc){cout << el << ",";} cout << "\n";
    q.push(vc);

    bool yn2 = false;
    while(!yn2){
        vector<int> pop = q.front();
        res = pop[0];
        // cout << "res : " << pop[0] << ", q 크기 : "<< q.size() << "\n";
        // cout << "pop : " ; for(int el : pop){cout << el << ",";} cout << "\n";
        for(vector<int> el : dd){
            vector<int> new_;
            bool yn = true;
            new_.push_back(pop[0]+1);
            for(int i=1;i<pop.size();i++){
                if(pop[i]-el[i-1] > 0) yn = false;
                new_.push_back(pop[i]-el[i-1]);
            }
            //cout << yn << ", new_ : " ; for(int el : new_){cout << el << ",";} cout << "\n";
            if(yn) {
                res = new_[0];
                yn2=true;
                }
            q.push(new_);
        }
        q.pop();
    }
    cout << res << "\n";
    return 0;
}