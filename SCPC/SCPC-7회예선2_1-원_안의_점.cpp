일단 원이니까 계산의 용이성을 위해서 4분원 하나만 계산해서 4배 하여 답을
구하기로 했고, O(N^2)로는 안되니까 적절히 어림 잡은 뒤에 답을 구하려고
했는데 그 알고리즘의 하나로 double 자료형과 floor, round 같은 cmath 함수를
사용하려고 했는데 자료형의 뒤섞임으로 인한 계산 오류로 버림.
  다음으로는 이분탐색으로 어림값을 구한 뒤 계산하는 방법 생각
-> 자료형 뒤섞일 일 없이 깔끔한 O(NlogN) 가능

#include<iostream>
#include<cmath>
#define ll long long

ll T, R, ans;

ll BS(ll val){
    ll mid, sq_mid, l = 0, r = 200005;

    while(l < r){
        mid = (l + r) / 2;
        sq_mid = mid * mid;
        if(sq_mid <= val)
            l = mid + 1;
        else 
            r = mid - 1;
    }
    return r;
}

int main() {
    scanf("%lld", &T);
    for(ll z = 1; z <= T; ++z){
        scanf("%lld", &R);

        ans = R - 1;
        for(ll i = 1; i < R; ++i){
            ll sq_tmp_ans, sq_R = R * R, sq_i = i * i;
            ll tmp_ans = BS(sq_R - sq_i) + 6;

            sq_tmp_ans = tmp_ans * tmp_ans;
            while(sq_tmp_ans >= sq_R - sq_i){
                --tmp_ans;
                sq_tmp_ans = tmp_ans * tmp_ans;
            }
            
            ans += tmp_ans;
        }

        ans = (ans << 2) + 1;
        printf("Case #%lld\n%lld\n", z, ans);
    }
    return 0;
}
