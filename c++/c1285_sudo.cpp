/*
*) 입력 
3
HHT
THH
THT

*) 메모리
int a = 3;
int cur = 3; // 현재 T의 갯수
int min_ = 999;
char mp[20][20];
pair<int,int> pp[40]; //{y,x}
    => 1행 : HHT , 2행 : THH , 3행 : THT , 1열 : HTT , 2열 : HHH , 3열 : THT 
int vis[20][20]; //{y,x}
3행 + 3열 = 6 => 전체 경우의 수 64

*) 시나리오

(행 순회)int i=0;i<a;i++
    (열 순회) int j=0;j<a;j++
        pp[i][j]=mp[i][j];
(열 순회)int i=0;i<a;i++
    (행 순회) int j=0;j<a;j++
        pp[i+a][j]=mp[j][i];

int n = 2*a; // pp 요소의 갯수

(1~2^a 순회)int i =1;i<=pow(2,2*a);i++
    int temp = cur;
    memset(vis,0,sizeof(vis));
    (n자리수 순회)int j =0;j<n;j++
        if(i&(1 << j)): 뒤집는다.
            (행 또는 열 순회)char c : pp[j]
                c=mp[pp[j][k].first][pp[j][k].second];
                if(is[pp[j][k].first][pp[j][k].second]%2!=0) : 
                    if(c=='T'){
                            c= 'H';
                        }
                        else{
                            c = 'T';
                        }
                if(c=='H'){
                        temp++;
                    }
                    else if(c=='T'){
                        temp--;
                    }
                    vis[pp[j][k].first][pp[j][k].second]++;
    if temp < min_ : min_ = temp;

*) 출력
1. mp
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout << mp[i][j];
        }
        cout << "\n";
    }
2. pp
for(int i=0;i<2*a;i++){
        for(int j=0;j<a;j++){
            cout << pp[i][j];
        }
        cout << "\n";
    }
*/