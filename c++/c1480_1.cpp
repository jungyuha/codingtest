#include<bits/stdc++.h>
using namespace std;

const int INF = -987654321;
int n,m,c,d,mp[15],vis[15];
vector<int> temp[16];
// mp[15] : (0) 2 3 1 4 .. 보석의 무게
/*
5 2 5
1 3 5 2 4 => 1,4 / 2,3

1 1 3
3

1 1 2
3

1 1 5
3

*/
int test(int b_idx,int vis,int m_res,int cnt){ 
    cout <<b_idx<<"번 가방 : \n";
    //if(m_res)
    // 1. 담고 넘기기
    cout <<"1번째 담기 : ";
    //m_res =0 ,vis = 0
    int res = 0;
    for(int i =1;i<=n;i++){
        res = test(b_idx,vis|(1<<1),m_res+mp[i],cnt+1);
    }
    cout << "res : " << res <<endl;
}
int main(){
    cin >> n >> m >> c; // 보석 가방 한도
    for(int i=1;i<=n;i++){
        cin >> mp[i];
    }
    cout << test(1,0,0,0);
    return 0;
}