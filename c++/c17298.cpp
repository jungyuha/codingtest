#include <bits/stdc++.h>
using namespace std;

int a , b ,start ,end_; // 4 ,(3 5 2 7)
vector<int> lst;
vector<int> resLst;
map<int,int> lastMap; // 값  , 최근 인덱스
int main(){

    cin >> a;
    for(int i =0;i<a;i++){
        cin >> b;
        lst.push_back(b);
        resLst.push_back(-1);
    }
    cout  << "b"<< "\n";
    for(int i=a-1;i>=0;i--){
        start = i;
        if(lastMap.find(lst[i])!=lastMap.end()){
            end_=lastMap[lst[i]];
        }
        else{
            end_= a;
        }
        for(int j=i;j<end_;j++){
            if(lst[i] < lst[j]){
                lastMap[lst[i]] = i;
                resLst[i]= lst[j];
                break;
            }
        }
    }
    for(int el : resLst){
        cout << el << " ";
    }

    return 0;
}