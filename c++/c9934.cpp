#include <bits/stdc++.h>
using namespace std;

int a,seq;
vector <int> mp1 ,res;
//cout <<  <<", " << << << << "\n" ;
void funcA(int cx){
    int nx;
    nx = 2*cx+1;
    if(nx>=pow(2,a)-1){
        res[cx]=mp1[seq];
        seq++;
        return;
    }
    funcA(nx);
    res[cx]=mp1[seq];
    seq++;
    funcA(nx+1);
}
int main(){
    cin >> a;
    for(int i=0;i<pow(2,a)-1;i++){
        int b;
        cin >> b;
        mp1.push_back(b);
        res.push_back(0);
    }
    funcA(0);

    int pop=0;
    for(int i=0;i<a;i++){
        for(int j=0;j<pow(2,i);j++){
            cout << res[pop] << " ";
            pop++;
        }
        cout << "\n";
    }
    return 0;
}