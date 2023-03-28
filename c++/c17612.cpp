#include <bits/stdc++.h>
using namespace std;

struct Data{
    int time;    // 계산 시간
    int end_time;    // 끝나는 시간
    int d_num;  // 자리 번호
    int seq;    // 일련 번호
};
struct comp{
    bool operator()(Data & a , Data & b){
        if(a.end_time == b.end_time){
            return a.d_num > b.d_num;
        }
        return a.end_time > b.end_time;
    }
};
bool comp2 (Data & a , Data & b){
    if(a.end_time == b.end_time){
        return a.d_num > b.d_num;
    }
    return a.end_time < b.end_time;
};
int n,k;
long long res=0;
Data dataArr[100000];
vector <Data> v;
priority_queue <Data,vector<Data>,comp> q1;
void init(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> dataArr[i].seq;
        cin >> dataArr[i].time;
    }

    for(int i=1;i<=k;i++){
        Data d1; d1.d_num=i; d1.end_time=0; q1.push(d1);
    }
}
int main(){
    init();
    int rnk=0;
    for (int i = 0; i < n; i++)
    {
        int s_num = q1.top().d_num;
        cout << s_num <<"!!"<<endl;
        int s_time = q1.top().end_time;
        if(s_time > 0) {
            //cout<<"rnk : "<<rnk <<","<< q1.top().end_time << "," << q1.top().d_num << "," << q1.top().seq << endl;
            v.push_back(q1.top());
            //res = res + rnk*q1.top().seq;
        }
        q1.pop();
        dataArr[i].d_num=s_num;
        dataArr[i].end_time=s_time+dataArr[i].time;
        q1.push(dataArr[i]);
    }
    while (!q1.empty())
    {
        v.push_back(q1.top());
        q1.pop();
    }
    sort(v.begin(),v.end(),comp2);
    for(Data el : v){
        rnk++;
        //cout<<"? : "<<rnk <<","<< el.end_time << "," << el.d_num << "," << el.seq << endl;
        res = res + rnk*el.seq;
    }
    cout << res ;
    return 0;
}