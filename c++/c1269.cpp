#include <bits/stdc++.h>
using namespace std;

int a,b,aLst[200000],bLst[200000],res;

void goBiTree(){
    int a_res=a,b_res=b;

    for(int i=0;i<a;i++){
        // (1)
        int s=0,e=b-1,mid=0;
        while(s<=e){   
            mid = (s+e)/2; 
            // (2)
            if(bLst[mid] == aLst[i]){
                // (3)
                a_res--; break;
            }
            else if(bLst[mid] > aLst[i]){
                e = mid-1;
            }
            else if(bLst[mid] < aLst[i]){
                s = mid+1;
            }
        }
    }
    // (4)
    for(int i=0;i<b;i++){
        // (5)
        int s=0,e=a-1,mid=0;
        while(s<=e){   
            mid = (s+e)/2; 
            // (6)
            if(aLst[mid] == bLst[i]){
                // (7)
                b_res--; break;
            }
            else if(aLst[mid] > bLst[i]){
                e = mid-1;
            }
            else if(aLst[mid] < bLst[i]){
                s = mid+1;
            }
        }
    }
    // (8)
    cout << a_res+b_res << endl;
}
void goBound(){
    int a_res=a,b_res=b;
    for(int i=0;i<a;i++){
        // (1)
        int index = lower_bound(bLst,bLst+b,aLst[i])-bLst;
        // (2)
        if(bLst[index] == aLst[i]){
            // (3)
            a_res--;
        }
    }
    // (4)

    for(int i=0;i<b;i++){
        // (5)
        int index = lower_bound(aLst,aLst+a,bLst[i])-aLst;
        // (6)
        if(aLst[index] == bLst[i]){
            // (7)
            b_res--;
        }
    }
    // (8)
}
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        cin >> aLst[i];
    }
    for(int i=0;i<b;i++){
        cin >> bLst[i];
    }    
    sort(aLst,aLst+a);sort(bLst,bLst+b);

    //goBiTree();
    goBound();

    return 0;
}