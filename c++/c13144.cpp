#include <bits/stdc++.h>
using namespace std;

int a,p1,p2,res,res_part;
int vis[100001];
vector<int> lst;
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        int b; cin >>b;
        lst.push_back(b);
    }

    for(p1=0;p1<a;p1++){
        //(1)
        while(vis[lst[p2]]!= 1 && p2 < a){
            res_part++;
            vis[lst[p2]]=1; p2++;
            //(2)
        }
        res += (res_part);
        res_part--;
        vis[lst[p1]]=0;
    }
    cout <<res << endl;
    return 0;
}