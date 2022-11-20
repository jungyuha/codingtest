/*
[4179 수도코드]
4 7
#######
#J....#
#..F..#
#.....#

0. 문제의 취지
- 병훈이의 최단 거리가 불의 최단거리보다 빠르면 되는 거임
- 이 수도코드는 불이 처음부터 여러개가 입력되면 틀리는 수도코드임

1. vector<vector<char>> mp1
mp1[0] : #######
mp1[1] : #J....#
mp1[2] : #..F..#
mp1[3] : #.....#

mp1 {# # # # # # # # J . . . . # # . . F . . # # . . . . . #

int min_;
//func(1,1,0,2,3)

<main>
//(1순회1) {상 우(선) 하 좌} => J의 시작 위치에서 상하좌우 이동 -> int nx, ny(이동한 새로운 위치) , fx,fy(불의 현재 위치)
	if 새로운 위치가 벽일 때(#) || 새로운 위치에 불이 있을 때(F) 
		continue
	mp1[cy][cx] ='.';
	func1(ny,nx,0,fy,fx);

<func1> => int cy , cx (j의 시작위치) , s(탈출거리) , fx,fy(불의 현재 위치)
//s ++;(탈출거리 ++)
if  현재 위치가 벽(#)이 아니면서 && 가장 자리일 때
	탈출 거리 기록 , 탈출 거리 최소값 계산(min_>s)
//    s--;
	return;(stop)
// mp1[cy][cx]='J';
(2순회1) {상(선) 우 하 좌} => 불의 상하좌우 이동 -> int nfx, nfy(이동한 불의 새로운 위치)
    nfy = fy + dy , nfx = fx + dx
	if 불의 위치 범위가 초과될 때 || 불의 새로운 위치가 벽일 때(#) || 불의 새로운 위치에 불이 있을 때(F) || 불의 새로운 위치에 J가 있을 때(J)
		continue
	mp1[nfy][nfx]='F'; // 불 옮겨붙음
		(2순회2) {상 우(선) 하 좌} => J의 현재 위치에서 상하좌우 이동 -> int nx, ny(이동한 새로운 위치)
			nx = cx + dx , ny = cy = dy
			if 위치 범위가 초과될 때 || 새로운 위치가 벽일 때(#) || 새로운 위치에 불이 있을 때(F)
				continue
			mp1[cy][cx]='.';
			mp1[ny][nx]='J';
			func1(ny,nx,s+1,nfy,nfx);
			mp1[cy][cx]='J';
			mp1[ny][nx]='.';
	mp1[nfy][nfx]='.'; // 불 다시 원복

*/

/* 디버깅 코드

1. mp1 순회
    cout << "1 : \n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << mp1[i][j];
        }
        cout << "\n";
    }
2. if문
if(s == 1){
	cout << "1 : \n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << mp1[i][j];
        }
        cout << "\n";
    }
}
*/


