#include <bits/stdc++.h>
using namespace std;

int a,res;
vector<int> lst;
vector<int> rnk;
int main(){

    scanf("%d",&a);

    for(int i=0;i<a;i++){
        int b; scanf("%d",&b);
        lst.push_back(b);
        rnk.push_back(1);
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<i;j++){
            if(lst[i]>lst[j] && rnk[i] < rnk[j]+1){
                rnk[i]=rnk[j]+1;
                res = max(res,rnk[i]);
            }
        }
    }
    cout << res << endl;
    return 0;
}