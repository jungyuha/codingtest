/*
*) 입력
26
add 1
add 2
check 1
check 2
check 3
remove 2
check 1
check 2
toggle 3
check 1
check 2
check 3
check 4
all
check 10
check 20
toggle 10
remove 20
check 10
check 20
empty
check 1
toggle 1
check 1
toggle 1
check 1

*) 
if s == "add" :
    if(!(res&(1 << p))){
        res |= (1 << p);
    }
*) 출력
for(int i=0;i<20;i++){
    if(res&(1<<i)){cout<<"1";}
    else{cout << "0"};
} cout << "\n";
*/