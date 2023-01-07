/*
*) 입력
게임 횟수 : X
이긴 게임 : Y (Z%)
Z는 형택이의 승률이고, 소수점은 버린다. 예를 들어, X=53, Y=47이라면, Z=88이다.
X와 Y가 주어졌을 때, 형택이가 게임을 최소 몇 번 더 해야 Z가 변하는지 구하는 프로그램을 작성하시오.

1 ≤ X ≤ 1,000,000,000
0 ≤ Y ≤ X

*) 메모리
int s,e,mid,res=987654321;
double x,y,z;
bool yn = false;

*) 시나리오
s = 1 ; e = x; z = (y/x)*100;

while(s<=e):
    mid = (s+e)/2;
    int m_z = (y+mid/x+mid)*100;
    if(m_z > z) :
        res = min(res,mid);
        yn = true;
        e = mid -1;
    else if (m_z == z) :
        s = mid + 1;
if(!yn) res = -1;

(res 출력)

*) 출력
(1) cout << "s : " << s << ",e : " << e << ", z : " << z  <<endl;
(2) cout << "s : " << s << ",e : " << e << ", mid : " << mid << ", m_z : " << m_z <<endl;
(3) cout << "m_res : " << res <<endl;
*/