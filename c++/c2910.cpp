/*
9 3
1 3 3 3 2 2 2 1 1
*/
#include <bits/stdc++.h>
using namespace std;
/*
n : n개로 이루어진 수열
c : 숫자는 모두 C보다 작거나 같다
mp1 : 각 수열값 등장 개수
vc1 : distinct 수열
*/
int n,c;
map<string,int> mp1 ,order_mp;

bool cmp(const pair<string,int>& a , const pair<string,int>& b){
    if(a.second == b.second) return order_mp[a.first] < order_mp[b.first];//a.first > b.first;
    return a.second > b.second;
}
int main(){

    cin >> n >> c ;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        if(mp1[s]<1) order_mp[s] = i;
        mp1[s]++;
    }

    vector<pair<string,int>> vc1(mp1.begin(),mp1.end());
    sort(vc1.begin(),vc1.end(),cmp);

    for(auto el : vc1){ // debug
        cout << el.first << " , " <<  el.second << "\n";
    }

    for(auto el : vc1){ // 출력
        string a = el.first;
        for(int i=0;i<el.second;i++){
            cout << a << ' ';
        }
    }
    return 0;
}

