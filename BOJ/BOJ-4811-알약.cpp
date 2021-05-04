#include<iostream>
#include<algorithm>
#include<cstring>
#define ll long long

ll N, cache[35][35];

ll pill(ll whole, ll half){
    if((whole == 1 && !half) || !whole) return 1;

    ll &ret = cache[whole][half];
    if(ret) return ret;

    if(!half)
        ret = pill(whole - 1, half + 1);
    else
        ret = pill(whole - 1, half + 1) + pill(whole, half - 1);
    return ret;
}

int main(){
    while(1){
        scanf("%lld", &N);
        if(!N) return 0;

        memset(cache, 0, sizeof(cache));
        printf("%lld\n", pill(N, 0));
    }
}
