#include<iostream>
#include<math.h>
#include<algorithm>

int arr[200];

int main(){
    long long w, h, n;
    int T;
    for(scanf("%d", &T); T > 0; --T){
        scanf("%lld %lld %lld", &w, &h, &n);
        long long widsap = 0, heisap = 0;
        while(w % 2 == 0){
            w /= 2; ++widsap;
        }
        while(h % 2 == 0){
            h /= 2; ++heisap;
        }
        long long tot = 1;
        for(int i = 0; i < widsap; ++i)
            tot *= 2;
        for(int i = 0; i < heisap; ++i)
            tot *= 2;
        if(tot >= n)
            printf("YES\n");
        else 
            printf("NO\n");
    }
    return 0;
}
