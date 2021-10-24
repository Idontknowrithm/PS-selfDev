// end를 K로 놓는 것은 트릭. N*N으로 놓는 것이 이론적으로 맞으나, 
// K번째 수는 경험적으로 K보다 작으므로, 또 N*N은 10^10이 될 수 있으나
// K는 10^9까지이므로 int의 제한에 걸리지 않음

#include<iostream>
#include<algorithm>

int N, K;

int BS(){
    int start = 1, end = K;
    while(start <= end){
        int lower = 0, mid = (start + end) / 2;
        for(int i = 1; i <= N; ++i){
            lower += std::min(N, mid / i);
        }
        if(lower < K)
            start = mid + 1;
        else 
            end = mid - 1;
    }
    return start;
}

int main() {
    scanf("%d\n%d", &N, &K);
    printf("%d", BS());
    return 0;
}
