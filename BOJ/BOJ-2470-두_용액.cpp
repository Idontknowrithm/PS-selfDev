차의 MAX값을 10억으로 했는데, 가능한 MAX 값은 20억(1,999,999,999)
이므로, 초기값 설정을 잘못함

#include<iostream>
#include<algorithm>

int N, sol[100005];

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &sol[i]);
    
    std::sort(sol, sol + N);
    int start = 0, end = N - 1;
    int cur_diff = 2000000005, acid, alkali;
    while(start < end){
        if(std::abs(sol[end] + sol[start]) < cur_diff){
            acid = sol[end];
            alkali = sol[start];
            cur_diff = std::abs(sol[end] + sol[start]);
        }
        if(sol[end] + sol[start] > 0)
            --end;
        else 
            ++start;
    }
    printf("%d %d", alkali, acid);
    return 0;
}
