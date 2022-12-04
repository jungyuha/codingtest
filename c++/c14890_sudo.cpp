/*
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2

*) 
int a,b,res;
int mp1[100][100];

*)

(행 순회)(int i=0;i<a;i++):
    cout << "i :"<<i <<"\n";
    bool psb=true;
    int num =0;
    (열순회)(int j=0;j<a-1;j++):
        cout << "j :"<<j <<"\n";
        int dif = abs(mp1[i][j]-mp1[i][j+1]);
        cout << "dif :"<<mp1[i][j]-mp1[i][j+1]<<"\n";
        if(dif==0) {continue;}
        else if(dif>1) {psb=false;break;}
        else{
            int index=j;
            cout << "index":<<index<<"\n";
            if((mp1[i][j]-mp1[i][j+1])==-1):
                (경사너비순회)(k=0;k<b;k++)
                    if((index-k) < 0) { cout << "(index-k):"<<(index-k)<<"\n"; psb=false; break;}
                    if(mp1[i][(index-k)]!=mp1[i][j]){cout << "mp1[i][(index-k)]!=:"<<mp1[i][(index-k)]<<"\n"; psb=false; break;}
                    if(num&(1<<(index-k))) { cout << "num&(1<<(index-k)):"<<(index-k)<<"\n"; psb=false; break;}               
                if(psb)
                    cout << "psb \n";
                    (경사너비순회)(k=0;k<b;k++)
                        num|=(1<<index-k)
            else if((mp1[i][j]-mp1[i][j+1])==1):
                (경사너비순회)(k=1;k<=b;k++)
                    if((index+k) < 0) { cout << "(index+k):"<<(index+k)<<"\n"; psb=false; break;}
                    if(mp1[i][(index+k)]!=mp1[i][j+1]){cout << "mp1[i][(index+k)]!=:"<<mp1[i][(index+k)]<<"\n"; psb=false; break;}
                    if(num&(1<<(index+k))){cout << "num&(1<<(index+k)):"<<(index+k)<<"\n"; psb=false; break;}
                if(psb)
                    cout << "psb \n";
                    (경사너비순회)(k=1;k<=b;k++)
                        num=|(1<<index+k)
        }
        if(!psb) break;
    if(psb) : res++;

(열 순회)(int j=0;j<a;j++):
    cout << "j :"<<j <<"\n";
    bool psb=true;
    int num =0;
    (행순회)(int i=0;i<a-1;i++):
        cout << "i :"<<i <<"\n";
        int dif = abs(mp1[i][j]-mp1[i][j+1]);
        cout << "dif :"<<mp1[i][j]-mp1[i][j+1]<<"\n";
        if(dif==0) {continue;}
        else if(dif>1) {psb=false;break;}
        else{
            int index=j;
            cout << "index":<<index<<"\n";
            if((mp1[i][j]-mp1[i][j+1])==-1):
                (경사너비순회)(k=0;k<b;k++)
                    if((index-k) < 0) { cout << "(index-k):"<<(index-k)<<"\n"; psb=false; break;}
                    if(mp1[i][(index-k)]!=mp1[i][j]){cout << "mp1[i][(index-k)]!=:"<<mp1[i][(index-k)]<<"\n"; psb=false; break;}
                    if(num&(1<<(index-k))) { cout << "num&(1<<(index-k)):"<<(index-k)<<"\n"; psb=false; break;}
                if(psb)
                    cout << "psb \n";
                    (경사너비순회)(k=0;k<b;k++)
                        num|=(1<<index-k)
            else if((mp1[i][j]-mp1[i][j+1])==1):
                (경사너비순회)(k=1;k<=b;k++)
                    if((index+k) < 0) { cout << "(index+k):"<<(index+k)<<"\n"; psb=false; break;}
                    if(mp1[i][(index+k)]!=mp1[i][j+1]){cout << "mp1[i][(index+k)]!=:"<<mp1[i][(index+k)]<<"\n"; psb=false; break;}
                    if(num&(1<<(index+k))){cout << "num&(1<<(index+k)):"<<(index+k)<<"\n"; psb=false; break;}
                if(psb)
                    cout << "psb \n";
                    (경사너비순회)(k=1;k<=b;k++)
                        num=|(1<<index+k)
        }
        if(!psb) break;
    if(psb) : res++;
    
    



*) 
1. mp1
cout << "\n";
    for(int i=0;i<a;i++){
       for(int j=0;j<a;j++){
           cout << mp1[i][j];
        } 
        cout << "\n";
    }
2. 순회
for(int i=0;i<a;i++){
    for(int j=0;j<a-1;j++){
        cout << "j :"<<j<<",j+1:"<<j+1<<",mp[j]:"<<mp1[i][j]<<",mp[j+1]:"<<mp1[i][j+1]<<"\n";
    } 
}
*/