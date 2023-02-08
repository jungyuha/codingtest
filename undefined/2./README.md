# 2. 재귀함수

## \[1] 특징

* 매개변수에 Index를 넣고 자기 함수를 재참조한다. 이 때 index는 참조할 때마다 바뀐다.
* 기저사례 + 메인로직 으로 구성된다.

## \[2] 코드(외우기)

```cpp
int list[11] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
vector<int> choose; // 선택한 원소를 보관

void Combination(int index, int level) {
    if(level == 5) {
        // 선택한 5개의 원소를 처리
        return;
    }

    // for문
    for(int i=index; i<=10; i++) {
        choose.push_back(list[i]); // i 번째 원소를 선택(추가)
        Combination(i+1, level+1); // 다음 for 문으로 들어가는 역할
        choose.pop_back(); // 넣었던 i 번째 원소를 제거
    }
}
```
