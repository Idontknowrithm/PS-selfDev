#include<iostream>
#include<algorithm>

int main (){
    long long ans, arr[100000];
    int N, max = 0, tempMax = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lld", &arr[i]);
    std::sort(arr, arr + N);
    ans = arr[N - 1];
    for(int i = 1; i < N; ++i){
        if(arr[i] != arr[i - 1]){
            ans = (max < tempMax) ? arr[i - 1] : ans;
            max = (max < tempMax) ? tempMax : max;
            tempMax = 1;
            continue;
        }
        ++tempMax;
    }
    ans = (max < tempMax) ? arr[N - 1] : ans;
    printf("%lld", ans);
    return 0;
}
