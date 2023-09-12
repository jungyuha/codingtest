# \[6] 이분탐색,LIS 솔루션

#### (E) 6-E:1269 대칭 차집합

{% embed url="http://boj.kr/1a4dbe0e0cb2415997acff8fc37819bc" %}

* 무식하게 풀기 시간 복잡도 : 200000x200000 = 40000000000 (400억)
* <mark style="background-color:green;">**문제 분류 1 : 카운팅**</mark>
  * ![](<../.gitbook/assets/image (102).png>)
  * 카운팅했을 때 1인 것들만 따로 모으면 된다.
* <mark style="background-color:blue;">**문제 핵심 1 : map 사용**</mark>
  * <mark style="background-color:blue;">**map에 입력을 받고 map을 순회한다.**</mark>
    * ![](<../.gitbook/assets/image (103).png>)

#### (F) _6 - F : 16434_ 드래곤 앤 던전

{% embed url="http://boj.kr/1700a29f60304c88bf47ac4928ec080c" %}

#### (G) 6-G:1072 게임

{% embed url="http://boj.kr/2d466352283f4b9ba1e5e0c2864a8ed8" %}

#### (H) 6-H:2776

{% embed url="http://boj.kr/6a21a43f74594cf08963ad0de77ec89a" %}

<mark style="background-color:green;">**풀이 : 이분탐색**</mark>

![](<../.gitbook/assets/image (6) (1) (1) (1).png>)

#### (I) 6-I:14627

{% embed url="http://boj.kr/1a34f4d0948243deac6d6915bcf1c8e0" %}

<mark style="background-color:green;">**풀이 : 이분탐색**</mark>

![](<../.gitbook/assets/image (7) (1) (1) (1).png>)

#### _(3) 6 - J : 1561 놀이공원_&#x20;

{% embed url="http://boj.kr/c2fb354cd24049edb34fbd09a91a38d3" %}

* <mark style="background-color:green;">**문제 분류 : 이분탐색**</mark>
  * <mark style="background-color:green;">**특정 시간이 mid일 때 n명 이상을 태울 수 있는지 확인**</mark>
  * <mark style="background-color:green;">**덩어리를 만드는 문제**</mark>
* 최대 600억 ( 놀이기구 1개만 있고 30분 \* 최대 인원수 20억명 )
* 순차적으로 하나하나 탐색하는 문제가 아님
*   한번에 7명을 태울수 있음 => 만약 30명 정도 있으면 4\~5덩어리 정도 있겠지 -> <mark style="background-color:red;">**이 덩어리를 먼저 계산**</mark>해버린다.

    (_**8–H:17297**에도 먼저 계산해버리는 누적 자르기 문제_)

    * ![](<../.gitbook/assets/image (27).png>)
    * mid 이분 탐색

#### (4) _6 - K : 14003_ 가장 긴 증가하는 부분 수열 5

* <mark style="background-color:green;">**문제 분류 : RIS + 역추적**</mark>

{% embed url="http://boj.kr/b4a30d5a7f404a25bf3097a45808b5e2" %}

* ![](<../.gitbook/assets/image (40).png>)
* LIS&#x20;
  * ![](<../.gitbook/assets/image (37).png>)
  * ![](<../.gitbook/assets/image (38).png>)
* 역추적 (스택사용)
  * ![](<../.gitbook/assets/image (39).png>)

#### (5) _6 - L : 2670_ 연속부분최대곱

{% embed url="http://boj.kr/d34cb3945f0a46f9ae3ba22377cff4d7" %}

* <mark style="background-color:green;">**문제 분류 : 그리디**</mark>
* S 지점과 E 지점을 찾아 범위를 정해야한다.
* 무식하게 푸는 방법 : n개 중에 e와 s를 무작위로 고른다.(조합)-> 시간복잡도 : n^3
* 증명이 어렵구 감이 안잡히넹.. -> <mark style="background-color:green;">**그리디**</mark> (로직을 나눠서 타당한지 확인)
  *   **현재 상태(a\[i])에서 다음 상태(a\[i+1])를 곱할 때 그 값이 (a\[i])\*a\[i+1])) 다음 상태(a\[i+1])보다**

      **작다면 GG -> 그 다음부터 곱할 애들은 모두 동일하기 때문 !**
  * **그 값이 (a\[i])\*a\[i+1])) 현재 상태(a\[i])보다 조금 더 작아지더라도 다음 상태(a\[i+1])보다 크다면 뒤에 어떤수가 나올지 모르니 가능성이 있는것이다.**
  * ![](<../.gitbook/assets/image (7) (1) (1).png>)
* 로직을 나눠서 하나씩 증명해보기 (곱했을 때 커지면 유지 , 작아지면 새롭게)
  * **1) 0.5 , 1 ,  2**
    * 0.5 -> 0.5 -> 1
    * ![](<../.gitbook/assets/image (3) (1) (1) (1) (1).png>)
      * 2를 곱하는 순간 2보다 더 작아진다. 그러므로 2부터 다시 시작
  * **2) 100 , 0.5 , 8**
    * 100 -> 20(>0.5) -> 160
      * ![](<../.gitbook/assets/image (6) (1) (1).png>)
        * 20이 0.5보다는 크니까 버리지 않는다. (0.5곱했다고 애가 0.5보다는 작아지지 않으니)
  * **3) 100 , 0.5 , 1 , 1 , 2**
    * 100 -> 20 -> 20 -> 20 -> 40
      * ![](<../.gitbook/assets/image (5) (1) (1).png>)

#### _(6) 6 - M : 11053_ 가장 긴 증가하는 부분 수열

{% embed url="http://boj.kr/703ee460495f48309c0e24b4f4c86e30" %}

* <mark style="background-color:green;">**문제 분류 :  LIS**</mark>

#### (7) _6 - N : 14002_ 가장 긴 증가하는 부분 수열 4

{% embed url="http://boj.kr/17f8476941034cfa9eb8d55b964690bb" %}

* <mark style="background-color:green;">**문제 분류 1 : LIS trace ->Prev 배열 활용**</mark>
  * ![](<../.gitbook/assets/image (70).png>)

#### (6) 6-O:2565 전깃줄

{% embed url="http://boj.kr/781fd29992c444638a46b118a95b81d9" %}

* <mark style="background-color:green;">**문제 분류 1: LIS**</mark>
  * <mark style="background-color:green;">**pair(쌍)으로 주어지는 데이터로 무언가를 할 때 둘 중에 하나를 잡아서 sort를 해본다.**</mark>
    * ![](<../.gitbook/assets/image (83).png>)
