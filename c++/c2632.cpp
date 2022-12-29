#include <bits/stdc++.h>
using namespace std;

int a,b,c,lst_a[1000],lst_b[1000];
int main(){

    cin >> a >> b >> c;
    for(int i=0;i<b;i++){
        cin >> lst_a[i];
    }
    for(int i=0;i<c;i++){
        cin >> lst_b[i];
    }

    for(int i=0;i<=b;i++){ // A피자 경우의 수 순회
        // i조각 (0~)
        for(int ii=0;ii<b;ii++){ // i조각 pick
            //if(ii+i>b) break;
            cout << "i : "; // (1)
             if(i==0) { ii = b; }
            int tot_a=0;
            for(int iii=0;iii<i;iii++){
                cout << lst_a[(ii+iii)%b] <<" "; // (2)
                tot_a += lst_a[(ii+iii)%b];
            }
            //cout << endl;
            //tot
            //B피자 경우의 수 순회
            for(int j=0;j<=c;j++){
                for(int jj=0;jj<c;jj++){ // j조각 pick
                    if(j==0) {jj=c;} // jj+j>c || 
                    cout << "   j :";   // (3)
                    int tot_b=tot_a;
                    for(int jjj=0;jjj<j;jjj++){
                        cout << lst_b[(jj+jjj)%c] <<" "; // (4)
                        tot_b += lst_b[(jj+jjj)%c];
                    }
                    cout << endl << "tot :"<< tot_b ;
                    cout << endl; // (5)
                }
            }
            
        }
        
    }

    return 0;
}
// 2 2 1 7 2