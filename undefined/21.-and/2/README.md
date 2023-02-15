# (2) 펜윅트리

## 펜윅 트리

### 1. 펜윅 트리 모양



<figure><img src="../../../.gitbook/assets/image (4) (3).png" alt=""><figcaption></figcaption></figure>

#### 펜윅트리의 Node Index 모양&#x20;

![](<../../../.gitbook/assets/image (2) (3).png>)

![](<../../../.gitbook/assets/image (3) (1).png>)

* **하나의 노드가 나타내는 값 중 알수 있는 정보는, 그노드가 나타내는 범위의**\
  **last index** 이다.
* 펜윅 트리의 노드의 값은 자기자신을 수도 있고, 범위 값일 수도 있다.
* 범위값의 시작점을 알기 힘들다.

### 2. 펜윅트리란 ?

1. 부분 범위 확장시 **불필요한 정보를 제외한 형태로** **확장**되는 모습을 가진다.
   * 세그먼트 트리의 경우 Node가 전체 Item에 대한 범위가, 2진 형태의 부분 범위로 확장되는 모습을 가진다.&#x20;
2. 구간의 정보를 업데이트하고 빠르게 가져오기 위해 사용한다.
3. **이진 트리**로 구성되어 있다.
4. 값이 아닌 **구간**의 정보를 가지는 트리이다.
5. 트리를 바이너리 인덱스 형태로 만들어서 풀이한다.
6. **트리의 크기**는 결국 **요소 (Item)의 크기(갯수)와 동일**하다.
7. 세그먼트 트리의 우측 구간 - 즉 1/2 씩 공간을 줄인다.
8. 업데이트나, 값 구하기 모두 시간복잡도는 O(LogN)이다.

### 3. 펜윅트리의 필요성

* 세그먼트 트리의 메모리를 절약하기 위함이다.

### 4. 펜윅 트리와 세그먼트 트리와의 차이점

세그먼트 트리가 다음과 같다고 가정하자

<figure><img src="../../../.gitbook/assets/image (5) (2).png" alt=""><figcaption></figcaption></figure>

1. **값의 소유 여부**&#x20;
   * 세그먼트 트리는 \[0, 7]의 값과, \[0, 3],\[4, 7]의 값을 모두 알고 있다.
   * 펜윅 트리는 \[0, 7]의 값과, \[0, 3]의 값만을 가진다.
     * \[0, 7]의 값 - \[0, 3]을 하면, \[4, 7]의 값을 알 수 있기에 굳이 \[4, 7]의 값을 유지할 필요가 없기 때문이다.
2. **노드 유지 형태**
   1. 펜윅트리는 **세그먼트 트리상의 우측 노드들을 유지 하지 않는 형태를 가진다.**
   2. 펜윅 트리는 **곧바로 어떤 구간에 대한 값을 곧바로 가져오지는 못한다**.
      * 세그먼트 트리와 달리, **불필요한 정보을 제외**하고 있기때문이다.
3. **getValue(L, R) 형태의 값 구하기 : 구간합**
   * 세그먼트 트리에서는 바로 구할 수 있다.
   * 펜윅 트리에서는 \[1 , R] - \[1 , L] + L 형태로 계산해서 구해야한다.
     1. getValue(L)형태로 값을 먼저 구한다.이는 1 \~ L, 즉 세그먼트 트리의 getValue(1, L) 형태와 같다.
     2. getValue(R)형태로 값을 먼저 구한다.이는 1 \~ R, 즉 세그먼트 트리의 getValue(1, R) 형태와 같다.
     3. getValue(1,R) - getValue(1, L)+ L 로 계산한다.
4. **ID 부여 순서**
   * 세그먼트 트리는 루트부터 Left, Right노드를 만들며 Node에 ID을 순서대로\
     **붙여간다.(동적) ->** Level순회 형태로 ID를 부여한다.ㅋ
   * **펜윅 트리는, 1부터 \~ N까지 (트리의 크기는 요소의 크기와 동일) 트리 순서대로**\
     **ID가 고정된다.**
5.  **노드 확장 형태**

    1. 세그먼트 트리는 루트(ID=1)(0 \~ N)범위, 루트의 L자식(ID=2)(0 \~ N/2), 루트의 R자식(ID=3)(N/2 \~ N) 형태로 확장된다.
    2. 펜윅 트리는 1(1), 2(1 \~ 2), 3(3), 4(1 \~ 4), ..., 12(9 \~ 12), ... 와 같은 형태이다.
       1. 1(1), 3(3)과 같은 노드는 범위가 아니다.
       2. 2(1 \~ 2), 4(1 \~ 4)과 같은 노드는 1부터 시작하는 범위이다.
       3. 12(9 \~ 12)는 중간부터 시작되는 노드이다.
    3. 펜윅 트리는  바이너리 형태로 불필요 정보(세그먼트 트리상의 우측 자식 정보)을 제외하고 정보를 저장하고 있기 때문에 노드의 형태가 제각각이다.



### 5. 코드

#### 펜윅트리 업데이트

```cpp
int mp[1000000];
int n ; // 배열의 길이

void update_tree(int index,int value){
    while(index<=n){
        tree[index]+=value;
        index = index + (index&-index);
    }
}
```

#### 펜윅트리 생성

```cpp
int mp[1000000];
int n ; // 배열의 길이

void make_penwickTree(){
    for(int i =1;i<=n;i++){
        update_tree(i,mp[i]);
    }
}
```

#### 펜윅트리 누적합 구하기

```cpp
int mp[1000000];
int n ; // 배열의 길이

int make_sum(int index){
    int sum = 0;
    while(index >= 1){
        sum += tree[index];
        index = index - (index&-index);
    }
    return sum ;
}
```