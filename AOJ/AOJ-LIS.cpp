// 일단 문제가 생기면 천천히, 합리적인 오류 포인트를 잡기 위해 노력하기
// DP 함수 첫 스타트 시 첫 번째 원소만 탐색하는 오류 발생

#include<iostream>
#include<algorithm>

int T, N, seq[505], cache[505];

int lis(int start){
    int &ret = cache[start];
    if(ret != 0) return ret;

    ret = 1;
    for(int i = start + 1; i < N; ++i){
        if(seq[i] > seq[start])
            ret = std::max(ret, lis(i) + 1);
    }
    return ret;
}

int main() {
    for(scanf("%d", &T); T > 0; --T){
        scanf("%d", &N);
        for(int i = 0; i < N; ++i){
            scanf("%d", &seq[i]);
            cache[i] = 0;
        }
        int temp = 0;
        for(int i = 0; i < N; ++i)
            temp = std::max(temp, lis(i));
        printf("%d\n", temp);
    }
    return 0;
}
