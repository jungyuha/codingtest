/*
첫째 줄에 체스판의 크기 N, 말의 개수 K가 주어진다.
둘째 줄부터 N개의 줄에 체스판의 정보가 주어진다.
체스판의 정보는 정수로 이루어져 있고, 각 정수는 칸의 색을 의미한다.
0은 흰색, 1은 빨간색, 2는 파란색이다.

다음 K개의 줄에 말의 정보가 1번 말부터 순서대로 주어진다.
말의 정보는 세 개의 정수로 이루어져 있고, 순서대로 행, 열의 번호, 이동 방향이다.
행과 열의 번호는 1부터 시작하고, 이동 방향은 4보다 작거나 같은 자연수이고
1부터 순서대로 →, ←, ↑, ↓의 의미를 갖는다.

같은 칸에 말이 두 개 이상 있는 경우는 입력으로 주어지지 않는다.

출력
게임이 종료되는 턴의 번호를 출력한다.
그 값이 1,000보다 크거나 절대로 게임이 종료되지 않는 경우에는 -1을 출력한다.

제한
4 ≤ N ≤ 12
4 ≤ K ≤ 10

입력 예제
4 4
0 0 2 0
0 0 1 0
0 0 1 2
0 2 0 0
2 1 1
3 2 3
2 2 1
4 1 2

*) 출력
1) 시나리오 테스트

    cout << "b:"<<kLst[1][1]<<","<<kLst[1][2];
    move0(1,kLst[1][1],kLst[1][2]);
    showVis();
    cout << "b:"<<kLst[2][1]<<","<<kLst[2][2];
    move2(2,kLst[2][1],kLst[2][2]);
    showVis();
    cout << "b:"<<kLst[3][1]<<","<<kLst[3][2];
    move2(3,kLst[3][1],kLst[3][2]);
    showVis();
    2턴
     for(int i=1;i<=k;i++){
        int b=nextMove(i);
        cout << "b:"<<b;
        showVis();
        if(b==0){move0(i,kLst[i][1],kLst[i][2]);}
        else if(b==1){move1(i,kLst[i][1],kLst[i][2]);}
        else if(b==2){move2(i,kLst[i][1],kLst[i][2]);}
        showVis();
    }
    
    showVis();
    move0(1,2,1);
    showVis();
    move0(2,3,2);
    showVis();
    move1(3,2,2);
    showVis();
    move2(4,4,1);
    showVis();

*/