/*
*) dataset
3 6
antarctica
antahellotica
antacartica

2 3
antaxxxxxxxtica
antarctica

*) 메모리
int a,b,total_w,res;
string wd1[50];
*) 시나리오
(함수B)int num
    int cnt =0;
    (단어 순회) int i=0;i<a;i++
        bool yn=true;
        cout << "[함수B] wd[] :" << wd1[i] << "\n";
        bool cntYn=true;
        (알파벳 순회) char c : wd1[i]
            cout << "일치여부" << num&(1 << (int)(1<<c-'a'));
            if(!num&(1 << (int)(1<<c-'a')){yn=false;break;}
        if(yn) cnt++;
    res = max(res,cnt);
(함수A) int index,int num,int level
    if(b<5){ return; }
    if (b>=5 && level==b){
        함수B(num|(1<<(int)('a'-'a'))|(1<<(int)('n'-'a'))|(1<<(int)('t'-'a'))
        |(1<<(int)('i'-'a'))|(1<<(int)('c'-'a')))
        return ;
    }
    cout <<"[funcA] index :"<<index<<"\n";
    (total_w순회)int i=index;i<26;i++
        if (total_w&(1<<i) && i!=(a,n,t,i,c)-'a'):
            index = i;
            함수A(index+1,num|(1<<index),level+1)
        else : continue




(메인)
    (순회) i=0;i<a;i++
        cin >> wd1[i];
        (s순회) char c : wd1[i]  // 입력된 알파벳 기록
            cout << (int)c-'a' << "," << (1<<(int)c-'a');
            total_w|=1<<(int)c-'a');
        for(int j=0;j<26;j++){
            if(total_w&(1 << j)) {cout << "1";}
            else{cout <<"0";}
        }
    함수A(0,0,0)

*) 출력
1.알파벳 자리 맞춰서 이진법 출력
for(int j=0;j<26;j++){
    if(w&(1 << j)) {cout << "1";}
    else{cout <<"0";}
}
2.
cout <<"[funcA] index :"<<index<<",level :" <<level <<"\n";
cout <<"[funcA end] level :"<<level<<",b :" <<b <<"\n";
*/
