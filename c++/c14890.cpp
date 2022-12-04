#include <bits/stdc++.h>
using namespace std;

int a,b,res;
int mp1[100][100];
int main(){

    cin >> a >> b;
    for(int i=0;i<a;i++){
       for(int j=0;j<a;j++){
            cin >> mp1[i][j];
        } 
    }

    for(int i=0;i<a;i++){
        bool psb=true;
        int num =0;
       for(int j=0;j<a-1;j++){
            int dif = abs(mp1[i][j]-mp1[i][j+1]);
            if(dif==0) {continue;}
            else if(dif>1) {psb=false;break;}
            else{
                int index=j;
                if((mp1[i][j]-mp1[i][j+1])==-1){
                    for(int k=0;k<b;k++){
                        if((index-k) < 0 || mp1[i][(index-k)]!=mp1[i][j] || num&(1<<(index-k))) { psb=false; break;}
                    }
                    if(psb){
                        for(int k=0;k<b;k++){num|=(1<<(index-k));}
                    }
                }
                else if((mp1[i][j]-mp1[i][j+1])==1){
                    for(int k=1;k<=b;k++){
                        if((index+k) < 0 || mp1[i][(index+k)]!=mp1[i][j+1] || num&(1<<(index+k))) { psb=false; break;}
                    }
                    if(psb)
                        for(int k=1;k<=b;k++){num|=(1<<((index+k)));}
                }
            }
            if(!psb) break;
        } 
        if(psb) {res++;}
    }

    for(int j=0;j<a;j++){
        bool psb=true;
        int num =0;
       for(int i=0;i<a-1;i++){
            int dif = abs(mp1[i][j]-mp1[i][j+1]);
            if(dif==0) {continue;}
            else if(dif>1) {psb=false;break;}
            else{
                int index=j;
                if((mp1[i][j]-mp1[i][j+1])==-1){
                    for(int k=0;k<b;k++){
                        if((index+k) < 0 || mp1[i][(index+k)]!=mp1[i][j+1] || num&(1<<(index-k))) { psb=false; break;}
                    }
                    if(psb){
                        for(int k=0;k<b;k++){num|=(1<<(index-k));}
                    }
                }
                else if((mp1[i][j]-mp1[i][j+1])==1){
                    for(int k=1;k<=b;k++){
                        if((index+k) < 0 || mp1[i][(index+k)]!=mp1[i][j+1] || num&(1<<(index+k))) {psb=false; break;}
                    }
                    if(psb)
                        for(int k=1;k<=b;k++){num|=(1<<((index+k)));}
                }
            }
            if(!psb) break;
        } 
        if(psb) {res++;}
    }
    
    cout << res << "\n";
    return 0;
}