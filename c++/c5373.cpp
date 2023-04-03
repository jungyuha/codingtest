#include <bits/stdc++.h>
using namespace std;

int cnt,mp[6][3][3];
int num[6][12]={
    {25,26,27,37,40,43,30,29,28,54,51,48},
    {21,20,19,46,49,52,34,35,36,45,42,39},
    {10,11,12,39,38,37,3,2,1,46,47,48},
    {7,8,9,43,44,45,18,17,16,54,53,52},
    {27,24,21,12,15,18,36,33,30,9,6,3},
    {19,22,25,1,4,7,28,31,34,16,13,10}
    };
int num2[6][8]={
    {1,2,3,6,9,8,7,4}, 
    {12,11,10,13,16,17,18,15},
    {19,20,21,24,27,26,25,22},
    {34,35,36,33,30,29,28,31},
    {37,38,39,42,45,44,43,40},
    {48,47,46,49,52,53,54,51}
    };
int color[55];
map<char,int> ss;
map<int,char> color_val;
void init(){
    ss['F']=0;
    ss['B']=1;
    ss['U']=2;
    ss['D']=3;
    ss['R']=4;
    ss['L']=5;

    color_val[0]='R';
    color_val[1]='O';
    color_val[2]='W';
    color_val[3]='Y';
    color_val[4]='B';
    color_val[5]='G';

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
    int ll,ll2;
    if(rl=='+'){
        ll = 3; ll2 = 6;
    }
    else if(rl =='-'){
        ll = 9; ll2 = 2;
    }
    //cout << "before :::"<<front<<"\n";
    vector<pair<int,int>> temp; vector<pair<int,int>> temp2;
    for(int i=0;i<12;i++){
        int next_idx = (i+ll)%12;
        temp.push_back({num[front][next_idx],color[num[front][i]]});
    }
    for(int i=0;i<8;i++){
        int next_idx = (i+ll2)%8;
        cout <<"!("<< num2[front][i] <<","<<color[num2[front][i]]<<","<<next_idx<<") ";
        temp2.push_back({num2[front][i],color[num2[front][next_idx]]});
    }
    cout << endl;
    for(pair<int,int> el : temp){
        int a = el.first; int b = el.second;
        //cout <<"("<< a <<","<<b<<") ";
        color[a]=b;
    }
    int k=0;
    for(pair<int,int> el : temp2){
        int a = el.first; int b = el.second;
        //cout <<"("<< a <<","<<b<<") ";
        color[a]=b;
    }
    cout << front << "after ::: \n";
    for(int el:num2[front]){
        cout <<"("<< el <<","<<color[el]<<") ";
    }
    cout << endl;
    for(int i=19;i<=27;i++){
        cout <<"("<< i <<","<<color[i]<<") ";
    }
    cout << endl;
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
    int k=1;
    for(int i=19;i<=27;i++){
        cout <<color_val[color[i]];
        if(k%3==0) cout << endl;
        k++;
    }
    return 0;
}
