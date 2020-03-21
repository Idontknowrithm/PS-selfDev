// normal wrong

#include<iostream>
#include<cstdlib>

int compare(const void* a, const void* b){
    return *(long long*)a < *(long long*)b;
}

int main (){
    long long N, ans, arr[100000], max = 0, tempMax = 1;
    scanf("%lld", &N);
    for(int i = 0; i < N; ++i)
        scanf("%lld", &arr[i]);
    qsort(arr, N, sizeof(long long), compare);
    ans = arr[0];
    for(long long i = 1; i < N; ++i){
        if(arr[i] != arr[i - 1]){
            ans = (max < tempMax) ? arr[i - 1] : ans;
            max = (max < tempMax) ? tempMax : max;
            tempMax = 1;
            continue;
        }
        ++tempMax;
    }
    printf("%lld", ans);
    return 0;
}
