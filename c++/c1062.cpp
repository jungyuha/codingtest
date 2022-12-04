#include <bits/stdc++.h>
using namespace std;

int a,b,total_w,res;
string wd1[50];
void funcB(int num){
    int cnt =0;
    for(int i =0;i<a;i++){
        bool cntYn=true;
        for(char c : wd1[i]){
            if(!(num&(1<<(int)(c-'a')))) {cntYn=false; break;}
        }
        if(cntYn) cnt++;
    }
    res=max(res,cnt);
}
void funcA(int index, int num,int level){
    if(b<5){ return; }
    if(b>=5 && level == b-5){
        funcB(num|(1<<(int)('a'-'a'))|(1<<(int)('n'-'a'))|(1<<(int)('t'-'a'))
        |(1<<(int)('i'-'a'))|(1<<(int)('c'-'a')));
        return;
    }
    for(int i=index;i<26;i++){ 
        if(total_w&(1<<i) && i!=(int)('a'-'a') && i!=(int)('n'-'a') && i!=(int)('t'-'a')
            && i!=(int)('i'-'a') &&i!=(int)('c'-'a')){
                index = i;
                funcA(index+1,num|(1<<index),level+1);
        }
    }
}
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        cin >> wd1[i];
        for(char c : wd1[i]){
            total_w|=(1<<(int)(c-'a'));
        } 
    }
    funcA(0,0,0);
    return 0;
}