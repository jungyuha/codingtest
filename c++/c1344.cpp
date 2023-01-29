#include <bits/stdc++.h>
using namespace std;

int a,b,cnt,era[20];
long long dp[20][20][20];
double dp2[20][20][20];
double res,aa,bb;

void go_print1(int vis_a,int vis_b,int d){
    cout <<"a: ";
    for(int j=1;j<=d;j++){
        if((1<<j)&vis_a){
            cout << "1 "; 
        }
        else{cout << "0 ";}
    }
    cout <<"\nb: ";
    for(int j=1;j<=d;j++){
        if((1<<j)&vis_b){
            cout << "1 "; 
        }
        else{cout << "0 ";}
    }
    cout <<"\n";
}
bool checkYn(int k){
    bool res=true;
    if(k<2) res = false;
    for(int i=2;i<k;i++){
        if(k%i==0){res=false;break;}
    }
    return res;
}
void go_era(){
    fill(era,era+20,1);
    era[0]=0;era[1]=0;
    for(int i=2;i<=20;i++){
        // 2 : 4 6 8 
        // 3 : 6 9 
        // 4 : 8 12
        // 20 ..
        for(int j = i+i;j<=20;j+=i){
            era[j]=0;
        }
    }
}
long long go_1(int vis_a,int vis_b,int d,long long ca,long long cb){
    cout <<  "ca :"<< ca << "cb :"<< cb << "d :"<< d << endl;
    if(d==2){
        // go_print1(vis_a|(1<<(d+1)),vis_b|(1<<(d+1)),d+1); // 11
        // go_print1(vis_a|(1<<(d+1)),vis_b,d+1); // 10
        // go_print1(vis_a,vis_b|(1<<(d+1)),d+1); // 01
        go_print1(vis_a,vis_b,d); // 00
        if(checkYn(ca)||checkYn(cb)) { return 1; }
        else { return 0; }
    }
    
    if(dp[ca][cb][d]>0){
        return dp[ca][cb][d];
    }
    dp[ca][cb][d]+= go_1(vis_a|(1<<(d+1)),vis_b|(1<<(d+1)),d+1,ca+1,cb+1); // 11
    dp[ca][cb][d]+= go_1(vis_a|(1<<(d+1)),vis_b,d+1,ca+1,cb); // 10
    dp[ca][cb][d]+= go_1(vis_a,vis_b|(1<<(d+1)),d+1,ca,cb+1); // 01
    dp[ca][cb][d]+= go_1(vis_a,vis_b,d+1,ca,cb); // 00

    cout << "dp["<< ca<<"]["<<cb<<"]["<<d<<"]:"<< dp[ca][cb][d]<< endl;
    return dp[ca][cb][d];
}
double go_2(int d,int ca,int cb){
    cout <<  "ca :"<< ca << ", cb :"<< cb << ", d :"<< d << endl;
    if(d>=18){
        //go_print1(vis_a,vis_b,d);
        if(era[ca]==1||era[cb]==1) { return 1; }
        else { return 0; }
    }
    
    if(dp2[ca][cb][d]>0){
        return dp2[ca][cb][d];
    }
    dp2[ca][cb][d]+= go_2(d+1,ca+1,cb+1)*aa*bb; // 11
    dp2[ca][cb][d]+= go_2(d+1,ca+1,cb)*aa*(1-bb); // 10
    dp2[ca][cb][d]+= go_2(d+1,ca,cb+1)*(1-aa)*bb; // 01
    dp2[ca][cb][d]+= go_2(d+1,ca,cb)*(1-aa)*(1-bb); // 00

    cout << "dp2["<< ca<<"]["<<cb<<"]["<<d<<"]:"<< dp2[ca][cb][d]<< endl;
    return dp2[ca][cb][d];
}
int main(){

    cin >> a >> b;
    aa = (double)a/100;
    bb = (double)b/100;
    go_era();

    // cout << "aa: "<<aa;cout << "bb: "<<bb<<endl;
    // for(int i=1;i<=20;i++){
    //     cout <<"["<<i<<"]:"<<era[i]<<",";
    // }

    printf("%.6lf", go_2(0,0,0));
    //cout << ret << endl;
    return 0;
}