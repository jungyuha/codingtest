#include <bits/stdc++.h>
using namespace std;  

int s,e,mid,res=987654321;
double x,y,z;
bool yn_ = false;
int main() {   
    cin >> x >> y ;
    cout << (y/x)*100 << endl;
    s = 1 ; e = x; z = (y/x)*100;
    // (1)
    while(s<=e){
        mid = (s+e)/2;
        int m_z = ((y+mid)/(x+mid))*100;
        // (2)
        if(m_z > z) {
            res = min(res,mid);
            yn_ = true;
            e = mid -1;
            // (3)
        }
        else if(m_z == z) {
            s = mid+1;
        }
    }
    if(!yn_) res = -1;   

    cout  << res <<endl;

    return 0;

}