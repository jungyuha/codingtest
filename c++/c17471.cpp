
#include <bits/stdc++.h>
using namespace std;  
int a,min_=987654321;
vector<int> adj[10];
int val[10],vis[10],s1[10],s2[10];
bool conYn =false,exist=false;
void dfs(int index, int level , int size,int* s){
    if(level==size){
        conYn=true;
        return;
    }
    for(int el : adj[index]){
        if(vis[el]==1||s[el]==0) continue;
        vis[el]=1;
        dfs(el,level+1,size,s);
        vis[el]=0;
        if(conYn) break;
    }
    memset(vis,0,sizeof(vis));
}
int main() {   
    cin >> a ;
    for(int i=0;i<a;i++){
        cin >> val[i];
    }
    for(int i=0;i<a;i++){
        int c ; cin >> c;
        for(int j=0;j<c;j++){
            int d; cin >> d;
            adj[i].push_back(d-1);
        }
    }
    
    for(int i=1;i<=pow(2,a);i++){
        bool resYn = false;
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        int s1_size=0,s2_size=0;
        for(int j=0;j<a;j++){
            if(i&(1<<j)){
                s1[j]=1; s2[j]=0;
                s1_size++;
            }
            else{s1[j]=0; s2[j]=1;s2_size++;}
        }
        for(int el : s1){
            conYn = false;
            dfs(0,1,s1_size,s1);
            if(conYn) break;
        }
        if(!conYn) continue;
        for(int el : s2){
            conYn = false;
            dfs(0,1,s2_size,s2);
            if(conYn) {
                resYn = true;
                break;
            }
        }
        if(resYn){
            // 인구차 비교
            int sum1=0,sum2=0;
            for(int i=0;i<a;i++){
                if(s1[i]==1){
                    sum1+=val[i];
                }
                else if(s2[i]==1){
                    sum2+=val[i];
                }
            }
            if(min_>abs(sum1-sum2)){
                min_ = abs(sum1-sum2);
                exist = true;
            }
        }
    }    
    if(exist){
        cout << min_;
    }
    else{
        cout << "-1";
    }
    return 0;
} 