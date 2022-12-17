#include <bits/stdc++.h>
using namespace std;

int a,p1,p2,x,res;
vector<int> lst;
int main(){
    cin >> a;
    p2 = a-1;
    for(int i=0;i<a;i++){
        int b;
        cin >> b;
        lst.push_back(b);
    }
    cin >> x;
    sort(lst.begin(),lst.end());
    while(p1<p2){
        if(lst[p1]+lst[p2]==x){
            res++;
            p2--;p1++;
        }
        else if(lst[p1]+lst[p2] < x){
            p2--;
        }
        if(lst[p1]+lst[p2] > x){
            p1++;
        }
    }
    cout << "res : " << res << "\n";
    return 0;
}