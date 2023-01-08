#include <bits/stdc++.h>
using namespace std;

int mp[1000000],n,lastIndex;
vector<pair<int,int>> infoLst; // rank , prev
vector<int> real_;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> mp[i];
        infoLst.push_back({0,-1});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (mp[i] > mp[j] && infoLst[j].first + 1 > infoLst[i].first){
                infoLst[i].first = infoLst[j].first + 1;
                infoLst[i].second = j;
                lastIndex=i;
            }
        }
    }
    int idx=lastIndex;
    int size=0;
    while (idx!=-1){
        real_.push_back(mp[idx]);
        idx=infoLst[idx].second;
        size++;
    }
    cout << size << endl;
    for(int i=0;i<size;i++){
        cout << real_.back() << " ";
        real_.pop_back();
    }
    return 0;
}