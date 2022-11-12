#include <bits/stdc++.h>
using namespace std;

/*
5 4
3 1
3 2
4 3
5 3
*/
int a,b,c,d,cnt,max_; // 5 4 입력 입력
vector<vector<int>> lst;
map<int,int> res;
void dfs(int head){
    cnt++;
    //cout << "head : " << head << "\n";
    if(lst[head].size()==0){
        return;
    }
    for(int el : lst[head]){
//        cout << "head : " << head << "," << "el : " << el <<  "\n";
        dfs(el);
    }
}
bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}
int main(){
    cin >> a >> b;

    for(int i=0;i<=a;i++){
        vector<int> vc;
        lst.push_back(vc);
    }

    for(int i=0;i<b;i++){
        cin >> c >> d;
        lst[d].push_back(c);
    }

    for(int i=1;i<=a;i++){
        dfs(i);
//        cout << "head : " << i << "," << "cnt : " << cnt <<  "\n";
        res[i]=cnt;
        if(cnt>max_) max_=cnt;
        cnt = 0;
    }
    vector<pair<int,int>> vec(res.begin(),res.end());

    sort(vec.begin(),vec.end(),cmp);

    for(pair<int,int> el : vec){
        if(el.second < max_) break;
        cout << el.first << " ";
    }

    return 0;
}