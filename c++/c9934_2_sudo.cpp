/*
3
1 6 4 3 5 2 7 ,
3
6 2
1 4 5 7

*) 수도코드
vector<int> adj[1004];
int mp1[1004];
int a,b,end_;
main(){
    mp1 = {1 6 4 3 5 2 7};
    end_=7;
    funcA(0,end_,0);
}

funcA(int s,int e,int lvl){
    if(s<e) return;
    int mid=(s+e)/2; // 3
    adj[lvl].push_back(mp1[mid]);
    if(s==e) return;
    funcA(s,mid-1,1);

}// s: 시작인덱스 , e : 끝인덱스 , lvl : 깊이

*)
int s =0,int e=6,int lvl=0
    int mid=(0+7)/2; // 3
    adj[0].push_back(mp1[3]);
    funcA(0,2,1);
    funcA(4,7,1);
int s =0,int e=6,int lvl=1
    int mid=(0+2)/2; // 1
    adj[1].push_back(mp1[1]); // 6
    funcA(0,0,2);
    funcA(2,2,2);
int s =0,int e=6,int lvl=2
    int mid=(0+0)/2; // 0
    if(s==e){
        adj[2].push_back(mp1[0]); // 1
        return;
    }
int s =2,int e=6,int lvl=2
    int mid=(2+2)/2; // 2
    if(s==e){
        adj[2].push_back(mp1[2]); // 4
        return;
    }
int s =4,int e=6,int lvl=1
    int mid=(4+7)/2; // 5
    adj[1].push_back(mp1[5]); // 2
    funcA(4,4,2);
    funcA(6,6,2);
*/