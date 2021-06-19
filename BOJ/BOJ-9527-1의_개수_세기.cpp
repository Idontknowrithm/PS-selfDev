#include<iostream>
#define ll long long

ll A, B, ans;

ll sum(ll g){
    ll idx = 1, ans = 0, tmp = ++g;
    while(tmp){
        if(g & idx)
            ans += (g % idx) + (g - g % (idx << 1)) / 2;
        else
            ans += (g - g % idx) / 2;
        
        tmp >>= 1;
        idx <<= 1;
    }
    return ans;
}

int main() {
    scanf("%lld %lld", &A, &B);
    ans = sum(B) - sum(A - 1);
    printf("%lld", ans);
    return 0;
}
