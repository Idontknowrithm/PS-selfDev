#include<iostream>
#include<algorithm>
#include<cstring>

int N, cache[55], arr[55];

int DP(int idx){
    if(idx == N) return 0;

    int &ret = cache[idx];
    if(ret != -1) return ret;

    ret = -2147483648;

    if(idx < N - 1)
        ret = std::max(ret, DP(idx + 2) + arr[idx] * arr[idx + 1]);
    ret = std::max(ret, DP(idx + 1) + arr[idx]);

    return ret;
}

int main() {
    memset(cache, -1, sizeof(cache));
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%d", &arr[i]);
    std::sort(arr, arr + N);

    printf("%d", DP(0));

    return 0;
}
