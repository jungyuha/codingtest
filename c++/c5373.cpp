#include <bits/stdc++.h>
using namespace std;

int cnt,mp[6][3][3];
int num[6][12]={
    {25,26,27,37,40,43,30,29,28,54,51,48},
    {19,20,21,39,42,45,36,35,34,52,49,46},
    {10,11,12,37,40,43,3,2,1,48,47,46},
    {16,17,18,45,44,43,30,29,28,54,53,52},
    {27,24,21,12,15,18,36,33,30,9,6,3},
    {19,22,25,1,4,7,28,31,34,16,13,10}
    };
int color_val[55];
map<char,int> ss;
map<char,int> color;
void init(){
    ss['F']=0;
    ss['B']=1;
    ss['U']=2;
    ss['D']=3;
    ss['R']=4;
    ss['L']=5;

    color['R']=0;
    color['O']=1;
    color['W']=2;
    color['Y']=3;
    color['B']=4;
    color['G']=5;

    int k=1;
    for (int i = 0; i < 6; i++) {
       for (int j = 0;j < 3; j++) {
            for (int l = 0;l < 3; l++) {
                color[k]=i;
                k++;
            }
       }
    }
}
void rotate_(int front,char rl){
    int ll;
    if(rl=='+'){
        ll = 3;
    }
    else if(rl =='-'){
        ll = 9;
    }
    cout << "before :::"<<front<<"\n";
    vector<pair<int,int>> temp;
    for(int i=0;i<12;i++){
        int next_idx = (i+ll)%12;
        temp.push_back({num[front][next_idx],color[num[front][i]]});
    }
    for(pair<int,int> el : temp){
        int a = el.first; int b = el.second;
        cout <<"("<< a <<","<<b<<") ";
        color[a]=b;
    }
    cout << "after ::: \n";
    for(int el:num[front]){
        cout <<"("<< el <<","<<color[el]<<") ";
    }
}
int main() {
    init();
    // for (auto mp : ss) {
    //     cout << mp.first <<":";
    //     cout << mp.second << endl;
    //     for(int el : num[mp.second]){
    //         cout << el <<" ";
    //     }
    //     cout << endl;
    // }
    cin >> cnt;
    char c1[2];
    for(int i=0;i<cnt;i++){
        scanf("%s",&c1);
        rotate_(ss[c1[0]],c1[1]);
    }
    cout << "result :: "<< endl;
    for(int i=19;i<=27;i++){
        cout <<"("<< i <<","<<color[i]<<") ";
    }
    return 0;
}
